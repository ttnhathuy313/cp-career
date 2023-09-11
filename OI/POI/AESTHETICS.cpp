#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e3 + 5, oo = 1e18;
int dp[N][N], n, m, a[N], p[N], mi[N][N], mii[N][N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("AESTHETICS.INP", "r", stdin);
	freopen("AESTHETICS.OUT", "w", stdout);

	cin >> m >> n;
	m++;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i]++;
		p[i] = p[i - 1] + a[i];
		for (int j = 1; j <= n; ++j) {
			dp[i][j] = mi[i][j] = mii[i][j] = oo;
		}
	}
	int res = oo;
	for (int i = 1; i <= n; ++i) {
		if (p[i] <= m) {
			dp[i][1] = 0;
			mi[i][1] = p[i];
			mii[i][1] = -p[i];
		}
		for (int j = 2; j <= i; ++j) {
			int cursum = p[i] - p[j - 1];
			if (cursum > m) continue;
			int k = lower_bound(p + 1, p + 1 + n, p[j - 1] - cursum) - p;
			if (p[j - 1] > cursum) {
				dp[i][j] = min(dp[i][j], mi[j - 1][k] - cursum);
			} else k--;
			dp[i][j] = min(dp[i][j], mii[j - 1][k + 1] + cursum);
			if (i == n) res = min(res, dp[i][j]);
		}
		for (int j = 2; j <= i; ++j) {
			mi[i][j] = dp[i][j] + p[i] - p[j - 1];
			mii[i][j] = dp[i][j] - p[i] + p[j - 1];
			mi[i][j] = min(mi[i][j - 1], mi[i][j]);
		}
		for (int j = i - 1; j >= 1; --j) {
			mii[i][j] = min(mii[i][j], mii[i][j + 1]);
		}
	}
	res = min(res, dp[n][1]);
	cout << res << endl;

	return 0;
}