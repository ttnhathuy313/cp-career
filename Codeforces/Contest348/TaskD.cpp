#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 3005, MOD = 1e9 + 7;
int n, m, f[N][N][2];
bool grid[N][N];

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			if (s[j - 1] == '.') grid[i][j] = 1;
			else grid[i][j] = 0;
		}
	}
	if (grid[1][2]) f[1][2][0] = 1;
	if (grid[2][1]) f[2][1][1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = 0; k < 2; ++k) {
				if (!grid[i][j] || i + j <= 3) continue;
				f[i][j][k] = (f[i - 1][j][k] + f[i][j - 1][k]) % MOD;
			}
		}
	}
	cout << (f[n - 1][m][0] * f[n][m - 1][1] - f[n - 1][m][1] * f[n][m - 1][0] + 1LL * MOD * MOD) % MOD << endl;

	return 0;
}