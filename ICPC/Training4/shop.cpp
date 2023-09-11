#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 505;
int dp[N][N], n, a[N], cnt;

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			dp[i][j] = -(int)1e9;
	}

	dp[1][0] = 0;
	dp[1][1] = a[1];
	int res = 0;
	if (n == 1) res = a[1];
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) if (j <= i / 2) {
			dp[i][j] = dp[i - 1][j];
			if (j != 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i]);
			if (i == n) {
				res = max(res, dp[i][j]);
			}
		}
	}
	cout << "Spree #" << (++cnt) << ": " << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("shop.INP", "r", stdin);
	freopen("shop.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}