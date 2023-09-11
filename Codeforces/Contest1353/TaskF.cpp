#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 105, oo = 1e18;
int n, m, f[N][N], g[N][N], a[N][N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	int res = oo;
	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= m; ++y) {
			int fdec;
			if (a[1][1] + x + y - 2 < a[x][y]) continue;
			else fdec = (a[1][1] + x + y - 2) - a[x][y];
			int beg = a[1][1] - fdec, end = beg + n + m - 2;
			for (int i = 0; i <= n + 1; ++i) {
				for (int j = 0; j <= m + 1; ++j) {
					f[i][j] = g[i][j] = oo;
				}
			}
			if (a[n][m] < beg + n + m - 2) continue;
			f[1][1] = fdec; g[n][m] = a[n][m] - beg - n - m + 2;
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= m; ++j) {
					if (i + j == 2) continue;
					int require = beg + i + j - 2;
					if (require > a[i][j]) continue;
					f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j] - require;
				}
			}
			for (int i = n; i >= 1; --i) {
				for (int j = m; j >= 1; --j) {
					if (i == n && j == m) continue;
					int require = beg + i + j - 2;
					if (require > a[i][j]) continue;
					g[i][j] = min(g[i + 1][j], g[i][j + 1]) + a[i][j] - require;
				}
			}
			res = min(res, f[x][y] + g[x][y]);
		}
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("TaskF.INP", "r", stdin);
	// freopen("TaskF.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}