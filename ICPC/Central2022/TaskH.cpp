#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, dist[N], m;
vector <int> adj[N];
vector <ii> adjj[N];
priority_queue <ii, vector <ii>, greater <ii>> pq;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskH.INP", "r", stdin);
	freopen("TaskH.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int t;
	cin >> t;
	while (t--) {
		int ti, u, v;
		cin >> ti >> u >> v;
		adjj[u].push_back({ti, v});
		adjj[v].push_back({ti, u});
	}
	for (int i = 1; i <= n; ++i) {
		dist[i] = (int)1e18;
	}
	pq.push({0, 1});
	dist[1] = 0;
	while (!pq.empty()) {
		ii d = pq.top();
		pq.pop();
		int u = d.second;
		if (d.first > dist[u]) {
			continue;
		}
		for (int v : adj[u]) {
			if (dist[u] + 1 < dist[v]) {
				dist[v] = dist[u] + 1;
				pq.push({dist[v], v});
			}
		}
		for (ii vv : adjj[u]) {
			int t = vv.first, v = vv.second;
			if (max(t - 1, dist[u]) + 1 < dist[v]) {
				dist[v] = max(t - 1, dist[u]) + 1;
				pq.push({dist[v], v});
			}
		}
	}
	if (dist[n] == (int)1e18) {
		cout << -1 << endl;
	} else cout << dist[n] << endl;

	return 0;
}