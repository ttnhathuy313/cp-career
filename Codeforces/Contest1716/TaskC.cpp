#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int m, a[2][N], dp[2][N];

void reset() {
	for (int i = 1; i <= m; ++i) {
		dp[0][i] = dp[1][i] = 0;
	}
}

void solve() {
	cin >> m;
	reset();
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int j = 1; j <= m; ++j) {
		if (j & 1) {
			if (j == 1) {
				dp[0][j] = 0;
			} else {
				dp[0][j] = max(a[0][j] + 1, dp[0][j - 1] + 1);
			}
			dp[1][j] = max(a[1][j] + 1, dp[0][j] + 1);
		} else {
			dp[1][j] = max(a[1][j] + 1, dp[1][j - 1] + 1);
			dp[0][j] = max(a[0][j] + 1, dp[1][j] + 1);
		}
	}
	cerr << dp[1][5] << endl;
	cout << dp[0][m] << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}