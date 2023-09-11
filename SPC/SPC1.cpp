#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2005, MOD = 1e9 + 7;
int n, dp[N][N], a[N], k, C[N][N], pw[N][N];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int res = 0;
	for (int i = 1; i <= min(k, n); ++i) {
		int temp = dp[n][i];
		for (int j = 1; j <= n; ++j) {
			temp = (temp * pw[k - i + 1][a[j]]) % MOD;
		}
		temp = (temp * C[k][i]) % MOD;
		res = (res + temp) % MOD;
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("SPC1.INP", "r", stdin);
	freopen("SPC1.OUT", "w", stdout);

	n = 1000;
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1] * j) % MOD;
		}
	}
	for (int i = 1; i <= n; ++i) {
		pw[i][0] = 1;
		for (int t = 1; t <= n; ++t) {
			pw[i][t] = pw[i][t - 1] * i % MOD;
		}
	}
	n *= 2;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == 0 || j == 0) {
				C[i][j] = 1;
				continue;
			}
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}

	int tc;
	cin >> tc;
	while(tc--) {
		solve();
	}

	return 0;
}