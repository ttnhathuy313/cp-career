#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int N = 305, oo = 1e9;
int grid[N][N], p, n, m, dp[N][N], dist[N][N];
vector <ii> idx[N * N];
int dx[] = {1, -1, 0, 0},
	dy[] = {0, 0, 1, -1};

void make_a_fucking_bfs(int turn) {
	memset(dist, -1, sizeof dist);
	vector <iii> V;
	V.clear();
	for (ii u : idx[turn]) {
		V.push_back({dp[u.first][u.second], u});
		dist[u.first][u.second] = dp[u.first][u.second];
	}
	sort(V.begin(), V.end());
	deque <iii> cur, tmp;
	cur.clear();
	for (iii d : V) cur.push_back(d);
	while (cur.size() > 0) {
		iii pack;
		if (tmp.size() && tmp.front() < cur.front()) {
			pack = tmp.front(); tmp.pop_front();
		} else {
			pack = cur.front(); cur.pop_front();
		}
		int x = pack.second.first, y = pack.second.second, d = pack.first;
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
			if (~dist[nx][ny]) continue;
			dist[nx][ny] = dist[x][y] + 1;
			iii need_a_push = iii(dist[nx][ny], ii(nx, ny));
			if (need_a_push < cur.back()) {
				tmp.push_back(need_a_push);
			} else cur.push_back(need_a_push);
		}
	}
	for (ii u : idx[turn + 1]) {
		dp[u.first][u.second] = dist[u.first][u.second];
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m >> p;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> grid[i][j];
			dp[i][j] = oo;
			idx[grid[i][j]].push_back(ii(i, j));
		}
	}
	for (ii u : idx[1]) {
		int i = u.first, j = u.second;
		dp[i][j] = i + j - 2;
	}
	for (int i = 2; i <= p; ++i) {
		if (idx[i - 1].size() > n) {
			make_a_fucking_bfs(i - 1);
		} else {
			for (ii u : idx[i]) {
				for (ii v : idx[i - 1]) {
					dp[u.first][u.second] = min(dp[u.first][u.second], dp[v.first][v.second] + abs(u.first - v.first) + abs(u.second - v.second));				
				}
			}
		}
	} 
	cout << dp[idx[p][0].first][idx[p][0].second] << endl;

	return 0;
}