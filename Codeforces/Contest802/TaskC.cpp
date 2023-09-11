#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e16;
struct Edge {
	int x, y, c, w, f;
	Edge() {}
	Edge(int _x, int _y, int _c, int _w, int _f) : x(_x), y(_y), c(_c), w(_w), f(_f) {}
};

struct MincostFlow {
	int n, totCost, totFlow, s, t;
	vector <vector <int>> adj;
	vector <int> inq, dist, trace;
	vector <Edge> EdgeList;
	queue <int> q;

	MincostFlow() {}
	MincostFlow(int _n) {
		this -> n = _n;
		adj.assign(n + 5, vector <int>(0, 0));
		EdgeList.clear();
	}

	void addEdge(int u, int v, int c, int w) {
		adj[u].push_back((int)EdgeList.size());
		EdgeList.push_back(Edge(u, v, c, w, 0));
		adj[v].push_back((int)EdgeList.size());
		EdgeList.push_back(Edge(v, u, 0, -w, 0));
	}

	bool FordBellman(int s, int t) {
		inq.assign(n + 5, false); dist.assign(n + 5, oo);
		trace.assign(n + 5, -1);
		while (!q.empty()) q.pop();
		q.push(s); inq[s] = true;
		dist[s] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			inq[u] = false;
			for (int id : adj[u]) {
				Edge e = EdgeList[id];
				if (e.c == e.f) continue;
				int v = e.y;
				if (dist[v] > dist[u] + e.w) {
					trace[v] = id;
					dist[v] = dist[u] + e.w;
					if (!inq[v]) {
						q.push(v);
						inq[v] = 1;
					}
				}
			}
		}
		return (dist[t] != oo);
	}

	void solve() {
		totCost = totFlow = 0;
		while (FordBellman(s, t)) {
			int delta = oo;
			for (int u = t; u != s; u = EdgeList[trace[u]].x) {
				Edge e = EdgeList[trace[u]];
				delta = min(delta, e.c - e.f);
			}
			for (int u = t; u != s; u = EdgeList[trace[u]].x) {
				EdgeList[trace[u]].f += delta;
				EdgeList[trace[u] ^ 1].f -= delta;
			}
			totFlow += delta;
			totCost += dist[t] * delta;
		}
	}
};

const int N = 105;
int a[N], c[N], cnt[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	freopen("TaskC.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int distinct = 0;
	for (int i = 1; i <= n; ++i) if (cnt[i]) distinct++;
	k = min(k, distinct);
	for (int i = 1; i <= n; ++i) cin >> c[i];
	MincostFlow Solver(2 * n + 3);
	int s = 2 * n + 1; Solver.s = 2 * n + 2; Solver.t = Solver.s + 1;
	Solver.addEdge(Solver.s, s, k, 0);
	for (int i = 1; i <= n; ++i) {
		Solver.addEdge(2 * i - 1, 2 * i, 1, -oo);
		Solver.addEdge(s, 2 * i - 1, 1, c[a[i]]);
		Solver.addEdge(2 * i, Solver.t, 1, 0);
		for (int j = i + 1; j <= n; ++j) if (a[i] == a[j]) {
			Solver.addEdge(2 * i, 2 * j - 1, 1, 0);
		} else Solver.addEdge(2 * i, 2 * j - 1, 1, c[a[j]]);
	}
	Solver.solve();
	cout << Solver.totCost + n * oo << endl;

	return 0;
}