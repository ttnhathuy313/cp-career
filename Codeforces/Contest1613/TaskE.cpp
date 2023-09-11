#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 1e6 + 6;

int n, m, mark[N], rem[N];
string grid[N];
// dx and dy are used for going to neighbor cells
int dx[] = {1, -1, 0, 0},
	dy[] = {0, 0, 1, -1};

// 1D indexing is much easier than 2D indexing
int encode(int i, int j) {
	return (i - 1) * m + j - 1;
}

// from 1D back to 2D
ii decode(int x) {
	return {x / m + 1, (x % m) + 1};
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> grid[i];
		grid[i] = ' ' + grid[i];
	}
	for (int i = 0; i <= m * n; ++i) {
		mark[i] = 0;
		rem[i] = 0;
	}
	queue <ii> q;
	while (!q.empty()) {
		q.pop();
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (grid[i][j] == 'L') {
				// only dfs from the root
				q.push({i, j});
				mark[encode(i, j)] = 1;
			}
			for (int dir = 0; dir < 4; ++dir) {
				int nx = i + dx[dir], ny = j + dy[dir];
				if (nx == 0 || ny == 0 || nx == n + 1 || ny == m + 1 || grid[nx][ny] == '#')
					continue;
				rem[encode(i, j)]++;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx == 0 || ny == 0 || nx == n + 1 || ny == m + 1 || grid[nx][ny] == '#')
				continue;
			if (mark[encode(nx, ny)])
				continue;
			rem[encode(nx, ny)]--;
			if (rem[encode(nx, ny)] <= 1) {
				mark[encode(nx, ny)] = 1;
				q.push({nx, ny});
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (mark[encode(i, j)] && grid[i][j] != 'L') {
				cout << '+';
			} else cout << grid[i][j];
		}
		cout << '\n';
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int tc;
	cin >> tc;

	while (tc--) {
		solve();
	}

	return 0;
}