#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 105;
int n, m, b[N][N], ans[N][N], type[N][N];
int dx[] = {1, -1, 0, 0},
	dy[] = {0, 0, 1, -1};
bool mark[N][N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;

	while (tc--) {
		cin >> n >> m;
		vector <ii> id; id.clear();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> b[i][j];
				id.push_back({i, j});
			}
		}
		sort(id.begin(), id.end(), [](ii i, ii j) {	
			return b[i.first][i.second] < b[j.first][j.second];
		});	
		memset(mark, false, sizeof mark);
		memset(type, -1, sizeof type);
		for (ii pack : id) {
			int i = pack.first, j = pack.second;
			if (!mark[i][j]) {
				queue <ii> q; while (!q.empty()) q.pop();
				q.push({i, j});
				vector <ii> S; S.clear();
				int color = 1;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					S.push_back({x, y});
					mark[x][y] = 1;
					for (int dir = 0; dir < 4; ++dir) {
						int nx = x + dx[dir], ny = y + dy[dir];
						if (nx == 0 || nx > n || ny == 0 || ny > m) continue;
						if (b[nx][ny] != b[x][y]) {
							if (b[nx][ny] + 1 == b[x][y]) color = type[nx][ny] ^ 1;
							continue;
						}
						if (mark[nx][ny]) continue;
						mark[nx][ny] = 1;
						q.push({nx, ny});
					}
				}
				// cerr << i << ' ' << j << ' ' << color << endl;
				for (ii v : S) {
					type[v.first][v.second] = color;
					ans[v.first][v.second] = (((v.first ^ v.second) & 1) ^ color);
					// cerr << "	" << v.first << ' ' << v.second << ' ' << ans[v.first][v.second] << endl;
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cout << b[i][j] + ans[i][j] << ' ';
			}
			cout << endl;
		}
	}

	return 0;
}