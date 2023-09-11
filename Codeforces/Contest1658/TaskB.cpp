#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e3 + 5, MOD = 998244353;
int n, fac[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		if (n & 1) {
			cout << 0 << endl;
			continue;
		}
		fac[0] = 1;
		for (int i = 1; i <= n; ++i) {
			fac[i] = fac[i - 1] * i % MOD;
		}
		int odd = (n + 1) / 2, even = n / 2;
		cout << (fac[odd] * fac[even] % MOD) << endl;
	}

	return 0;
}