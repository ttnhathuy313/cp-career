#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5005, MOD = 1e9 + 7;
int dp[N][N];

int modPow(int x, int y) {
	x %= MOD;
	int res = 1;
	while (y) {
		if (y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int n, k;
	cin >> n >> k;
	dp[0][0] = 1;
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= i; ++j) if (j <= n) {
			dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1] * (n - j + 1)) % MOD;
		}
	}
	int res = 0;
	for (int i = 1; i <= k; ++i) if (i <= n) {
		res += dp[k][i] * modPow(2, n - i);
		res %= MOD;
	}
	cout << res << endl;

	return 0;
}