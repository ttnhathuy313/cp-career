#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 105, oo = 1e9 + 5;
int n, dp[N][N], trace[N][N], m;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("FLOYD.INP", "r", stdin);
	freopen("FLOYD.OUT", "w", stdout);

	cin >> n >> m;
	int q;
	cin >> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) dp[i][i] = 0;
			else dp[i][j] = oo;
		}
	}
	memset(trace, -1, sizeof trace);
	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		dp[u][v] = c;
		dp[v][u] = c;
		trace[u][v] = v;
		trace[v][u] = u;
	}
	for (int k = 1; k <= n; ++k) {
		for (int u = 1; u <= n; ++u) {
			for (int v = 1; v <= n; ++v) {
				if (dp[u][v] > dp[u][k] + dp[k][v]) {
					trace[u][v] = trace[u][k];
					dp[u][v] = dp[u][k] + dp[k][v];
				}
			}
		}
	}
	while (q--) {
		int type, u, v;
		cin >> type >> u >> v;
		if (type == 0) {
			cout << dp[u][v] << endl;
		} else {
			int t = u;
			vector <int> V; V.clear();
			while (t != v) {
				V.push_back(t);
				t = trace[t][v];
			}
			V.push_back(v);
			cout << V.size() << ' ';
			for (int d : V) cout << d << ' '; cout << endl;
		}
	}

	return 0;
}