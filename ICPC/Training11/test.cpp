#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, MOD = 1e9 + 7;
int fac[N], n;

int modPow(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

int inv(int x) {
	return modPow(x, MOD - 2);
}

int C(int k, int n) {
	return fac[n] * inv(fac[k] * fac[n - k] % MOD) % MOD;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	fac[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	cerr << C(467, 777) << endl;
	

	return 0;
}