#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, MOD = 1e9 + 7;
int n, l, r, fac[N];

int modPow(int x, int y) {
	x %= MOD;
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

int C(int k, int n) {
	if (k > n) return 0;
	if (k < 0 || n < 0) return 0;
	return fac[n] * (inv(fac[k] * fac[n - k]) % MOD) % MOD;
}

void add(int &x, int y) {
	x = (x + y) % MOD;
}

void solve() {
	int border = min(r - n, 1 - l), res = 0, half = n / 2;
	add(res, border * C(half, n)% MOD);
	if (n & 1) add(res, border * C(half + 1, n) % MOD);
	for (int k = border + 1; k <= border + n; ++k) {
		int h = max(1LL, l + k) - 1, p = n - min(n, r - k);
		add(res, C(half - p, n - h - p));
		if (n & 1) add(res, C(half - p + 1, n - h - p));
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	fac[0] = 1;
	for (int i = 1; i <= N - 5; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
	}

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> l >> r;
		solve();
	}

	return 0;
}