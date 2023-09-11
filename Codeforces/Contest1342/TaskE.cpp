#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 998244353, N = 2e5 + 5;
int fac[4 * N];

void mult(int &a, int b) {
	a = a * b % MOD;
}

void add(int &a, int b) {
	a = (a + b) % MOD;
}

int modPow(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) mult(ret, x);
		mult(x, x);
		y >>= 1;
	}
	return ret;
}

int inv(int x) {
	x %= MOD;
	return modPow(x, MOD - 2);
}

int C(int k, int n) {
	int ret = fac[n];
	mult(ret, inv(fac[n - k] * fac[k]));
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int n, k;
	cin >> n >> k;
	if (n - k <= 0) {
		cout << 0 << endl;
		return 0;
	}
	fac[0] = 1;
	for (int i = 1; i < 4 * N; ++i) {
		fac[i] = fac[i - 1];
		mult(fac[i], i);
	}
	int res = 1;
	mult(res, C(n - k, n));
	int t = 0;
	for (int i = 0; i <= n - k; ++i) {
		int tmp = C(i, n - k);
		mult(tmp, modPow(n - k - i, n));
		if (i & 1) t = (t - tmp + MOD) % MOD;
		else add(t, tmp);
	}
	mult(res, t);
	if (k != 0) mult(res, 2);
	cout << res << endl;

	return 0;
}