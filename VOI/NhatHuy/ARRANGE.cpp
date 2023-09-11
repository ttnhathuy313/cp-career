#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2005, oo = 1e18;
int n, a[N], dp[N][N], high[N], low[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("ARRANGE.INP", "r", stdin);
	freopen("ARRANGE.OUT", "w", stdout);

	cin >> n;
	int s = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s += a[i];
	}
	int tot = s % n;
	s /= n;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > s) {
			high[i] = a[i] - s;
		} else low[i] = s - a[i];
	}
	for (int i = 1; i <= n; ++i) {
		high[i] += high[i - 1];
		low[i] += low[i - 1];
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = oo;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= n; ++j) if (dp[i][j] != oo) {
			int cur = dp[i][j], diff = high[i] - low[i] - j;
			if (diff >= 0) {
				if (a[i + 1] > s) {
					dp[i + 1][j] = min(dp[i + 1][j], cur + diff);
					dp[i + 1][j + 1] = min(dp[i + 1][j + 1], cur + diff);
				} else {
					dp[i + 1][j] = min(dp[i + 1][j], cur + diff + (diff >= s - a[i + 1] ? 0 : -(i + 1) * (s - a[i + 1] - diff)));
					dp[i + 1][j + 1] = min(dp[i + 1][j + 1], cur + diff + (diff >= s + 1 - a[i + 1] ? 0 : -(i + 1) * (s + 1 - a[i + 1] - diff)));
				}
			} else {
				diff = -diff;
				if (a[i + 1] > s) {
					dp[i + 1][j] = min(dp[i + 1][j], cur + min(diff, a[i + 1] - s) * (i + 1));
					dp[i + 1][j + 1] = min(dp[i + 1][j + 1], cur + min(diff, a[i + 1] - s - 1) * (i + 1));
				} else {
					dp[i + 1][j] = min(dp[i + 1][j], cur - (i + 1) * (s - a[i + 1]));
					dp[i + 1][j + 1] = min(dp[i + 1][j + 1], cur - (i + 1) * (s + 1 - a[i + 1]));
				}
			}
		}
	}
	cout << dp[n][tot] << endl;

	return 0;
}