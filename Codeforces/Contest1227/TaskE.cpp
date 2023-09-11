#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair <int, int> ii;

const int N = 1e6 + 5;
vector <vector <int>> grid, mark, dp;
queue <ii> q;

int get(int x, int y, int a, int b) {
	return dp[a][b] - dp[a][y - 1] - dp[x - 1][b] + dp[x - 1][y - 1];
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int n, m;
	cin >> n >> m;
	grid.assign(n + 5, vector <int>(m + 5, 0));
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			if (s[j - 1] == '.') grid[i][j] = 0;
			else grid[i][j] = 1;
		}
	}
	dp.assign(n + 5, vector <int>(m + 5, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = grid[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	int l = 0, r = max(n, m), ans = -1;
	vector <vector <int>> F;

	while (l <= r) {
		int mid = (l + r) >> 1;
		F.assign(n + 5, vector <int>(m + 5, 0));
		int sz = (2 * mid + 1) * (2 * mid + 1);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (grid[i][j] == 0) {
					F[i][j] = 0;
					continue;
				}
				int x = i - mid, y = j - mid;
				int u = i + mid, v = j + mid;
				if (x <= 0 || y <= 0 || u > n || v > m) {
					F[i][j] = 0;
					continue;
				}
				if (get(x, y, u, v) == sz) {
					F[i][j] = 1;
				} else F[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				F[i][j] = F[i - 1][j] + F[i][j] + F[i][j - 1] - F[i - 1][j - 1];
			}
		}
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) if (grid[i][j]) {
				int x = i - mid, y = j - mid;
				int u = i + mid, v = j + mid;
				x = max(x, 1); y = max(y, 1);
				u = min(u, n), v = min(v, m);
				if (F[u][v] - F[u][y - 1] - F[x - 1][v] + F[x - 1][y - 1] == 0) {
					ok = false;
					goto tag;
				}
			}
		}
		tag:;
		if (ok) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans << endl;
	int s = (2 * ans + 1) * (2 * ans + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (grid[i][j] == 0) {
				cout << ".";
				continue;
			}
			int x = i - ans, y = j - ans;
			int u = i + ans, v = j + ans;
			if (x <= 0 || y <= 0 || u > n || v > m) {
				cout << ".";
				continue;
			} 
			if (get(x, y, u, v) == s) cout << "X";
			else cout << ".";
		}
		cout << endl;
	}


	return 0;
}