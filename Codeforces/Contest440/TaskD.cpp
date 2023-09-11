#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 405, oo = 1e9;
int n, k, dp[N][N][N], subSize[N], res = oo, sz[N], id, par[N];
vector <int> adj[N], trace[N];
map <ii, int> ind;

void dfs(int u, int pre) {
	subSize[u] = 1, par[u] = pre;
	int layer = 0;
	for (int i = 2; i <= n; ++i)
		dp[u][i][0] = oo;
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
		++layer;
		for (int i = 1; i <= n; ++i)
			dp[u][i][layer] = oo;
		for (int i = 0; i <= subSize[v]; ++i) {
			for (int j = 1; j <= subSize[u]; ++j) {
				dp[u][i + j][layer] = min(dp[u][i + j][layer], dp[u][j][layer - 1] + (i == 0 ? 1 : dp[v][i][sz[v]]));
			}
		}
		subSize[u] += subSize[v];
	}
	if (dp[u][k][layer] + (pre == -1 ? 0 : 1) < res) {
		res = dp[u][k][layer] + (pre == -1 ? 0 : 1);
		id = u;
	}
	sz[u] = layer;
}

void print(int u, int pre, int rem) {
	if (id == u && pre != -1)
		cout << ind[{u, pre}] << ' ';
	reverse(adj[u].begin(), adj[u].end());
	int cur = rem;
	for (int v : adj[u]) {
		if (v == pre) continue;
		for (int i = 0; i <= subSize[v]; ++i) if (i <= cur) {
			if (dp[u][cur - i][sz[u] - 1] + (i == 0 ? 1 : dp[v][i][sz[v]]) == dp[u][cur][sz[u]]) {
				if (i == 0) {
					cout << ind[{u, v}] << ' ';
					break;
				} else {
					print(v, u, i);
					cur -= i;
					break;
				}
			}
		}
		sz[u]--;
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		ind[{x, y}] = i;
		ind[{y, x}] = i;
	}
	dfs(1, -1);
	cerr << id << endl;
	cout << res << endl;
	print(id, par[id], k);

	return 0;
}