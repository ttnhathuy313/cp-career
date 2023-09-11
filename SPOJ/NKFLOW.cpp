#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;
struct Edge {
	int x, y, c, f;
	Edge() {}
	Edge(int _x, int _y, int _c, int _f) : x(_x), y(_y), c(_c), f(_f) {}
};

struct MaxFlow {
	int n, s, t, maxFlow;
	vector <int> excess, h, cnt, seen;
	vector <vector <int>> adj;
	vector <Edge> EdgeList;
	queue <int> ex_vertex;

	MaxFlow() {}
	MaxFlow(int _n) {
		this -> n = _n;
		maxFlow = 0;
		excess.assign(n + 5, 0);
		seen.assign(n + 5, 0);
		cnt.assign(2 * n + 5, 0);
		h.assign(n + 5, 0);
		adj.assign(n + 5, vector <int>(0, 0));
		EdgeList.clear();
		while (!ex_vertex.empty()) ex_vertex.pop();
	}

	void addEdge(int u, int v, int c) {
		adj[u].push_back((int)EdgeList.size());
		EdgeList.push_back(Edge(u, v, c, 0));
		adj[v].push_back((int)EdgeList.size());
		EdgeList.push_back(Edge(v, u, 0, 0));
	}

	void push(int id) {
		Edge e = EdgeList[id];
		int delta = min(e.c - e.f, excess[e.x]);
		EdgeList[id].f += delta;
		EdgeList[id ^ 1].f -= delta;
		excess[e.y] += delta;
		excess[e.x] -= delta;
	}

	void setH(int u, int H) {
		cnt[h[u]]--;
		h[u] = H;
		cnt[H]++;
	}

	void Lift(int u) {
		int minH = 2 * n + 10;
		for (int id : adj[u]) {
			Edge e = EdgeList[id];
			if (e.c == e.f) continue;
			minH = min(minH, h[e.y]);
		}
		int oldH = h[u];
		setH(u, minH + 1);
		if (oldH > 0 && oldH < n && cnt[oldH] == 0) {
			for (int v = 1; v <= n; ++v) if (v != s && h[v] <= n && h[v] > oldH) {
				setH(v, n + 1);
				seen[v] = 0;
			}
		}
	}

	void solve() {
		for (int i = 1; i <= n; ++i) h[i] = 1;
		h[s] = n; h[t] = 0;
		cnt[n] = cnt[0] = 1; cnt[1] = n - 2;
		for (int id : adj[s]) {
			Edge e = EdgeList[id];
			int sf = e.c;
			EdgeList[id].f += sf;
			EdgeList[id ^ 1].f -= sf;
			excess[e.y] += sf;
			excess[e.x] -= sf;
		}
		for (int i = 1; i <= n; ++i) if (i != s && i != t && excess[i] > 0) {
			ex_vertex.push(i);
		}
		while (!ex_vertex.empty()) {
			int z = ex_vertex.front(); ex_vertex.pop();
			while (seen[z] < adj[z].size()) {
				Edge e = EdgeList[adj[z][seen[z]]];
				if (e.c > e.f && h[e.x] > h[e.y]) {
					bool needQ = (e.y != s && e.y != t && excess[e.y] == 0);
					push(adj[z][seen[z]]);
					if (needQ) ex_vertex.push(e.y);
					if (excess[z] == 0) break;
				}
				seen[z]++;
			}
			if (excess[z] > 0) {
				ex_vertex.push(z);
				Lift(z);
				seen[z] = 0;
			}
		}
		maxFlow = excess[t];
	}
};


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("NKFLOW.INP", "r", stdin);
	freopen("NKFLOW.OUT", "w", stdout);

	int n, m, s, t;
	cin >> n >> m;
	s = 1; t = n;
	MaxFlow Solver(n);
	Solver.s = s, Solver.t = t;
	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		Solver.addEdge(u, v, c);
		Solver.addEdge(v, u, c);
	}
	Solver.solve();
	cout << Solver.maxFlow << endl;

	return 0;
}