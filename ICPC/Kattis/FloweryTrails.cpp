#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5, oo = 1e18;
int n, m;
vector <int> d1, d2;
vector <ii> adj[N];

void dijkstra(int s, int t, vector <int> &d) {
	priority_queue <ii, vector <ii>, greater <ii>> pq;
	while (!pq.empty()) pq.pop();
	d.assign(n + 5, 0);
	for (int i = 1; i <= n; ++i) {
		d[i] = oo;
	}
	d[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		int u = pq.top().second, dd = pq.top().first;
		pq.pop();
		if (dd > d[u]) continue;
		for (ii ww : adj[u]) {
			int v = ww.first, w = ww.second;
			if (d[u] + w < d[v]) {
				d[v] = d[u] + w;
				pq.push({d[u] + w, v});
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("FloweryTrails.INP", "r", stdin);
	freopen("FloweryTrails.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		u++; v++;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	dijkstra(1, n, d1);
	dijkstra(n, 1, d2);

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (ii v : adj[i]) {
			int j = v.first, w = v.second;
			if (d1[i] + w + d2[j] == d1[n])
				res += w;
		}
	}
	cout << res * 2 << endl;

	return 0;
}