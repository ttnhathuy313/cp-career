#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

vector <vector <int>> grid, row, col, x, y;
int n, m, k;

void init() {
	grid.assign(n + 5, vector <int>(m + 5, 0));
	row.assign(n + 5, vector <int>(m + 5, 0));
	col.assign(n + 5, vector <int>(m + 5, 0));
	x.assign(n + 5, vector <int>(m + 5, -1));
	y.assign(n + 5, vector <int>(m + 5, -1));
}

int solve(int target) {
	int ret = 0;
	row.assign(n + 5, vector <int>(m + 5, 0));
	col.assign(n + 5, vector <int>(m + 5, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			col[i][j] += col[i - 1][j];
			row[i][j] = col[i][j] + row[i][j - 1];
			row[i][j] %= 3;
			int more = (target - grid[i][j] - row[i][j] + 9) % 3;
			if (more && x[i][j] == -1) return (int)1e18;
			if (more == 0) continue;
			row[i][j] += more;
			int u = x[i][j], v = y[i][j];
			col[i][j] += more;
			col[u + 1][j] -= more;
			col[u + 1][v + 1] += more;
			col[i][v + 1] -= more;
			ret += more;
		}
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("LIGHT.INP", "r", stdin);
	freopen("LIGHT.OUT", "w", stdout);

	cin >> n >> m >> k;
	init();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> grid[i][j];
		}
	}
	for (int i = 1; i <= k; ++i) {
		int r, c;
		cin >> r >> c;
		cin >> x[r][c] >> y[r][c];
	}
	int v = min(solve(1), solve(2));
	cout << (v == (int)1e18 ? -1 : v) << endl;

	return 0;
}