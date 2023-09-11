#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 505;
int n, m, dp[N][N], choice[N][2], mn[N];
vector <int> a[N][N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		mn[i] = (int)1e9 + 7;
		for (int j = 1; j <= n; ++j) {
			a[i][j].clear();
			dp[i][j] = (int)1e9 + 7;
		}
	}
	vector <array<int, 3>> ed;
	ed.clear();
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		ed.push_back({u, v, w});
		mn[u] = min(mn[u], w);
		mn[v] = min(mn[v], w);
		dp[u][v] = dp[v][u] = 1;
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	int res = (int)1e18;
	for (int i = 1; i <= n; ++i) {
		res = min(res, mn[i] * (dp[i][1] + dp[1][n] + 1));
	}
	for (auto e : ed) {

		res = min(res, e[2] * (dp[e[0]][1] + dp[e[1]][n] + 1));
		res = min(res, e[2] * (dp[e[0]][n] + dp[e[1]][1] + 1));
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j] = (int)1e9 + 7;
		}
	}
	for (auto e : ed) {
		dp[e[0]][e[1]] = e[2];
		dp[e[1]][e[0]] = e[2];
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	cout << min(res, dp[1][n]) << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}