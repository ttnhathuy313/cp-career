#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 105;
int n, grid[N][N], m, mark[N][N], tc = 0;
int dx[] = {1, -1, 0, 0},
	dy[] = {0, 0, 1, -1};

void solve() {
	memset(grid, 0, sizeof grid);
	memset(mark, 0, sizeof mark);

	for (int i = 1; i <= m; ++i) {
		string s;
		cin >> s;
		cerr << s << endl;
		for (int j = 1; j <= n; ++j) {
			if (s[j - 1] == '-') grid[i][j] = 1;
		}
	}
	int cc = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) if (grid[i][j] && !mark[i][j]) {
			cc++;
			queue <ii> q;
			while (!q.empty()) q.pop();
			q.push({i, j});
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = x + dx[dir], ny = y + dy[dir];
					if (nx == 0 || nx == m + 1 || ny == 0 || ny == n + 1 || mark[nx][ny] || grid[nx][ny] == 0) continue;
					q.push({nx, ny});
					mark[nx][ny] = 1;
				}
			}
		}
	}
	cout << "Case " << (++tc) << ": " << cc << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	while (cin >> m >> n) {
		solve();
	}

	return 0;
}