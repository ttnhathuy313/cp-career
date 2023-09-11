#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1005, M = 1e6 + 5;
int n, m, grid[N][N], comp[N][N], dp[M], value[M], cnt;
vector <int> adj[M], topo;
bool mark[M];
int dx[] = {1, -1, 0, 0},
	dy[] = {0, 0, 1, -1};

void dfs(int u) {
	mark[u] = 1;
	for (int v : adj[u]) {
		if (!mark[v]) dfs(v);
	}
	topo.push_back(u);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("VLUOI.INP", "r", stdin);
	freopen("VLUOI.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> grid[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) if (!comp[i][j]) {
			queue <ii> q;
			while (!q.empty()) q.pop();
			value[++cnt] = 1;
			comp[i][j] = cnt;
			q.push({i, j});
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = x + dx[dir], ny = y + dy[dir];
					if (nx < 1 || nx > n || ny < 1 || ny > m || comp[nx][ny] || grid[x][y] != grid[nx][ny])
						continue;
					comp[nx][ny] = cnt;
					value[cnt]++;
					q.push({nx, ny});
				}
			}
			value[cnt] *= grid[i][j];
			if (grid[i][j] == 1) value[cnt] = 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i != n && comp[i][j] != comp[i + 1][j])
				adj[comp[i][j]].push_back(comp[i + 1][j]);
			if (j != m && comp[i][j] != comp[i][j + 1])
				adj[comp[i][j]].push_back(comp[i][j + 1]);
		}
	}
	dfs(1);
	reverse(topo.begin(), topo.end());
	for (int i = 1; i <= cnt; ++i) 
		dp[i] = (int)1e18;
	dp[comp[1][1]] = 0;
	for (int u = 1; u <= cnt; ++u) {
		for (int v : adj[u]) 
			dp[v] = min(dp[v], dp[u] + value[v]);
	}
	cout << dp[comp[n][m]] << endl;

	return 0;
}