#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e5 + 5, MOD = 998244353;
int n, a[N], dp[N][2];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i <= n * 2; ++i) {
		dp[i][0] = dp[i][1] = 0;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i] - 1 >= 0) {
			(dp[a[i] - 1][1] += dp[a[i] - 1][0] + dp[a[i] - 1][1]) %= MOD;
		}
		(dp[a[i] + 1][0] += dp[a[i] + 1][0]) %= MOD;
		(dp[a[i] + 1][1] += dp[a[i] + 1][1]) % MOD;
		// (dp[a[i] + 2][0] += dp[a[i]][1]) %= MOD;
		(dp[a[i] + 1][0] += dp[a[i]][0]) %= MOD;
	}
	int res = -1;
	for (int i = 0; i <= n; ++i) {
		res = (res + dp[i][0] + dp[i][1] + MOD) % MOD;
		// cerr << i << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;
	}
	cout << res << endl;
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