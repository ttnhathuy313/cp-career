#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e4 + 5;
int n, m, scc, tin[N], low[N], dfsTime, mark[N];
vector <int> adj[N];

void dfs(int u) {
	mark[u] = 1;
	tin[u] = ++dfsTime;
	low[u] = tin[u];
	for (int v : adj[u]) {
		if (!mark[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else {
			if (mark[v] == 2) {
				continue;
			}
			low[u] = min(low[u], tin[v]);
		}
	}
	// cerr << u << ' ' << low[u] << ' ' << tin[u] << endl;
	if (low[u] == tin[u]) scc++;
	mark[u]= 2;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TJALG.INP", "r", stdin);
	freopen("TJALG.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i) if (tin[i] == 0) {
		dfs(i);
	}
	cout << scc << endl;

	return 0;
}