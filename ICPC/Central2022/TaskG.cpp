#include <bits/stdc++.h>

using namespace std;
#define int long long 

const int N = 2e5 + 5, oo = 1e18;
int n, k, a[N], pref[N], dp[N][2];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			pref[i] = pref[i - 1] + a[i];
		}
		for (int i = 1; i <= n; ++i) {
			dp[i][0] = dp[i][1] = -oo;
		}
		dp[0][0] = dp[0][1] = 0;
		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j < 2; ++j) {
				dp[i][j] = dp[i - 1][j];
				if (i < k) {
					continue;
				}
				dp[i][j] = max(dp[i][j], dp[i - k][j ^ 1] + (pref[i] - pref[i - k]) * (j ? -1 : 1));
			}
		}
		int res = max(dp[n][0], dp[n][1]);
		cout << res << endl;
	}

	return 0;
}