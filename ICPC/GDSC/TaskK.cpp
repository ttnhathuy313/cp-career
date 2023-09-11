#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, MOD = 1e6 + 3;
int n, F1[N], F2[N], xn[N], yn[N], x, y, z, pxn[N], pyn[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskK.INP", "r", stdin);
	freopen("TaskK.OUT", "w", stdout);

	cin >> n >> x >> y >> z;
	for (int i = 1; i <= n; ++i) {
		cin >> F1[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> F2[i];
	}

	pxn[0] = pyn[0] = xn[0] = yn[0] = 1;
	for (int i = 1; i <= n; ++i) {
		xn[i] = xn[i - 1] * x % MOD;
		yn[i] = yn[i - 1] * y % MOD;
		pxn[i] = (pxn[i - 1] + xn[i]) % MOD;
		pyn[i] = (pyn[i - 1] + yn[i]) % MOD;
	}
	int res = 0;
	for (int i = 2; i <= n; ++i) {
		int temp = (yn[n - 1] * xn[n - i] * F1[i]) % MOD;
		temp = (temp + z * pyn[n - 2] * pxn[n - i]) % MOD;
		res = (res + temp) % MOD;
	}
	for (int i = 2; i <= n; ++i) {
		int temp = (xn[n - 1] * yn[n - i] * F2[i]) % MOD;
		temp = (temp + z * pxn[n - 2] * pyn[n - i]) % MOD;
		res = (res + temp) % MOD;
	}
	cout << res << endl;

	return 0;
}