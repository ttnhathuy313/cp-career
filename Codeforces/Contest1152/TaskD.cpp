#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1005, MOD = 1e9 + 7;
int dp[N][N][2], n;

void add(int &a, int b) {
	a = (a + b) % MOD;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n;
	dp[n][n][0] = 0, dp[n][n][1] = 0;
	for (int tot = 2 * n - 1; tot >= 0; --tot) {
		for (int open = 0; open <= min(tot, n); ++open) {
			int close = tot - open;
			if (close > open) continue;
			add(dp[open][close][0], dp[open + 1][close][1] + dp[open][close + 1][1]);
			if (open == n) {
				add(dp[open][close][1], dp[open][close + 1][0] + 1);
				continue;
			} else if (close == open) {
				add(dp[open][close][1], dp[open + 1][close][0] + 1);
				continue;
			}
			add(dp[open][close][1], dp[open + 1][close][0] + dp[open][close + 1][1] + 1);
		}
	}
	cout << dp[0][0][0] << endl;

	return 0;
}