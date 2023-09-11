#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 505, MOD = 1e9 + 7;
int n, dp[N][N], m;
bool okay[N][N];
string s, t;

/*
	dp[i][j]: The number of j-element sets of 
	operations to satisfy the substring [i..n]

	okay[i][j] = 1 if t doesn't appear in s[i..j]
*/

int calc(int i, int j) {
	if (i > n) {
		return 1;
	}
	if (j == 0) {
		if (!okay[i][n]) {
			return 0;
		}
	}
	if (okay[i][n]) {
		if (j == 0) {
			return 1;
		} else return 0;
	}
	if (~dp[i][j]) {
		return dp[i][j];
	}
	int res = 0;
	for (int k = i; k <= n - m + 1; ++k) {
		if (okay[k][k + m - 1] == 0 && okay[i][k - 1]) {
			res = (res + calc(k + m, j - 1)) % MOD;
		}
	}
	return dp[i][j] = res;
}

void solve() {
	memset(okay, 0, sizeof okay);
	memset(dp, -1, sizeof dp);
	cin >> s >> t;
	n = s.size();
	m = t.size();
	s = ' ' + s;

	for (int i = 1; i <= n; ++i) {
		okay[i][i - 1] = 1;
		for (int j = i; j <= n; ++j) {
			okay[i][j] = okay[i][j - 1];
			if (j - m + 1 >= i && s.substr(j - m + 1, m) == t) {
				okay[i][j] = 0;
			}
		}
	}

	for (int len = 0; len <= n; ++len) if (calc(1, len) > 0) {
		int fac = 1;
		for (int i = 1; i <= len; ++i) {
			fac = fac * i % MOD;
		}
		cout << len << ' ' << (calc(1, len) % MOD) << endl;
		return;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}