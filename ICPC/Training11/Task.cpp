#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 505, MOD = 998244353;
int dp[N][N], n, x, C[2 * N][2 * N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	cin >> n >> x;
	memset(dp[0], 1, sizeof dp[0]);
	C[0][0] = 1;
	for (int i = 1; i < 2 * N; ++i) {
		for (int j = 0; j <= i; ++j) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= x; ++j) {
			for (int k = i; k >= 1; --k) {
				int numDied = i - k + 1, upb = min(j, i - 1);
				if (upb == 0) {
					continue;
				}
				// range of the last numDied elements is [1 -> min(j, n - 1)]
				int curWays = C[numDied][numDied + upb - 1];
				(dp[i][j] += dp[k - 1][j - upb] * curWays % MOD) %= MOD;
			}
		}
	}
	int res = dp[n][x];
	for (int i = 1; i <= n; ++i) {
		res = res * i % MOD;
	}
	cout << res << endl;

	return 0;
}