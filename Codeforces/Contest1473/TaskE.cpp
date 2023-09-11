#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, oo = 1e18;
int n, m, d[N][2][2];
vector <array<int, 2>> adj[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	priority_queue <array<int, 4>, vector<array<int,4>>, greater <array<int,4>>> pq;
	while (!pq.empty()) pq.pop();
	pq.push({0, 1, 0, 0});
	for (int i = 1; i <= n; ++i)
		d[i][0][0] = d[i][0][1] = d[i][1][1] = d[i][1][0] = oo;
	d[1][0][0] = 0;
	while (!pq.empty()) {
		array<int, 4> pack = pq.top(); pq.pop();
		if (pack[0] > d[pack[1]][pack[2]][pack[3]]) continue;
		for (auto V : adj[pack[1]]) {
			int w = V[1], v = V[0];
			for (int t = 3; t >= 1; --t) {
				if (t == 3 && !pack[t]) {
					if (pack[0] < d[v][pack[2]][1]) {
						d[v][pack[2]][1] = pack[0];
						pq.push({pack[0], v, pack[2], 1});
					}
				}
				if (t == 2 && !pack[t]) {
					if (pack[0] + 2 * w < d[v][1][pack[3]]) {
						d[v][1][pack[3]] = pack[0] + w * 2;
						pq.push({pack[0] + w * 2, v, 1, pack[3]});
					}
				}
				if (pack[0] + w < d[v][pack[2]][pack[3]]) {
					d[v][pack[2]][pack[3]] = pack[0] + w;
					pq.push({pack[0] + w, v, pack[2], pack[3]});
				}
			}
		}
	}
	for (auto j : adj[1]) {
		d[j[0]][1][1] = min(d[j[0]][1][1], j[1]);
	}
	for (int i = 2; i <= n; ++i) {
		cout << d[i][1][1] << " ";
	}

	return 0;
}