#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, MOD = 998244353;
int n, p[N], dp[N], pref[N];

void mul(int &a, int b) {
	a = a * b % MOD;
}
void add(int &a, int b) {
	a = (a + b) % MOD;
}

int modPow(int x, int y) {
	int ret = 1LL;
	while (y) {
		if (y & 1) mul(ret, x);
		mul(x, x);
		y >>= 1;
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[i];
	pref[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pref[i] = p[i];
		mul(pref[i], pref[i - 1]);
	}
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1] * 100;
		add(dp[i], pref[i - 1] * 100);
	}
	int res = dp[n] * modPow(pref[n], MOD - 2LL) % MOD;

	cout << res << endl;

	return 0;
}