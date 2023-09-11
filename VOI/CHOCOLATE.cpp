#include <bits/stdc++.h>

using namespace std;
#define int long long

const int M = 1005, oo = 1e18;
int m, n, grid[M][15], dp[M][13][1 << 10];

void upd(int &a, int b) {
	a = min(a, b);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("CHOCOLATE.INP", "r", stdin);
	// freopen("CHOCOLATE.OUT", "w", stdout);

	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; ++j) {
			if (s[j - 1] == '.') grid[i][j] = 0;
			else grid[i][j] = 1;
			for (int msk = 0; msk < (1 << n); ++msk)
				dp[i][j][msk] = dp[0][j][msk] = oo;
		}
	}
	dp[0][n][0] = 0;
	int res = oo;
	for (int i = 0; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int mask = 0; mask < (1 << n); ++mask) if (dp[i][j][mask] < oo) {
				if (i == m && j == n) {
					res = min(res, dp[i][j][mask]);
					continue;
				}
				int cur = dp[i][j][mask];
				if (j == n) {
					if (!grid[i + 1][1]) upd(dp[i + 1][1][mask >> 1], cur);
					else {
						int nmask = mask >> 1;
						upd(dp[i + 1][1][nmask], cur + 1);
						upd(dp[i + 1][1][nmask + (1 << (n - 1))], cur + 1 - (mask & 1));
					}
					continue;
				}
				if (!grid[i][j + 1]) {
					upd(dp[i][j + 1][mask >> 1], cur);
				}
				else {
					int nmask = mask >> 1;
					upd(dp[i][j + 1][nmask], cur + 1 - (!(mask & (1 << (n - 1))) && grid[i][j]) );
					upd(dp[i][j + 1][nmask + (1 << (n - 1))], cur + 1 - (mask & 1));
				}
			}
		}
	}
	cout << res << endl;

	return 0;
}