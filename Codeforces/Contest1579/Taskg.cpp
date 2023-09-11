#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e4 + 5, M = 2005, offset = 1000;
int n, dp[N][2005], a[N], pref[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			pref[i] = pref[i - 1] + a[i];
			for (int j = 0; j < M; ++j)
				dp[i][j] = (int)1e9 + 7;
		}
		for (int j = 0; j < M; ++j)
			dp[0][j] = (int)1e9 + 7;
		dp[0][offset] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < M; ++j) if (dp[i - 1][j] != -1) {
				int cur = j - offset;
				if (abs(cur - a[i]) < dp[i - 1][j] && j - a[i] >= 0) {
					dp[i][j - a[i]] = min(dp[i][j - a[i]], dp[i - 1][j]);
				}
				if (j + a[i] < M) dp[i][j + a[i]] = min(dp[i][j + a[i]], max(dp[i - 1][j], cur + a[i]));
			}
		}
		int res = (int)1e9 + 7;
		for (int j = 0; j < M; ++j)
			res = min(res, dp[n][j]);
		cout << res << endl;
	}

	return 0;
}