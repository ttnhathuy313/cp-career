#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5, LOG = 23, oo = 2e18;
int n, s, q, e, dfsTime, tin[N], tout[N], h[N], P[N][LOG], dp[N], V[N][LOG], depth[N];
bool shop[N];
ii E[N];
vector <ii> adj[N];

void dfs(int u, int pre) {
	tin[u] = ++dfsTime;
	for (ii d : adj[u]) {
		int v = d.first;
		if (v == pre) continue;
		h[v] = h[u] + d.second;
		depth[v] = depth[u] + 1;
		dfs(v, u);
	}
	tout[u] = ++dfsTime;
}

void dfs2(int u, int pre) {
	dp[u] = oo;
	if (shop[u]) dp[u] = h[u];
	for (ii d : adj[u]) {
		int v = d.first;
		if (v == pre) continue;
		dfs2(v, u);
		V[v][0] = u;
		dp[u] = min(dp[v], dp[u]);
	}
	P[u][0] = dp[u] - 2 * h[u];
	if (dp[u] == oo) P[u][0] = oo;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s >> q >> e;
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		E[i] = {u, v};
	}
	for (int i = 1; i <= s; ++i) {
		int c;
		cin >> c;
		shop[c] = 1;
	}
	dfs(e, -1);
	dfs2(e, -1);
	for (int i = 1; i < LOG; ++i) {
		for (int u = 1; u <= n; ++u) {
			P[u][i] = min(P[V[u][i - 1]][i - 1], P[u][i - 1]);
			V[u][i] = V[V[u][i - 1]][i - 1];
		}
	}
	while (q--) {
		int iiiii, u;
		cin >> iiiii >> u;
		int x = E[iiiii].first, y = E[iiiii].second;
		if (tin[y] > tin[x]) swap(x, y);
		if (!(tin[x] <= tin[u] && tout[x] >= tout[u])) {
			cout << "escaped\n";
			continue;
		}
		int hu = h[u];
		int res = oo;
		for (int i = LOG; i >= 0; --i) if ((1 << i) <= depth[u] - depth[y]) {
			res = min(res, P[u][i]);
			u = V[u][i];
		}
		if (res == oo) {
			cout << "oo\n";
			continue;
		}
		cout << res + hu << endl;
	}
 
	return 0;
}