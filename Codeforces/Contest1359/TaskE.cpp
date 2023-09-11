#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 998244353, N = 5e5 + 5;
int n, k, fac[N];

int modPow(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = ret * x % MOD;
		y >>= 1;
		x = x * x % MOD;
	}
	return ret;
}

int inv(int a) {
	a %= MOD;
	return (modPow(a, MOD - 2));
}

void mult(int &a, int b) {
	a = a * b % MOD;
}

int C(int k, int n) {
	if (k > n) return 0;
	int ret = fac[n];
	mult(ret, inv(fac[n - k] * fac[k]));
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> k;
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		int tot = n / i;
		ret = (ret + C(k - 1, tot - 1)) % MOD;
	}
	cout << ret << endl;

	return 0;
}