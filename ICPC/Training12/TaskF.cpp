#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1005, MOD = 998244353;
int t[N][N], n, s[N], m, a[N], mark[N];
vector <int> topo, adj[N], radj[N];

void init() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			t[i][j] = 0;
		}
		s[i] = 0;
		adj[i].clear();
		mark[i] = 0;
		radj[i].clear();
	}
	topo.clear();
}

void dfs(int u) {
	mark[u] = 1;
	for (int v : adj[u]) {
		if (!mark[v]) {
			dfs(v);
		}
	}
	topo.push_back(u);
}

void solve() {
	cin >> n >> m;
	init();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = t[i][0] = a[i];
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) if (!mark[i]) {
		dfs(i);
	}
	// for (int u : topo) {
	// 	cerr << u << ' ';
	// }
	// cerr << endl;
	reverse(topo.begin(), topo.end());
	for (int u : topo) {
		for (int v : radj[u]) {
			s[u] = (s[u] + s[v]) % MOD;
		}
		for (int j = 1; j <= m; ++j) {
			t[u][j] = t[u][j - 1] - (t[u][j - 1] > 0);
			for (int v : radj[u]) {
				t[u][j] += (t[v][j - 1] > 0);
			}
		}
	}
	int dest = topo[topo.size() - 1];
	int res = s[dest];
	for (int j = 0; j <= m; ++j) {
		bool pos = false;
		for (int i = 1; i <= n; ++i) if (i != dest && t[i][j] != 0)
			pos = true;
		if (pos && t[dest][j] == 0) {
			res++;
		}
	}
	res %= MOD;
	cout << res << endl;
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