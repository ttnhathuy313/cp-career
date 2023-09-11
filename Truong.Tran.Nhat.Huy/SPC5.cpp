#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 55, MOD = 1e9 + 7;
int dp[N][N][N], n;

void solve() {
	string s;
	cin >> s;
	n = s.size();
	s = ' ' + s;
	memset(dp, 0, sizeof dp);
	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int open = 0; open <= i; ++open) {
			for (int close = 0; close <= open; ++close) {
				int cur = dp[i][open][close];
				if (cur == 0) continue;
				int nxt = (s[i + 1] == 'T' ? 1 : 0);
				if (nxt) {
					(dp[i + 1][open + 1][close] += cur) %= MOD;
					if (close) (dp[i + 1][open - 1][close - 1] += cur * close) %= MOD;
				} else {
					(dp[i + 1][open][close + 1] += cur * (open - close)) %= MOD;
					(dp[i + 1][open][close] += cur * close) %= MOD;
				}
			}
		}
	}
	cout << dp[n][0][0] << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("SPC5.INP", "r", stdin);
	freopen("SPC5.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}