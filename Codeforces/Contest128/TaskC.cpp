#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1005, MOD = 1e9 + 7;
int f[N][N], g[N][N], n, m, k;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n >> m >> k;
	f[n][0] = 1;
	for (int j = 1; j <= k; ++j) {
		int s = 0, p = 0;
		for (int i = n; i >= 1; --i) {
			s += f[i + 2][j - 1];
			s %= MOD;
			p += f[i + 2][j - 1] * (i + 2) % MOD;
			p %= MOD;
			f[i][j] = (p - s * (i + 1) + MOD * MOD) % MOD;
		}
	}
	int S = 0;
	for (int i = 1; i <= n; ++i)
		S = (S + f[i][k]) % MOD;
	g[m][0] = 1;
	for (int j = 1; j <= k; ++j) {
		int s = 0, p = 0;
		for (int i = m; i >= 1; --i) {
			s += g[i + 2][j - 1];
			s %= MOD;
			p += g[i + 2][j - 1] * (i + 2) % MOD;
			p %= MOD;
			g[i][j] = (p - s * (i + 1) + MOD * MOD) % MOD;
		}
	}
	int res = 0;
	for (int i = 1; i < m; ++i) {
		res += (S * g[i][k] % MOD);
		res %= MOD;
	}
	cout << res << endl;

	return 0;
}