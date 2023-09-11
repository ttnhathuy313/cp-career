#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e9 + 7;

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
		for (int i = 1; i <= n; ++i) if (i != s && i != t && excess[i] > 0) ex_vertex.push(i);
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

const int N = 55;
int n, m, a[N][N], r, c, mark[N * N * 4];
int dx[] = {1, -1, 0, 0},
	dy[] = {0, 0, -1, 1};
char res[N][N];

int label(int x, int y, int z) {
	return (x - 1) * m + y + z * n * m;
}

void dfs(int s) {
	mark[s] = 1;
	for (int i : Solver.adj[s]) if (Solver.EdgeList[i].c != Solver.EdgeList[i].f) {
		if (!mark[Solver.EdgeList[i].y]) dfs(Solver.EdgeList[i].y);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m >> r >> c;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			res[i][j] = '.';
		}
	}

	Solver = MaxFlow(label(n, m, 1) + 2);
	Solver.s = label(n, m, 1) + 1;
	Solver.t = Solver.s + 1;

	Solver.addEdge(label(r, c, 1), Solver.t, oo);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i == 1 || i == n || j == 1 || j == m)
				Solver.addEdge(Solver.s, label(i, j, 0), oo);
			if (i == r && j == c) {
				Solver.addEdge(label(i, j, 0), label(i, j, 1), oo);
			} else {
				Solver.addEdge(label(i, j, 0), label(i, j, 1), a[i][j]);
			}
			for (int dir = 0; dir < 4; ++dir) {
				int x = i + dx[dir], y = j + dy[dir];
				if (x == 0 || x == n + 1 || y == 0 || y == m + 1) continue;
				Solver.addEdge(label(i, j, 1), label(x, y, 0), oo);
			}
		}
	}
	Solver.Push_Relabel_GapHeuristic();
	cout << Solver.maxFlow << endl;
	dfs(Solver.s);
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (mark[label(i, j, 0)] ^ mark[label(i, j, 1)]) {
				cout << 'X';
			} else cout << '.';
		}
		cout << endl;
	}

	return 0;
}