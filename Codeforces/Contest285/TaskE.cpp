#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1005, MOD = 1e9 + 7;
int n, k, dp[N][N][6], res[N], fac[N], C[N][N];

void add(int &a, int b) {
	a = (a + b) % MOD;
}

void sub(int &a, int b) {
	b %= MOD;
	a = (a - b + MOD) % MOD;
}

void updateckn() {
	for (int k = 0; k < N; ++k)
		for (int n = 0; n < N; ++n) {
			if (k == 0 || k == n || n == 0) {
				C[k][n] = 1;
				continue;
			} else {
				C[k][n] = (C[k - 1][n - 1] + C[k][n - 1]) % MOD;
			}
		}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	updateckn();
	cin >> n >> k;
	if (n != 1) dp[1][1][2] = 1;
	dp[1][0][0] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			for (int mask = 0; mask < 4; ++mask) {
				int cur = dp[i][j][mask];
				add(dp[i + 1][j][mask >> 1], cur);
				if (!(mask & 1)) add(dp[i + 1][j + 1][mask >> 1], cur);
				if (i + 1 != n) add(dp[i + 1][j + 1][(mask >> 1) ^ 2], cur);
			}
		}
	}
	fac[0] = 1;
	for (int i = 1; i <= n; ++i)
		fac[i] = fac[i - 1] * i % MOD;
	for (int i = k; i <= n; ++i) {
		for (int j = 0; j < 4; ++j)
			add(res[i], dp[n][i][j]);
		res[i] = res[i] * fac[n - i] % MOD;
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 1; j <= n; ++j)
			sub(res[i], res[j] * C[i][j]);
	}
	cout << res[k] % MOD << endl;

	return 0;
}