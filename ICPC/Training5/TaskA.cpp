#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, MOD = 998244353;
int n, a[N], dp[N], sdp[N], fac[N];

void mul(int &a, int b) {
	a = a * b % MOD;
}

int modPow(int x, int y) {
	x %= MOD;
	int res = 1;
	while (y) {
		if (y & 1) mul(res, x);
		mul(x, x);
		y >>= 1;
	}
	return res;
}

int inv(int x) {
	return modPow(x, MOD - 2);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		fac[0] = 1;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			fac[i] = i;
			mul(fac[i], fac[i - 1]);
		}
		dp[1] = a[1];
		sdp[1] = a[1];
		for (int i = 2; i <= n; ++i) {
			dp[i] = (sdp[i - 1] + dp[i - 1]) * a[i] % MOD;
			dp[i] = (dp[i] + i * dp[i - 1] - sdp[i - 1] + MOD) % MOD;
			dp[i] = (dp[i] + fac[i - 1] * a[i]) % MOD;
			sdp[i] = (sdp[i - 1] * a[i] % MOD + dp[i]) % MOD;
		}
		int res = dp[n];
		mul(res, inv(fac[n]));
		cerr << dp[n] << endl;
		cout << res << endl;
	}

	return 0;
}