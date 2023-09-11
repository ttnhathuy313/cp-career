#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 1005;
int n, m, maxCol[N], maxRow[N], minRow[N], minCol[N], cntRow[N], cntCol[N], a[N][N];
int dx[] = {1, -1, 0, 0},
	dy[] = {0, 0, 1, -1};
bool mark[N][N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		minRow[i] = N;
		for (int j = 1; j <= m; ++j) {
			minCol[j] = N;
			a[i][j] = (s[j - 1] == '#');
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) if (a[i][j]) {
			cntRow[i]++; cntCol[j]++;
			maxRow[i] = max(maxRow[i], j);
			maxCol[j] = max(maxCol[j], i);
			minRow[i] = min(minRow[i], j);
			minCol[j] = min(minCol[j], i);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (a[i][j] && !mark[i][j]) {
		res++;
		queue <ii> q;
		while (!q.empty()) q.pop();
		memset(mark, 0, sizeof mark);
		q.push({i, j});
		mark[i][j] = 1;
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			if (maxRow[x] - minRow[x] + 1 != cntRow[x]) {
				cout << -1 << endl;
				return 0;
			}
			if (maxCol[y] - minCol[y] + 1 != cntCol[y]) {
				cout << -1 << endl;
				return 0;
			}
			q.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir], ny = y + dy[dir];
				if (nx == 0 || nx == n + 1 || ny == 0 || ny == m + 1 || !a[nx][ny] || mark[nx][ny]) continue;
				mark[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}
	int sa = 0, sb = 0;
	for (int i = 1; i <= n; ++i) if (cntRow[i] == 0) sa++;
	for (int i = 1; i <= m; ++i) if (cntCol[i] == 0) sb++;
	if (sa + sb && (sa == 0 || sb == 0)) {
		cout << -1 << endl;
		return 0;
	}
	cout << res << endl;

	return 0;
}