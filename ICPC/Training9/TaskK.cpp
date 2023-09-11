#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 55, MOD = 1e9 + 7;
int n, p[N], dp[N][N];
string s;

void solve() {
	cin >> s;
	n = s.size();
	s = ' ' + s;
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i - 1] + s[i] - '0';
	}
	memset(dp, 0, sizeof dp);
	dp[0][n + 1] = 1;
	for (int i = 0; i <= n; ++i) {
		for (int j = n + 1; j >= 1; --j) if (dp[i][j] != 0) {
			for (int x1 = i + 1; x1 <= n; ++x1) {
				for (int x2 = j - 1; x2 > x1; --x2) {
					int s1 = p[x1] - p[i], s2 = p[j - 1] - p[x2 - 1];
					if (s1 == s2) {
						dp[x1][x2] += dp[i][j];
						dp[x1][x2] %= MOD;
					}
				}
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) if (dp[i][j]) {
			res = (res + dp[i][j]) % MOD;
		}
	}
	cout << res + 1 << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskK.INP", "r", stdin);
	freopen("TaskK.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}