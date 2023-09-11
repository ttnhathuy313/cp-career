#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 70, MOD = 998244353;
int fac[N], dp[N][2];

int modPow(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return ret;
}

int C(int k, int n) {
	int ret = fac[n];
	ret = ret * modPow(fac[k] * fac[n - k] % MOD, MOD - 2) % MOD;
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);

	fac[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
	}	
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		dp[0][0] = 1;
		dp[0][1] = 1;
		for (int i = 2; i <= n; i += 2) {
			dp[i][0] = C(i / 2 - 1, i - 1) + C(i / 2 - 1, i - 2) - dp[i - 2][1] - (i != 2 ? 1 : 0) + MOD;
			dp[i][0] %= MOD;
			dp[i][1] = C(i / 2 - 1, i - 1) + C(i / 2 - 1, i - 2) - dp[i - 2][0] - (i != 2 ? 1 : 0) + MOD;
			dp[i][1] %= MOD;
		}
		cout << dp[n][0] << ' ' << (C(n / 2, n) - dp[n][0] - 1 + MOD) % MOD << ' ' << 1 << endl;
	}

	return 0;
}