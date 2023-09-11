#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;

struct Edge {
	Edge() {x = y = c = f = 0;}
	Edge(int _x, int _y, int _c, int _f) : x(_x), y(_y), c(_c), f(_f) {}
	int x, y, c, f;
};

struct MaxFlow {
	int n, m, s, t, maxFlow;
	vector <int> excess, cnt, seen, h;
	vector <vector <int>> adj;
	vector <Edge> EdgeList;
	queue <int> ex_vertex;

	MaxFlow() {}
	MaxFlow(int n) {
		this -> n = n;
		excess.assign(n + 5, 0);
		cnt.assign(2 * n + 10, 0);
		seen.assign(n + 5, 0);
		h.assign(n + 5, 0);
		adj.assign(n + 5, vector <int> (0, 0));
		EdgeList.clear();
		while (!ex_vertex.empty()) ex_vertex.pop();
		maxFlow = -0;
	}

	void addEdge(int u, int v, int c) {
		adj[u].push_back(1LL * EdgeList.size());
		EdgeList.push_back(Edge(u, v, c, 0));
		adj[v].push_back(1LL * EdgeList.size());
		EdgeList.push_back(Edge(v, u, 0, 0));
	}

	void push(int index) {
		int Delta = min(EdgeList[index].c - EdgeList[index].f, excess[EdgeList[index].x]);
		EdgeList[index].f += Delta;
		EdgeList[index ^ 1].f -= Delta;
		excess[EdgeList[index].x] -= Delta;
		excess[EdgeList[index].y] += Delta;
	}
	 
	void setH(int u, int newH) {
		cnt[h[u]]--;
		h[u] = newH;
		cnt[newH]++;
	}
	 
	void Lift(int u) {
		int minH = 2 * n + 10;
		for (int index : adj[u]) if (EdgeList[index].c > EdgeList[index].f) {
			minH = min(minH, h[EdgeList[index].y]);
		}
		int OldH = h[u];
		setH(u, minH + 1);
		if (OldH > 0 && OldH < n && cnt[OldH] == 0) {
			for (int v = 1; v <= n; ++v) if (v != s && OldH < h[v] && h[v] <= n) {
				setH(v, n + 1);
				seen[v] = 0;
			}
		}
	}

	void init() {
		for (int i = 1; i <= n; ++i) h[i] = 1;
		h[s] = n; h[t] = 0;
		cnt[n] = 1; cnt[0] = 1; cnt[1] = n - 2;
		for (int id : adj[s]) {
			int sf = EdgeList[id].c;
			EdgeList[id].f += sf;
			EdgeList[id ^ 1].f = -sf;
			excess[EdgeList[id].y] += sf;
			excess[s] -= sf;
		}
		for (int i = 1; i <= n; ++i) if (i != s && i != t && excess[i] > 0) {
			ex_vertex.push(i);
		}
	}
	 
	void Push_Relabel_GapHeuristic() {
		init();
		while (!ex_vertex.empty()) {
			int z = ex_vertex.front();
			ex_vertex.pop();
			while (seen[z] < adj[z].size()) {
				Edge e = EdgeList[adj[z][seen[z]]];
				if (e.c > e.f && h[e.x] > h[e.y]) {
					bool NeedQueue = (e.y != s && e.y != t && excess[e.y] == 0);
					push(adj[z][seen[z]]);
					if (NeedQueue) ex_vertex.push(e.y);
					if (excess[z] == 0) break;
				}
				seen[z]++;
			}
			if (excess[z] > 0) {
				Lift(z);
				seen[z] = 0;
				ex_vertex.push(z);
			}
		}
		maxFlow = excess[t];
	}
} Solver;

const int N = 105;
int m, n, l[N][N], r[N][N], c_in[N], c_out[N], h[N], w[N], ans[N][N];
int row[N], col[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("DIENSO.INP", "r", stdin);
	freopen("DIENSO.OUT", "w", stdout);

	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> l[i][j];
			c_in[j] += l[i][j];
			c_out[i] += l[i][j];
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> r[i][j];
		}
	}
	Solver = MaxFlow(n + m + 4);
	Solver.s = n + m + 1, Solver.t = Solver.s + 1;
	int s = n + m + 3, t = s + 1;
	for (int i = 1; i <= m; ++i) {
		Solver.addEdge(Solver.s, i, w[i]);
		Solver.addEdge(s, Solver.t, w[i]);
		Solver.addEdge(i, Solver.t, c_out[i]);
	}
	for (int i = 1; i <= n; ++i) {
		Solver.addEdge(Solver.s, t, h[i]);
		Solver.addEdge(m + i, Solver.t, h[i]);
		Solver.addEdge(Solver.s, m + i, c_in[i]);
	}
	Solver.addEdge(t, s, oo);
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			Solver.addEdge(i, m + j, r[i][j] - l[i][j]);
		}
	}
	Solver.Push_Relabel_GapHeuristic();
	for (Edge e : Solver.EdgeList) {
		if (e.x <= m && e.y > m && e.y <= n + m) {
			ans[e.x][e.y - m] = e.f + l[e.x][e.y - m];
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << ans[i][j] << ' ';
			row[i] += ans[i][j];
			col[j] += ans[i][j];
			if (ans[i][j] < l[i][j] || ans[i][j] > r[i][j]) {
				// cerr << "WRONG";
				return 0;
			}
		}
		cout << endl;
	}
	// for (int i = 1; i <= m; ++i) if (row[i] != w[i]) {
	// 	cout << "WRONG";
	// 	return 0;
	// }
	// for (int i = 1; i <= n; ++i) if (col[i] != h[i]) {
	// 	cout << "WRONG";
	// 	return 0;
	// }
	cout << "CORRECT";

	return 0;
}