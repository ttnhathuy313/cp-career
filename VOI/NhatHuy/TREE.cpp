#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e3 + 5;
int n, a[N], dp[N][N], subSize[N], ch[N][2], sz[N];
vector <int> adj[N];

void prepare(int u, int pre) {
	int cnt = 0;
	for (int v : adj[u]) {
		if (v == pre) continue;
		if (v != pre) prepare(v, u);
		ch[u][cnt++] = v;
	}
	sz[u] = cnt;
}

void dfs(int u) {
	if (sz[u] == 0) {
		dp[u][0] = a[u];
		dp[u][1] = abs(a[u] - 1);
		subSize[u] = 1;
		return;
	}

	if (sz[u] == 1) {
		int v = ch[u][0];
		dfs(v);
		subSize[u] += subSize[v];
		for (int i = 0; i <= n; ++i)
			dp[u][i] = min(dp[u][i], dp[v][i] + abs(a[u] - i));
		subSize[u]++;
		return;
	}
	int v1 = ch[u][0], v2 = ch[u][1];
	dfs(v1); dfs(v2);
	for (int i = 0; i <= subSize[v1]; ++i) {
		for (int j = 0; j <= subSize[v2]; ++j) if (i + j <= n) {
			dp[u][i + j] = min(dp[u][i + j], dp[v1][i] + dp[v2][j] + abs(a[u] - i - j));
		}
	}
	subSize[u] += subSize[v1] + subSize[v2] + 1;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TREE.INP", "r", stdin);
	freopen("TREE.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j)
			dp[i][j] = (int)1e18;
	}
	prepare(1, -1);
	dfs(1);
	int res = (int)1e18;
	for (int i = 0; i <= n; ++i)
		res = min(res, dp[1][i]);
	cout << res << endl;

	return 0;
}