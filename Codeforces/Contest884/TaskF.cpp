#include "bits/stdc++.h"

using namespace std;
#define int long long

const int oo = 1e18;
struct Edge {
	int x, y, c, w, f;
	Edge() {}
	Edge(int _u, int _v, int _c, int _w, int _f) : x(_u), y(_v), c(_c), w(_w), f(_f) {}
};

struct MincostFlow {
	int n, totCost, totFlow, s, t;
	vector <Edge> EdgeList;
	vector <vector <int>> adj;
	vector <int> dist, inq, trace;
	queue <int> q;
	MincostFlow() {}
	MincostFlow(int _n) {
		this -> n = _n;
		EdgeList.clear();
		adj.assign(n + 5, vector <int>(0, 0));
	}

	void addEdge(int u, int v, int c, int w) {
		adj[u].push_back((int)EdgeList.size());
		EdgeList.push_back(Edge(u, v, c, w, 0));
		adj[v].push_back((int)EdgeList.size());
		EdgeList.push_back(Edge(v, u, 0, -w, 0));
	}

	bool FordBellman(int s, int t) {
		inq.assign(n + 5, 0); trace.assign(n + 5, -1);
		dist.assign(n + 5, oo);
		while (!q.empty()) q.pop();
		q.push(s);
		inq[s] = true;
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
						inq[v] = true;
					}
				}
			}
		}
		return (dist[t] != oo);
	}

	void solve() {
		totFlow = 0; totCost = 0;
		while (FordBellman(s, t)) {
			int delta = oo;
			for (int i = t; i != s; i = EdgeList[trace[i]].x) {
				Edge e = EdgeList[trace[i]];
				delta = min(delta, e.c - e.f);
			}
			for (int i = t; i != s; i = EdgeList[trace[i]].x) {
				EdgeList[trace[i]].f += delta;
				EdgeList[trace[i] ^ 1].f -= delta;
			}
			totFlow += delta;
			totCost += delta * dist[t];
		}
	}
};

const int N = 105;
int cnt[30], b[N], n;
string s;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.inp", "r", stdin);
	freopen("TaskF.out", "w", stdout);

	cin >> n >> s;
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	MincostFlow Solver(n / 2 + 28);
	Solver.s = 1, Solver.t = 2;
	int p = 2;
	for (int i = 0; i < n; ++i) cnt[s[i] - 'a' + 1]++;
	for (int i = 1; i <= 26; ++i) {
		Solver.addEdge(Solver.s, p + i, cnt[i], 0);
	}
	p += 26;
	for (int i = 1; i <= 26; ++i) {
		for (int j = 1; j <= n / 2; ++j) {
			int l = s[j - 1] - 'a' + 1, r = s[n - j] - 'a' + 1;
			if (l == r && l == i) {
				Solver.addEdge(i + 2, p + j, 1, -max(b[j], b[n - j + 1]));
			} else if (l == i) {
				Solver.addEdge(i + 2, p + j, 1, -b[j]);
			} else if (r == i) {
				Solver.addEdge(i + 2, p + j, 1, -b[n - j + 1]);
			} else Solver.addEdge(i + 2, p + j, 1, 0);
		}
	}
	for (int j = 1; j <= n / 2; ++j) Solver.addEdge(p + j, Solver.t, 2, 0);
	Solver.solve();
	cout << -Solver.totCost << endl;

	return 0;
}