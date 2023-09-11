#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, M = 55, oo = 1e18;
int n, m, k, d, g1, g2, g3, f[M][N][2], v[M], g[N][M];
string s;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("AC6.INP", "r", stdin);
	freopen("AC6.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> k >> d >> g1 >> g2 >> g3 >> s;
		s = ' ' + s;
		if (m == 0) {
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j <= m; ++j) {
					g[i][j] = -oo;
				}
			}
			g[0][0] = 0;
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j <= k; ++j) {
					if (i >= 2) g[i][j] = max(g[i][j], g[i - 2][j] + g2);
					if (j) g[i][j] = max(g[i][j], g[i - 1][j - 1] + g1);
				}
			}
			int res = 0;
			for (int i = 0; i <= k; ++i) res = max(res, g[n][i]);
			cout << res << endl;
			continue;
		}
		int cnt = 0;
		for (int i = 1; i <= n; ++i) if (s[i] == '#') {
			v[++cnt] = i;
		}
		int thick = 0;
		for (int i = 1; i <= m; ++i) thick += max(0LL, (v[i] - 3 - v[i - 1])) / 2;
		thick += max(0LL, (n - 2 - v[m])) / 2;
		m++;
		thick += max(0LL, (v[1] - 2)) / 2;
		v[m] = n + 1;
		v[m + 1] = n + 2;
		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= k; ++j) {
				f[i][j][0] = f[i][j][1] = -oo;
			}
		}
		f[0][0][0] = 0;
		for (int i = 1; i <= m; ++i) {
			if (i == m) d = 0;
			for (int j = 0; j <= k; ++j) {
				if (v[i] == v[i - 1] + 1) {
					f[i][j][1] = -oo;
					f[i][j][0] = f[i - 1][j][0] - d;
					continue;
				}
				if (v[i] == v[i - 1] + 2) {
					f[i][j][0] = max(f[i][j][0], f[i - 1][j - 1][0] + g1 - d);
					f[i][j][0] = max(f[i][j][0], f[i - 1][j][1] - d);
					f[i][j][0] = max(f[i][j][0], f[i - 1][j][0] - d);
					f[i][j][1] = max(f[i][j][1], f[i - 1][j][0] + g3);
					continue;
				}
				if ((v[i] - 3 - v[i - 1]) % 2 == 0) {
					for (int use = 0; use <= 2; ++use) if (j >= use) {
						f[i][j][0] = max(f[i][j][0], f[i - 1][j - use][0] + use * g1 - d + (use == 0 ? g2 : 0));
					}
					for (int use = 0; use <= 1; ++use) if (j >= use) {
						f[i][j][0] = max(f[i][j][0], f[i - 1][j - use][1] + use * g1 - d + (use == 0 ? g2 : 0));
					}
					if (v[i] == v[i + 1] - 1) continue;
					for (int use = 0; use <= 1; ++use) if (j >= use) {
						f[i][j][1] = max(f[i][j][1], f[i - 1][j - use][0] + use * g1 + g3);
					}
					for (int use = 0; use <= 0; ++use) if (j >= use) {
						f[i][j][1] = max(f[i][j][1], f[i - 1][j - use][1] + use * g1 + g3);
					}
				} else {
					for (int use = 0; use <= 3; ++use) if (j >= use) {
						f[i][j][0] = max(f[i][j][0], f[i - 1][j - use][0] + use * g1 - d + (use <= 1 ? g2 : 0));
					}
					for (int use = 0; use <= 2; ++use) if (j >= use) {
						f[i][j][0] = max(f[i][j][0], f[i - 1][j - use][1] + use * g1 - (i == m ? 0 : d) + (use == 0 ? g2 : 0));
					}
					if (v[i] == v[i + 1] - 1) {
						continue;
					}
					for (int use = 0; use <= 2; ++use) if (j >= use) {
						f[i][j][1] = max(f[i][j][1], f[i - 1][j - use][0] + use * g1 + g3 + (use == 0 ? g2 : 0));
					}
					for (int use = 0; use <= 1; ++use) if (j >= use) {
						f[i][j][1] = max(f[i][j][1], f[i - 1][j - use][1] + use * g1 + g3);
					}
				}
			}
		}
		int res = -oo;
		for (int i = 0; i <= k; ++i) {
			int tmp = f[m][i][0];
			if (g1 * 2 > g2) {
				tmp += min(thick, (k - i) / 2) * 2 * g1 + (thick - min(thick, (k - i) / 2)) * g2;
			} else tmp += thick * g2;
			res = max(res, tmp);
		}
		cout << res << endl;
	}

	return 0;
}