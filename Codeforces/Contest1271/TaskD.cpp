#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int inf = 1e14;

struct Edge {
	Edge() {x = y = c = f = w = 0;}
	Edge(int _x, int _y, int _c, int _f, int _w) : x(_x), y(_y), c(_c), f(_f), w(_w) {}
	int x, y, c, f, w;
};

struct MinCostMaxFlow {
	int n, m, idm = 0, s, t;
	int totCost, totFlow, oo = (int)1e18;
	vector <Edge> EdgeList;
	vector <int> dist;
	vector <vector <int>> adj;
	vector <int> trace;
 
	MinCostMaxFlow() {
		n = 0;
	}
 
	MinCostMaxFlow(int n) {
		this -> n = n;
		adj.assign(n + 5, vector <int> (0, 0));
		EdgeList.clear();
		dist = vector <int> (n + 5);
		trace = vector <int> (n + 5);
	}
 
 
	void addEdge(int u, int v, int c, int w) {
		adj[u].push_back(EdgeList.size());
		EdgeList.push_back(Edge(u, v, c, 0, w));
		adj[v].push_back(EdgeList.size());
		EdgeList.push_back(Edge(v, u, 0, 0, -w));
	}
 
	bool FordBellman(int s, int t) {
		for (int i = 1; i <= n; ++i) dist[i] = oo, trace[i] = -1;
		vector <bool> inq = vector <bool> (n + 5, false);
		queue <int> q;
		q.push(s); inq[s] = true; dist[s] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop(); inq[u] = false;
			for (int id : adj[u]) if (EdgeList[id].c > EdgeList[id].f) {
				int v = EdgeList[id].y;
				if (dist[v] > dist[u] + EdgeList[id].w) {
					dist[v] = dist[u] + EdgeList[id].w;
					trace[v] = id;
					if (!inq[v]) {
						q.push(v);
						inq[v] = true;
					}
				}
			}
		}
		return (dist[t] < oo);
	}
	
	void solve() {
		totFlow = totCost = 0;
		while (FordBellman(s, t)) {
			int delta = oo;
			for (int u = t; u != s; u = EdgeList[trace[u]].x) 
				delta = min(delta, EdgeList[trace[u]].c - EdgeList[trace[u]].f);
			for (int u = t; u != s; u = EdgeList[trace[u]].x) {
				EdgeList[trace[u]].f += delta;
				EdgeList[trace[u] ^ 1].f -= delta;
			}
			totCost += delta * dist[t];
			totFlow += delta;
		}
	}
 
} Solver;

const int N = 5e3 + 5;
int n, m, k, a[N], b[N], c[N], bal[N], B[N], dp[N], f[N];
vector <int> adj[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m >> k;
	int s1 = 0, s2 = k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
		s1 += a[i];
		s2 += b[i];
	}
	B[0] = k;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = B[i - 1] - a[i];
        if(dp[i] < 0)
        {
            cout << "-1";
            exit(0);
        }
        B[i] = B[i - 1] + b[i];
        cerr << "dp[" << i << "] : " << dp[i] << endl;
    }
    f[n + 1] = oo;
    dp[n + 1] = b[n];
    for (int i = n; i >= 1; --i) {
    	f[i] = min(dp[i + 1], f[i + 1]);
    }
	if (a[1] > k) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	Solver = MinCostMaxFlow(2 * n + 3);
	int s = 3 * n + 1; Solver.t = 3 * n + 2;
	Solver.s = 3 * n + 3;
	Solver.addEdge(Solver.s, s, s2, 0);
	for (int i = 1; i <= n; ++i) {
		Solver.addEdge(i, i + 1, a[i + 1], -inf);
		Solver.addEdge(i, i + 1, (int)1e9, 0);
	}
	for (int i = 1; i <= n; ++i) {
		for (int v : adj[i]) {
			Solver.addEdge(i + n, v + n, 1, 0);
		}
		Solver.addEdge(i, i + n, dp[i], 0);
		Solver.addEdge(i + n, i + 2 * n, 1, 0);
		Solver.addEdge(i + 2 * n, Solver.t, 1, -c[i]);
	}
	Solver.addEdge(s, 1, a[1], -inf);
	Solver.addEdge(s, 1, s2 - a[1], 0);
	Solver.addEdge(n, Solver.t, (int)1e9, 0);
	Solver.solve();
	cerr << Solver.totCost << endl;
	if (Solver.totCost > -s1 * inf) {
		cout << -1 << endl;
	} else {
		cout << -(Solver.totCost) - s1 * inf << endl;
	}

	return 0;
}