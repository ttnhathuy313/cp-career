#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 105;
int path[N][N][N], n, m, MOD, dp[N][N][N][2];
vector <int> adj[N];

void solve(int s, int t) {
	for (int i = 2; i <= 55; ++i) {
		for (int cur = 0; cur < 2; ++cur) {
			dp[s][t][i][cur] = path[s][cur ? t : s][i - 1];
			bool ok = (s == 3 && t == 2 && i == 3 && cur == 0);
			for (int j = 2; j < i; ++j) {
				for (int lst = 0; lst < 2; ++lst) {
					dp[s][t][i][cur] = dp[s][t][i][cur] - dp[s][t][j][lst] * path[lst ? t : s][cur ? t : s][i - j] + MOD * MOD;
					dp[s][t][i][cur] %= MOD;
				}
			}
 		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("MESSENGER.INP", "r", stdin);
	freopen("MESSENGER.OUT", "w", stdout);

	cin >> n >> m >> MOD;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i) {
		path[i][i][0] = 1;
	}
	for (int len = 0; len <= 55; ++len) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int k : adj[j]) {
					(path[i][k][len + 1] += path[i][j][len]) %= MOD;
				}
			}
		}
	}
	for (int s = 1; s <= n; ++s) {
		for (int t = 1; t <= n; ++t) if (s != t)
			solve(s, t);
	}
	int q;
	cin >> q;
	while (q--) {
		int u, v, d;
		cin >> u >> v >> d;
		int res = path[u][v][d];
		for (int i = 2; i <= d; ++i) {
			for (int lst = 0; lst < 2; ++lst) {
				res = (res - dp[u][v][i][lst] * path[lst ? v : u][v][d + 1 - i] + MOD * MOD) % MOD;
			}
		}
		cout << res << endl;
	}

	return 0;
}