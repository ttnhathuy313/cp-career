#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef pair <int, int> ii;

const int N = 2005;
int h[N][N], n, k, mark[N][N];
ii t[N];
queue <ii> q;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("civilization.INP", "r", stdin);
	// freopen("civilization.OUT", "w", stdout);

	cin >> n >> k;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= k; ++i) {
		int x, y;
		cin >> x >> y;
		t[i] = ii(x, y);
		h[x][y] = 0;
		q.push({x, y});
	}
	while (!q.empty()) {
		ii cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx == 0 || nx > n || ny == 0 || ny > n || ~h[nx][ny]) continue;
			h[nx][ny] = h[x][y] + 1;
			q.push({nx, ny});
		}
	}
	int l = 0, r = 2 * n, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		memset(mark, 0, sizeof mark);
		queue <ii> q; while (!q.empty()) q.pop();
		for (int i = 1; i <= 1; ++i) {
			mark[t[i].first][t[i].second] = 1;
			q.push(t[i]);
		}
		while (!q.empty()) {
			ii cur = q.front();
			q.pop();
			int x = cur.first, y = cur.second;
 			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir], ny = y + dy[dir];
				if (nx == 0 || nx > n || ny == 0 || ny > n || h[nx][ny] > mid || mark[nx][ny]) continue;
				mark[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
		bool ok = true;
		for (int i = 1; i <= k; ++i) if (!mark[t[i].first][t[i].second]) ok = false;
		if (ok) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;

	return 0;
}