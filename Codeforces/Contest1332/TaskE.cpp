#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 998244353;

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

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int n, m, l, r;
	cin >> n >> m >> l >> r;
	int tot = n * m;
	int c = modPow(r - l + 1, n * m);
	int add;
	if ((r - l + 1) % 2 == 0) add = 0;
	else {
		if (l & 1) add = -1;
		else add = 1;
		if ((n * m) % 2 == 0) add = abs(add);
	}
	int iv = 499122177;
	int res = c - (c - add) * iv % MOD;
	res = (res + MOD) % MOD;
	cout << res << endl;

	return 0;
}