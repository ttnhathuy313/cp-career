#include <bits/stdc++.h>

using namespace std;

const int N = 205;
int dp[N][N], n, k, subSize[N], res, a[N];
vector <int> adj[N];

void dfs(int u, int pre) {
	vector <int> g[2];
	g[0].assign(n + 5, -1);
	g[0][0] = a[u];
	subSize[u] = 1;
	for (int v : adj[u]) {
		g[1].assign(n + 5, -1);
		if (v == pre) continue;
		dfs(v, u);
		for (int i = 0; i <= subSize[u]; ++i) {
			for (int j = 0; j <= subSize[v]; ++j) if (j + 1 + i > k && ~g[0][i]) {
				g[1][min(j + 1, i)] = max(g[1][min(j + 1, i)], dp[v][j] + g[0][i]);
			}
		}
		for (int j = 0; j <= subSize[v]; ++j) {
			g[1][j + 1] = max(g[1][j + 1], dp[v][j]);
		}
		g[1][0] = max(g[1][0], g[0][0]);
		for (int i = 1; i <= n; ++i) {
			g[1][i] = max(g[1][i], g[0][i]);
		}
		g[0] = g[1];
		subSize[u] += subSize[v];
	}
	for (int i = 0; i <= n; ++i) {
		dp[u][i] = g[0][i];
		res = max(res, g[0][i]);
		// cerr << "dp[" << u << "][" << i << "] : " << dp[u][i] << endl;
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.inp", "r", stdin);
	freopen("TaskF.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	cout << res << endl;

	return 0;
}