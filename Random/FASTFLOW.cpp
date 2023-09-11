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
	vector <int> h, cnt, excess, seen;
	vector <vector <int>> adj;
	vector <Edge> EdgeList;
	queue <int> ex_vertex;
	MaxFlow() {}
	MaxFlow(int _n) {
		this -> n = _n;
		h.assign(n + 5, 0);
		cnt.assign(2 * n + 5, 0);
		excess.assign(n + 5, 0);
		seen.assign(n + 5, 0);
		adj.assign(n + 5, vector <int>(0, 0));
		EdgeList.clear();
		while (!ex_vertex.empty())
			ex_vertex.pop();
		maxFlow = 0;
	}
	void addEdge(int u, int v, int c) {
		adj[u].push_back((int)EdgeList.size());
		EdgeList.push_back(Edge(u, v, c, 0));
		adj[v].push_back((int)EdgeList.size());
		EdgeList.push_back(Edge(v, u, 0, 0));
	}

	void Push(int id) {
		Edge e = EdgeList[id];
		int delta = min(e.c - e.f, excess[e.x]);
		EdgeList[id].f += delta;
		EdgeList[id ^ 1].f -= delta;
		excess[e.x] -= delta;
		excess[e.y] += delta;
	}

	void setH(int u, int d) {
		cnt[h[u]]--;
		h[u] = d;
		cnt[h[u]]++;
	}

	void Lift(int u) {
		int minH = 2 * n + 10;
		for (int i : adj[u]) {
			Edge e = EdgeList[i];
			if (e.c == e.f) continue;
			minH = min(minH, h[e.y]);
		}
		int oldH = h[u];
		setH(u, minH + 1);
		if (oldH > 0 && oldH < n && cnt[oldH] == 0) {
			for (int v = 1; v <= n; ++v) if (h[v] > 0 && h[v] < n && oldH < h[v]) {
				setH(v, n + 1);
				seen[v] = 0;
			}
		}
	}

	void solve() {
		for (int i = 1; i <= n; ++i) h[i] = 1;
		h[s] = n, h[t] = 0; cnt[1] = n - 2; cnt[n] = cnt[0] = 1;
		for (int i : adj[s]) {
			Edge &e = EdgeList[i];
			int f = e.c - e.f;
			excess[e.y] += f;
			excess[e.x] -= f;
			EdgeList[i].f += f;
			EdgeList[i ^ 1].f -= f;
		}
		for (int i = 1; i <= n; ++i) if (i != s && i != t && excess[i] > 0) {
			ex_vertex.push(i);
		}
		while (!ex_vertex.empty()) {
			int z = ex_vertex.front(); ex_vertex.pop();
			while (seen[z] < adj[z].size()) {
				Edge e = EdgeList[adj[z][seen[z]]];
				if (e.c != e.f && h[e.x] > h[e.y]) {
					bool needPush = (e.y != s && e.y != t && excess[e.y] == 0);
					Push(adj[z][seen[z]]);
					if (needPush) ex_vertex.push(e.y);
				}
				if (excess[z] == 0) break;
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
};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("FASTFLOW.INP", "r", stdin);
	freopen("FASTFLOW.OUT", "w", stdout);

	int n, m;
	cin >> n >> m;
	MaxFlow Solver = MaxFlow(n);
	Solver.s = 1, Solver.t = n;
	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		Solver.addEdge(u, v, c);
		Solver.addEdge(v, u , c);
	}
	Solver.solve();
	cout << Solver.maxFlow << endl;

	return 0;
}