#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 505;
int n, x[N], m, f[N], tin[N], tout[N], dfsTime = 0, g[N][N];
bool mark[N];
vector <ii> adj[N];
double res;

void dfs(int u) {
	mark[u] = 1;
	tin[u] = dfsTime++;
	for (ii v : adj[u]) {
		if (mark[v.first]) continue;
		f[v.first] = f[u] + v.second;
		dfs(v.first);
	}
	tout[u] = dfsTime++;
}

void solve(int u, int ver, int e) {
	mark[u] = 1;
	for (ii d : adj[u]) {
		int v = d.first;
		if (tin[v] <= tin[u] && tout[v] >= tin[u]) 
			e += d.second;
	}
	if (e) res = max(res, 1.0 * ver / (e + f[u]));
	for (ii v : adj[u]) if (!mark[v.first]) {
		solve(v.first, ver + x[v.first], e);
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> x[i];
	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u][v] = g[v][u] = 1;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	for (int i = 1; i <= n;  ++i) {
		for (int j = 1; j <= n; ++j) if (i != j && !g[i][j]) {
			adj[i].push_back({j, 0});
		}
	}

	for (int u = 1; u <= n; ++u) {
		dfsTime = 0;
		memset(tin, 0, sizeof tin);
		memset(tout, 0, sizeof tout);
		memset(f, 0, sizeof f);
		memset(mark, 0, sizeof mark);
		dfs(u);
		memset(mark, 0, sizeof mark);
		solve(u, x[u], 0);
	}
	cout << fixed << setprecision(9) << res << endl;

	return 0;
}