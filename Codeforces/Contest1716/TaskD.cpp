#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, MOD = 998244353;
int n, k, dp[N][2], res[N];


void solve() {
	cin >> n >> k;
	int mx = 2 * (int)sqrt(n);
	dp[0][0] = 1;
	for (int j = 1; j <= mx; ++j) {
		if (k * j + j * (j - 1) / 2 >= n)
			break
		int id = j & 1;
		for (int i = 1; i <= n; ++i) if (i >= k + j - 1) {
			dp[i][id] = (dp[i - k - j + 1][id] + dp[i - k - j + 1][id ^ 1]) % MOD;
			res[i] = (res[i] + dp[i][id]) % MOD;
		}
		for (int i = 0; i <= n; ++i)
			dp[i][id ^ 1] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		cout << res[i] << ' ';
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	solve();

	return 0;
}