#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
const int N = 5005, oo = 1e18;
int dp[N][N][2], n, b, c[N], d[N], subSize[N], res;
vector <int> adj[N], g[2];
 
void dfs(int u) {
	for (int v : adj[u]) {
		dfs(v);
	}
	subSize[u] = 1;
	for (int i = 0; i <= n; ++i) g[0][i] = oo;
	g[0][1] = c[u];
	int sz = 1;
	for (int v : adj[u]) {
		subSize[u] += subSize[v];
		for (int i = 0; i <= n; ++i) g[1][i] = oo;
		for (int i = 1; i <= sz; ++i) {
			for (int j = 0; j <= subSize[v]; ++j) {
				g[1][i + j] = min(g[0][i] + min(dp[v][j][0], dp[v][j][1] - d[v]), g[1][i + j]);
			}
		}
		g[0] = g[1];
		sz += subSize[v];
	}
	for (int i = 0; i <= n; ++i) {
		dp[u][i][1] = g[0][i];	
	}
	for (int i = 0; i <= n; ++i) g[0][i] = oo;
	g[0][0] = 0;
	g[0][1] = c[u];
	sz = 1;
	for (int v : adj[u]) {
		for (int i = 0; i <= n; ++i) g[1][i] = oo;
		for (int i = 0; i <= sz; ++i) {
			for (int j = 0; j <= subSize[v]; ++j) {
				g[1][i + j] = min(g[0][i] + dp[v][j][0], g[1][i + j]);
			}
		}
		for (int i = 0; i <= n; ++i)
			g[1][i] = min(g[1][i], g[0][i]);
		g[0] = g[1];
		sz += subSize[v];
	}
	for (int i = 0; i <= n; ++i) {
		dp[u][i][0] = g[0][i];
	}
}
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);
 
	cin >> n >> b;
	cin >> c[1] >> d[1];
	g[0].assign(n + 5, oo);
	g[1].assign(n + 5, oo);
	c[1] -= d[1];
	for (int i = 2; i <= n; ++i) {
		cin >> c[i] >> d[i];
		int x;
		cin >> x;
		adj[x].push_back(i);
	}
	dfs(1);
	int res = -1;
	while (min(dp[1][res + 1][0], dp[1][res + 1][1]) <= b && res < n) res++;
	cout << res << endl;
 
	return 0;
}