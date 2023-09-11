#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, m, active[N], mark[N], res, dp[N];
vector <ii> adj[N];
vector <int> topo;

void dfs(int u) {
	mark[u] = 1;
	for (ii ed : adj[u]) {
		int v = ed.first, id = ed.second;
		if (!active[id]) {
			continue;
		}
		if (mark[v] == 1) {
			res++;
			active[id] = false;
			continue;
		}
		if (!mark[v]) {
			dfs(v);
		}
	}
	topo.push_back(u);
	mark[u] = 2;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
		active[i] = 1;
	}
	dfs(1);
	// for (int u : topo) {
	// 	cerr << u << ' ';
	// }
	// cerr << endl;

	for (int i = 1; i < n; ++i) {
		dp[i] = (int)1e18;
	}
	for (int u : topo) {
		map <int, int> cnt;
		cnt.clear();
		int tot = 0;
		for (ii edge : adj[u]) {
			int v = edge.first;
			int id = edge.second;
			// if (!active[id]) {
			// 	continue;
			// }
			tot++;
			cnt[dp[v]]++;
		}
		for (auto counter : cnt) {
			int value = counter.first;
			int times = counter.second;

			dp[u] = min(dp[u], value + 1 + tot - times);
			tot -= times;
		}
	}
	cout << dp[1] << endl;

	return 0;
}