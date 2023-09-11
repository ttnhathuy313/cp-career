#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 505;
int n, m, grid[N][N], mark[N][N], a, b;
int dx[] = {1, -1, 0, 0},
	dy[] = {0, 0, 1, -1};
queue <ii> q;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	memset(mark, -1, sizeof mark);
	cin >> m >> n >> a >> b;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			if (s[j - 1] == '#') grid[i][j] = 0;
			else grid[i][j] = 1;
		}
	}
	mark[1][1] = 0;
	q.push({1, 1});
	while (!q.empty()) {
		ii d = q.front();
		q.pop();
		int x = d.first, y = d.second;
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx == 0 || nx == n + 1 || ny == 0 || ny == m + 1 || !grid[nx][ny] || (~mark[nx][ny])) continue;
			mark[nx][ny] = mark[x][y] + 1;
			q.push({nx, ny});
		}
	}
	int len = mark[n][m];
	if (len == -1) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	cerr << len << endl;
	int res = (int)1e9 + 7;
	for (int i = 0; i <= len; ++i) if (abs(i - len + i) <= 1 && i <= len - i) {
		res = min(res, i * a + (len - i) * b);
	}
	cout << res << endl;

	return 0;
}