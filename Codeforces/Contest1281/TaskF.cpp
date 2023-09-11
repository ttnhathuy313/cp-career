#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define int long long

const int N = 3005, oo = 1e18;
int n, m, a[N], subSize[N];
vector <int> adj[N];
pair <int, int> tmp[N], dp[N][N];

pair <int, int> operator + (const pair <int, int> a, const pair <int, int> b) {
	return {a.first + b.first, a.second + b.second};
}

void dfs(int u, int pre) {
	subSize[u] = 1;
	dp[u][0] = {0, a[u]};
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
		for (int i = 0; i <= subSize[u]; ++i) if (dp[u][i].second != -oo) {
			for (int j = 0; j <= subSize[v]; ++j) {
				pair <int, int> trans = dp[v][j];
				if (j > 0 && dp[v][j - 1].second > 0) trans = max(trans, {dp[v][j - 1].first + 1, 0});
				if (trans.second == oo) continue;
				tmp[i + j] = max(tmp[i + j], dp[u][i] + trans);
			}
		}
		subSize[u] += subSize[v];
		for (int i = 0; i <= subSize[u]; ++i) {
			dp[u][i] = tmp[i];
			tmp[i] = {0, -oo};
		}
	}
	if (u != 1) {
		for (int i = n; i >= 1; --i) {
			if (dp[u][i - 1].second > 0) {
				dp[u][i] = max(dp[u][i], {dp[u][i - 1].first + 1, 0});
			} else dp[u][i] = max(dp[u][i], {dp[u][i - 1].first, 0});
		}
	} else {
		for (int i = n; i >= 1; --i) {
			if (dp[u][i - 1].second > 0) {
				dp[u][i] = {dp[u][i - 1].first + 1, 0};
			} else dp[u][i] = {dp[u][i - 1].first, 0};
		}
	}
	// for (int i = 0; i <= m; ++i) {
	// 	cerr << "dp[" << u << "][" << i << "] : " << dp[u][i].first << ' ' << dp[u][i].second << endl;
	// }
}

void solve() {
	cin >> n >> m;
	tmp[0] = {0, -oo};
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j)
			dp[i][j] = {0, -oo};
		tmp[i] = {0, -oo};
		a[i] = 0;
		subSize[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		a[i] -= x;
	}
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		a[i] += x;
		adj[i].clear();
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	cout << dp[1][m].first << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}