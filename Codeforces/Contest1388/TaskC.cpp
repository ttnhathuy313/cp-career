#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, m, p[N], h[N], subSize[N], bad[N];
vector <int> adj[N];
bool ans;

void prepare(int u, int pre) {
	subSize[u] = p[u];
	for (int v : adj[u]) {
		if (v == pre) continue;
		prepare(v, u);
		subSize[u] += subSize[v];
	}
	if ((subSize[u] + h[u]) & 1) {
		ans = false;
		return;
	}
	bad[u] = (subSize[u] - h[u]) >> 1;
	if (bad[u] < 0) {
		ans = false;
		return;
	}
}

void check(int u, int pre) {
	bad[u] -= min(bad[u], p[u]);
	int tot = 0;
	for (int v : adj[u]) if (v != pre)
		tot += bad[v];
	if (tot < bad[u]) {
		ans = false;
		return;
	}
	for (int v : adj[u]) if (v != pre)
		check(v, u);
}

void solve() {
	ans = true;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> p[i];
	for (int i = 1; i <= n; ++i)
		cin >> h[i];
	for (int i = 1; i <= n; ++i)
		adj[i].clear();
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	prepare(1, -1);
	check(1, -1);
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}