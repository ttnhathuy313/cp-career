#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
int n, m, tin[N], low[N], dfsTime, res1, res2;
vector <int> adj[N];
bool mark[N];

void dfs(int u, int pre) {
	tin[u] = low[u] = ++dfsTime;
	mark[u] = 1;
	int nchild = 0, ok = 0;
	for (int v : adj[u]) {
		if (v == pre) continue;
		if (!mark[v]) {
			nchild++;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > tin[u]) res2++;
			if (low[v] >= tin[u]) ok = 1;
		} else low[u] = min(low[u], tin[v]);
	}
	if (nchild == 0) ok = 0;
	if (~pre) {
		if (ok) res1++;
	} else res1 += (nchild > 1);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("GRAPH_.INP", "r", stdin);
	freopen("GRAPH_.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) if (!mark[i]) {
		dfs(i, -1);
	}
	cout << res1 << ' ' << res2 << endl;

	return 0;
}