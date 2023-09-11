#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 3605, MOD = 998244353;
int dp1[N][N / 2], dp2[N][N / 2], h, w, n, fac[N], dp[N][N];
bool markL[N], markR[N];

int modPow(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = res * x % MOD;
		y >>= 1;
		x = x * x % MOD;
	}
	return res;
}

int inv(int x) {
	x %= MOD;
	return modPow(x, MOD - 2);
}

int C(int k, int n) {
	if (n < 0) return 0;
	if (k > n) return 0;
	if (k < 0) return 0;
	return dp[n][k];
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	clock_t t = clock();
	fac[0] = 1;
	for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % MOD;
	dp[0][0] = 1;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			(dp[i][j] = dp[i - 1][j] + (j > 0 ? dp[i - 1][j - 1] : 0)) %= MOD;
		}
	}
	cin >> h >> w >> n;
	for (int i = 1; i <= n; ++i) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		markL[r1] = markL[r2] = markR[c1] = markR[c2] = 1;
	}
	dp1[0][0] = 1;
	for (int i = 1; i <= h; ++i) {
		for (int j = 0; j <= h / 2; ++j) {
			dp1[i][j] = dp1[i - 1][j];
			if (!markL[i] && !markL[i - 1] && i > 1 && j > 0) dp1[i][j] += dp1[i - 2][j - 1];
			dp1[i][j] %= MOD;
		}
	}
	dp2[0][0] = 1;
	for (int i = 1; i <= w; ++i) {
		for (int j = 0; j <= w / 2; ++j) {
			dp2[i][j] = dp2[i - 1][j];
			if (!markR[i] && !markR[i - 1] && i > 1 && j > 0) dp2[i][j] += dp2[i - 2][j - 1];
			dp2[i][j] %= MOD;
		}
	}
	int l, r; l = r = 0;
	for (int i = 1; i <= h; ++i) if (!markL[i]) l++;
	for (int i = 1; i <= w; ++i) if (!markR[i]) r++;
	int res = 0;
	for (int i = 0; i <= w / 2; ++i) {
		for (int j = 0; j <= r - i * 2; ++j) {
			int R = dp2[w][i] * C(j, r - i * 2) % MOD;
			int L = dp1[h][j] * C(i, l - 2 * j) % MOD;
			int d = fac[j] * fac[i] % MOD;
			res += (R * L % MOD) * d % MOD;
			res %= MOD;
		}
	}
	cout << res << endl;

	return 0;
}