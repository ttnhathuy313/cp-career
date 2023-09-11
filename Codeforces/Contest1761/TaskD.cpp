#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e6 + 5, MOD = 1e9 + 7;
int fac[N], n, k, p2[N], p4[N];

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
	x %= MOD;
	return modPow(x, MOD - 2);
}

int C(int k, int n) {
	if (k > n) return 0;
	int res = fac[n];
	res = (res * inv(fac[k] * fac[n - k])) % MOD;
	return res;
}

int nhet(int x, int y) {
	return C(y - 1, x + y - 1);
}

int getp2(int x) {
	if (x < 0) {
		return 0;
	} else return p2[x];
}

int getp4(int x) {
	if (x < 0) {
		return 0;
	} else return p4[x];
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);

	cin >> n >> k;
	p2[0] = 1;
	p4[0] = 1;
	fac[0] = 1;
	for (int i = 1; i < N; ++i) {
		p2[i] = p2[i - 1] * 2 % MOD;
		p4[i] = p4[i - 1] * 3 % MOD;
		fac[i] = fac[i - 1] * i % MOD;
	}
	int res = 0;
	if (k == 0) {
		cout << getp4(n) << endl;
		return 0;
	}
	for (int i = 1; i <= k; ++i) {
		int temp = getp4(k - i) * nhet(k - i, i) % MOD;
		int zeros = nhet(n - k - i + 1, i) * getp4(n - k - i + 1) % MOD;
		zeros += (nhet(n - k - i, i + 1) * getp4(n - k - i) % MOD);
		zeros %= MOD;
		temp = temp * zeros % MOD;
		res = (res + temp) % MOD;
	}
	cout << res << endl;

	return 0;
}