#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, MOD = 1e9 + 7;
int a[N], b[N], n;

int modPow(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	int exp = 1, base = 1;
	for (int i = 1; i <= n; ++i) {
		base = base * a[i] % MOD;
		exp = exp * b[i] % (MOD - 1);
	}
	cout << modPow(base, exp) << endl;

	return 0;
}