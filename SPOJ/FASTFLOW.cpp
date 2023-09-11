#include <bits/stdc++.h>

using namespace std;
#define int long long

struct Edge {
	int x, y, c, f;
	Edge() {}
	Edge(int _x, int _y, int _c, int _f) : x(_x), y(_y), c(_c), f(_f) {}
};

struct MaxFlow {
	int n, s, t, maxFlow;
	queue <int> ex_vertex;
	vector <int> seen, h, cnt, excess;
	vector <vector <int>> adj;
	vector <Edge> EdgeList;

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
		adj[u].push_back((int)EdgeList.size());
		EdgeList.push_back(Edge(u, v, c, 0));
		adj[v].push_back((int)EdgeList.size());
		EdgeList.push_back(Edge(v, u, 0, 0));
	}

	void Push(int id) {
		Edge e =  EdgeList[id];
		int delta = min(excess[e.x], e.c - e.f);
		EdgeList[id].f += delta;
		EdgeList[id ^ 1].f -= delta;
		excess[e.x] -= delta;
		excess[e.y] += delta;
	}

	void setH(int u, int d) {
		cnt[h[u]]--;
		h[u] = d;
		cnt[d]++;
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
			for (int v = 1; v <= n; ++v) if (v != s && h[v] <= n && oldH < h[v]) {
				setH(v, n + 1);
				seen[v] = 0;
			}
		}
	}

	void solve2() {
		for (int i = 1; i <= n; ++i) h[i] = 1;
		h[t] = 0; h[s] = n;
		cnt[0] = cnt[n] = 1, cnt[1] = n - 2;
		for (int id : adj[s]) {
			int f = EdgeList[id].c;
			EdgeList[id].f += f;
			EdgeList[id ^ 1].f -= f;
			excess[s] -= f;
			excess[EdgeList[id].y] += f;
		}
		for (int i = 1; i <= n; ++i) if (i != s && i != t && excess[i] > 0)
			ex_vertex.push(i);
		while (!ex_vertex.empty()) {
			int z = ex_vertex.front();
			ex_vertex.pop();
			while (seen[z] < adj[z].size()) {
				Edge e = EdgeList[adj[z][seen[z]]];
				if (e.c > e.f && h[e.x] > h[e.y]) {
					bool needQ = (excess[e.y] == 0 && e.y != t && e.y != s);
					Push(adj[z][seen[z]]);
					if (needQ) ex_vertex.push(e.y);
					if (excess[z] == 0) break;
				}
				seen[z]++;
			}
			if (excess[z] > 0) {
				seen[z] = 0;
				Lift(z);
				ex_vertex.push(z);
			}
		}
		maxFlow = excess[t];
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("FASTFLOW.INP", "r", stdin);
	freopen("FASTFLOW.OUT", "w", stdout);

	int n, m;
	cin >> n >> m;
	MaxFlow Solver(n);
	Solver.s = 1, Solver.t = n;
	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		Solver.addEdge(u, v, c);
		Solver.addEdge(v, u, c);
	}
	Solver.solve2();
	cout << Solver.maxFlow << endl;

	return 0;
}