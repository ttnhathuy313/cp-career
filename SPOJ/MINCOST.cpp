#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 200, oo = 1e18;
int c[N][N], w[N][N], n, m, k, s, t;

struct Edge {
	int x, y, c, w, f;
	Edge() {}
	Edge(int _x, int _y, int _c, int _w, int _f) : x(_x), y(_y), c(_c), w(_w), f(_f) {}
};

vector <Edge> EdgeList;
vector <int> adj[N], trace;
int dist[N];

bool bmf(int s, int t) {
	vector <bool> inq(n + 5, false);
	trace.assign(n + 5, -1);
	for (int i = 1; i <= n; ++i) dist[i] = oo;
	dist[s] = 0;
	queue <int> q;
	while (!q.empty()) q.pop();
	q.push(s);
	inq[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int id : adj[u]) {
			Edge e = EdgeList[id];
			if (e.c == e.f) continue;
			if (dist[u] + e.w < dist[e.y]) {
				dist[e.y] = dist[u] + e.w;
				trace[e.y] = id;
				if (!inq[e.y]) {
					inq[e.y] = true;
					q.push(e.y);
				}
			}
		}
	}	
	return (dist[t] != oo);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("MINCOST.INP", "r", stdin);
	freopen("MINCOST.OUT", "w", stdout);

	cin >> n >> m >> k >> s >> t;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		cin >> w[u][v] >> c[u][v];
		w[v][u] = w[u][v];
		c[v][u] = c[u][v];
	}
	EdgeList.clear();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) if (c[i][j]) {
			adj[i].push_back((int)EdgeList.size());
			EdgeList.push_back(Edge(i, j, c[i][j], w[i][j], 0));
			adj[j].push_back((int)EdgeList.size());
			EdgeList.push_back(Edge(j, i, 0, -w[i][j], 0));
		}
	}

	int totFlow, totCost;
	totFlow = totCost = 0;
	while (bmf(s, t)) {
		int delta = oo;
		for (int id = trace[t]; id != -1; id = trace[EdgeList[id].x]) {
			delta = min(delta, EdgeList[id].c - EdgeList[id].f);
		}
		delta = min(delta, k);
		totFlow += delta;
		totCost += delta * dist[t];
		k -= delta;
		for (int id = trace[t]; id != -1; id = trace[EdgeList[id].x]) {
			EdgeList[id].f += delta;
			EdgeList[id ^ 1].f -= delta;
		}
		if (k == 0) break;
	}

	cout << totCost << endl;
	if (totCost == 0) return 0;
	for (Edge e : EdgeList) if (e.f > 0) {
		cout << e.x << ' ' << e.y << ' ' << e.f << endl;
	}
	cout << "0 0 0\n";
	return 0;
}
