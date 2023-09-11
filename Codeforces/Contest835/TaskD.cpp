#include <bits/stdc++.h>

using namespace std;

const int N = 5005, MOD1 = 1e9 + 7, MOD2 = 1e9 + 9, base1 = 37, base2 = 31;
int n, lo = 14, res[19], h[N][N], g[N][N];
string s;
bool f[N][N][2];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> s;
	n = s.size();
	s = ' ' + s;
	res[0] = n;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			h[i][j] = (1LL * h[i][j - 1] * base1 + s[j] - 'a' + 1) % MOD1;
			g[i][j] = (1LL * g[i][j - 1] * base2 + s[j] - 'a' + 1) % MOD2;
		}
	}
	for (int i = 1; i <= n; ++i)
		f[i][i][0] = 1;
	for (int len = 2; len <= n; ++len) {
		for (int i = 1; i <= n; ++i) {
			int j = i + len - 1;
			if (j > n || s[i] != s[j]) continue;
			if (len != 2) f[i][j][0] = f[i + 1][j - 1][0];
			else f[i][j][0] = 1;

			if (f[i][j][0]) res[0]++;
		}
	}
	for (int k = 1; k <= lo; ++k) {
		int cur = k & 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = i; j <= n; ++j) {
				int len = (j - i + 1) / 2;
				int mid = i + len - 1;
				f[i][j][cur] = f[i][mid][cur ^ 1] & f[mid + 1 + ((j - i + 1) & 1)][j][cur ^ 1];
				if (g[i][mid] != g[mid + 1 + ((j - i + 1) & 1)][j] || h[i][mid] != h[mid + 1 + ((j - i + 1) & 1)][j])
					f[i][j][cur] = 0;
				if (f[i][j][cur]) res[k]++;
			}
		}
	}

	for (int i = 0; i <= min(n - 1, lo); ++i) cout << res[i] << ' ';
	for (int i = min(n - 1, lo) + 1; i < n; ++i) cout << "0 ";

	return 0;
}