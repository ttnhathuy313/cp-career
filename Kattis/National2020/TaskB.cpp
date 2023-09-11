#include <bits/stdc++.h>

using namespace std;
#define int long long

vector <vector <int>> grid, dist;
int r, c;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1},
	dy[] = {0, 0, 1, -1, -1, 1, 1, -1};

void solve() {
	grid.assign(r + 5, vector <int>(c + 5, 0));
	dist.assign(r + 5, vector <int>(c + 5, -1));
	for (int i = 1; i <= r; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < c; ++j) {
			if (s[j] == '.') grid[i][j + 1] = 2;
			else if (s[j] == '#') grid[i][j + 1] = 1;
		}
	}
	deque <array <int, 3>> dq;
	dq.clear();
	for (int i = 1; i <= r; ++i) {
		dq.push_front({i, 0, 0});
		dist[i][0] = 0;
	}
	for (int i = 1; i <= c; ++i) {
		dq.push_front({r + 1, i, 0});
		dist[r + 1][i] = 0;
	}
	while (!dq.empty()) {
		array <int, 3> cur = dq.front(); dq.pop_front();
		int x = cur[0], y = cur[1], d = cur[2];
		for (int dir = 0; dir < 8; ++dir) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (ny < 0 || nx == r + 2) continue;
			if (nx == 0 || ny == c + 1) if (x && y && x != r + 1 && y != 0) {
				cout << d << endl;
				return;
			} else continue;
			if (grid[nx][ny] == 0 || ~dist[nx][ny]) continue;
			dist[nx][ny] = d + grid[nx][ny] - 1;
			if (grid[nx][ny] == 1) dq.push_front({nx, ny, dist[nx][ny]});
			else dq.push_back({nx, ny, dist[nx][ny]});
		}
	}
	cout << -1 << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	while (cin >> r >> c && (r | c)) {
		solve();
	}

	return 0;
}