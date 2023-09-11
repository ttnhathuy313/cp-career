#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5005, MOD = 998244353;
int n, dp[N][N], m, b[N], a[N], pref[N];

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

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
	}
	sort(b + 1, b + 1 + m);
	int cont = 0;
	for (int i = 1; i <= m + 1; ++i) {
		if (b[i] == b[i - 1]) cont++;
		else {
			a[n++] = cont;
			cont = 1;
		}
	}
	n--;
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + a[i];
	}
	int good = 0, bad = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * a[i]);
			if (a[i] > 1) {
				good = good + (a[i] * (a[i] - 1) / 2) * dp[i - 1][j] % MOD;
				good %= MOD;
			}
			int rem = pref[i - 1] - j;
			bad = bad + (a[i] * rem * dp[i - 1][j]) % MOD;
			if (i == 3) cerr << j << ' ' << (a[i] * rem * dp[i - 1][j]) << endl;
			bad %= MOD;
		}
	}
	cerr << bad << endl;

	int res = good * inv(bad + good) % MOD;
	cout << res << endl;

	return 0;
}