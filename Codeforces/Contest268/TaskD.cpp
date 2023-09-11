#include <bits/stdc++.h>

using namespace std;
#define int long long
#define forn(i, a, b) for (int i = a; i <= b; ++i)
#define rep(i, a) for (int i = 0; i < a; ++i)

const int N = 1005, H = 35, MOD = 1e9 + 9;
int dp[2][2][H][H][H], n, h;

void add(int &a, int b) {
	a = (a + b) % MOD;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> h;
	dp[1][1][1][1][1] = 4;
	forn(id, 1, n - 1) {
		int i = id & 1;
		memset(dp[i ^ 1], 0, sizeof dp[i ^ 1]);
		rep(a, 2) rep(b, h + 1) rep(c, h + 1) rep(d, h + 1) {
			int cur = dp[i][a][b][c][d];
			if (cur == 0) continue;
			add(dp[i ^ 1][a][min(b + 1, h)][min(c + 1, h)][min(d + 1, h)], cur);
			add(dp[i ^ 1][b < h][min(c + 1, h)][min(d + 1, h)][a == 1 ? 1 : h], cur);
			add(dp[i ^ 1][c < h][min(d + 1, h)][a == 1 ? 1 : h][min(b + 1, h)], cur);
			add(dp[i ^ 1][d < h][a == 1 ? 1 : h][min(b + 1, h)][min(c + 1, h)], cur);
		}
	}
	int res = 0;
	rep(a, 2) rep(b, h + 1) rep(c, h + 1) rep(d, h + 1) {
		if (a == 1 || b < h || c < h || d < h) add(res, dp[n & 1][a][b][c][d]);
	}

	cout << res << endl;

	return 0;
}