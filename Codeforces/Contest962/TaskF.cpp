#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, tin[N], tout[N], dfsTime, m, cnt[2 * N], dp[N], up[N], down[N], d[N], p[N];
vector <int> adj[N], res, outdown[N], outup[N];
map <pair <int, int>, int> ind;
bool mark[N];

void dfs1(int u, int pre) {
	mark[u] = 1;
	tin[u] = ++dfsTime;
	int mx = 0;
	p[u] = pre;
	for (int v : adj[u]) {
		if (!mark[v]) {
			d[v] = d[u] + 1;
			dfs1(v, u);
			mx = max(mx, dp[v]);
			dp[u] += dp[v];
		} else if (tin[v] > tin[u] && v != pre) {
			outdown[u].push_back(v);
			down[u]++;
		} else if (v != pre) {
			up[u]++;
		}
	}
	tout[u] = ++dfsTime;
	dp[u] += up[u] - down[u];
	cnt[tin[u]] = dp[u];
	cnt[tout[u]] = -dp[u];
}

void dfs2(int u, int pre) {
	mark[u] = 1;
	for (int v : outdown[u]) {
		if (cnt[tin[v]] - cnt[tin[u]] == d[v] - d[u]) {
			int cur = v;
			while (cur != u) {
				res.push_back(ind[{p[cur], cur}]);
				cur = p[cur];
			}
			res.push_back(ind[{u, v}]);
		}
	}
	for (int v : adj[u]) {
		if (!mark[v]) dfs2(v, u);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		ind[{u, v}] = i;
		ind[{v, u}] = i;
	}
	for (int i = 1; i <= n; ++i) if (!mark[i])
		dfs1(i, -1);
	memset(mark, 0, sizeof mark);
	for (int i = 1; i <= 2 * n; ++i) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = 1; i <= n; ++i) if (!mark[i]) 
		dfs2(i, 0);
	sort(res.begin(),  res.end());
	cout << res.size() << endl;
	for (int v : res) cout << v << ' ';

	return 0;
}