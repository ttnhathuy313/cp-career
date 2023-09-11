#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int n, m, s, t, ds[N], dt[N], g[N][N];
vector <int> adj[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u][v] = g[v][u] = 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue <int> q;
	while (!q.empty()) q.pop();
	q.push(s);
	memset(ds, -1, sizeof ds);
	ds[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) if (ds[v] == -1) {
			q.push(v);
			ds[v] = ds[u] + 1;
		}
	}
	while (!q.empty()) q.pop();
	q.push(t);
	memset(dt, -1, sizeof dt);
	dt[t] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) if (dt[v] == -1) {
			q.push(v);
			dt[v] = dt[u] + 1;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) if (!g[i][j]) {
			if (min(ds[i] + dt[j] + 1, dt[i] + ds[j] + 1) >= ds[t])
				res++;
		}
	}
	cout << res << endl;

	return 0;
}