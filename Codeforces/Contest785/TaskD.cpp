#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, MOD = 1e9 + 7;
int n, fac[N * 2];
string s;

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
	if (k < 0) return 0;
	int ret = fac[n];
	ret = ret * inv(fac[n - k] * fac[k]) % MOD;
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> s;
	n = s.size(); s = ' ' + s;
	fac[0] = 1;
	for (int i = 1; i <= 2 * n; ++i)
		fac[i] = fac[i - 1] * i % MOD;
	int close = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == ')') close++;
	}
	int open = 0, res = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == ')') close--;
		else {
			open++;
			// cerr << open << ' ' << close << ' ' << C(open, open + close - 1) << endl;
			res = (res + C(open, open + close - 1)) % MOD;
		}
	}
	cout << res << endl;

	return 0;
}