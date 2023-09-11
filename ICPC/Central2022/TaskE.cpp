#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 105, MOD = 1e9 + 7;
int dp[N][N][15], n, a[N][N], r, c, pref[N][N], req[N];

int get(int i, int j, int x, int y) {
	return pref[x][y] - pref[x][j - 1] - pref[i - 1][y] + pref[i - 1][j - 1];
}

int calc(int i, int j, int turn) {

	if (turn == n + 1) {
		return 1;
	}
	if (turn == n) {
		if (get(i, j, r, c) <= req[turn]) {
			return 1;
		} else return 0;
	}
	if (~dp[i][j][turn]) {
		return dp[i][j][turn];
	}
	int ret = 0;
	for (int k = i + 1; k <= r; ++k) if (get(i, j, k - 1, c) <= req[turn]) {
		ret += calc(k, j, turn + 1);
		ret %= MOD;
	}

	for (int k = j + 1; k <= c; ++k) if (get(i, j, r, k - 1) <= req[turn]) {
		ret += calc(i, k, turn + 1);
		if (turn == 1) {
			cerr << k << ' ' << calc(i, k, turn + 1) << endl;
		}
		ret %= MOD;
	}
	return dp[i][j][turn] = ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> r >> c >> n;
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];		
		}
	}
	for (int i = 1; i <= n; ++i) {
		cin >> req[i];
	}
	cout << calc(1, 1, 1) << endl;

	return 0;
}