#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, MOD = 1e9 + 7;
int fac[N];

int modPow(int a, int x) {
	int res = 1;
	a %= MOD;
	while (x) {
		if (x & 1) res = 1LL * res * a % MOD;
		a = 1LL * a * a % MOD;
		x >>= 1;
	}
	return res;
}

int inv(int x) {
	return modPow(x, MOD - 2);
}

int C(int k, int n) {
	if (k > n) return 0;
	int tmp = fac[n];
	tmp = 1LL * tmp * inv(1LL * fac[n - k] * fac[k] % MOD) % MOD;
	return tmp;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);

	int n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) 
		fac[i] = 1LL * fac[i - 1] * i % MOD;
	s = ' ' + s;
	int sum = 0;
	int res = 0;
	for (int k = n; k >= 1; --k) {
		int i = n - k + 1;
		if (i >= 2) sum += 1LL * C(t - 1, n - i) * modPow(10, i - 2) % MOD;
		sum %= MOD;
		res += 1LL * sum * (s[k] - '0') % MOD;
		res %= MOD;
		res += 1LL * (1LL * C(t, n - i) * modPow(10, i - 1) % MOD) * (s[k] - '0') % MOD;
		res %= MOD;
	}
	cout << res << endl;
 
	return 0;
}