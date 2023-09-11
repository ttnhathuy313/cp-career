#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5005;
int n, dp[N][N], fac[N], MOD, invv[N];

int modPow(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return ret;
}

int inv(int x) {
	return modPow(x, MOD - 2);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> MOD;

	fac[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	int safe = n / 2;
	dp[1][1] = fac[n - 1];
	for (int i = 1; i <= n; ++i) {
		invv[i] = inv(i);
	}
	for (int tot = 2; tot <= n; ++tot) {
		int chia = invv[n - tot + 1];
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			dp[i][tot] = sum * chia % MOD;
			sum += dp[i][tot - 1];
			sum %= MOD;
			if (i - safe >= 1) {
				sum = (sum - dp[i - safe][tot - 1] + MOD) % MOD;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n + 1; ++i) if (i - 1 > safe) {
		int rem = n + 2 - i;
		int first_choice = 0;
		for (int j = 2; j < i; ++j) {
			if (j - 1 <= safe && i - j <= safe)
				first_choice++;
		}
		// what if rem = 1
		int temp = 0;
		for (int j = 2; j <= rem; ++j) {
			temp = (invv[n - j] * dp[rem][j] % MOD) * first_choice % MOD;
			res += temp;
			res %= MOD;
		}

		if (rem == 1) {
			res += fac[n - 2] * first_choice % MOD;
			res %= MOD;
		}
	}
	res = res * n % MOD;

	cout << res << endl;

	return 0;
}