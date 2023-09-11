#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, MOD = 998244353;
int n, f[N];
string s;

void solve() {
	cin >> n >> s;
	s = ' ' + s;
	f[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (s[i] != s[i - 1]) {
			f[i] = 1;
			continue;
		}
		f[i] = f[i - 1] * 2;
		f[i] %= MOD;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res = (res + f[i]) % MOD;
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	int x = 3;
	int pow = 1;
	double cur = 0;
	for (int i = 1; i <= 20; ++i) {
		pow = pow * x;
		cur += 1.0/pow;
	}
	cerr << cur << endl;

	return 0;
}