#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5, LOG = 18;
int n, P[N][LOG], X, Y, W, q, h[N], dp[N];
vector <ii> adj[N];

struct dsu_t {
	int n;
	vector <int> lab;
	dsu_t() {}
	dsu_t(int _n) {
		this -> n = _n;
		lab.assign(n + 5, -1);
	}
	int root(int x) {
		return lab[x] == -1 ? x : lab[x] = root(lab[x]);
	}
	bool merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return false;
		lab[x] = y;
		return true;
	}
};

void dfs(int u, int pre) {
	for (ii v : adj[u]) {
		if (v.first == pre) continue;
		P[v.first][0] = u;
		h[v.first] = h[u] + 1;
		dp[v.first] = dp[u] + v.second;
		dfs(v.first, u);
	}
}

int LCA(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	for (int j = LOG - 1; j >= 0; --j) if ((1 << j) <= h[u] - h[v]) {
		u = P[u][j];
	}
	if (u == v) return u;
	for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= h[u] && P[u][i] != P[v][i]) {
		u = P[u][i];
		v = P[v][i];
	}
	return P[u][0];
}

int path(int u, int v) {
	int x = LCA(u, v);
	return dp[u] + dp[v] - 2 * dp[x];
}

void re_init() {
	for (int i = 1; i <= n; ++i) {
		dp[i] = h[i] = 0;
		adj[i].clear();
		for (int j = 0; j < LOG; ++j)
			P[i][j] = -1;
	}
}

void solve() {
	cin >> n >> q;
	re_init();
	dsu_t dsu = dsu_t(n);
	for (int i = 1; i <= n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		if (!dsu.merge(u, v)) {
			X = u, Y = v; W = w;
		} else {
			adj[v].push_back({u, w});
			adj[u].push_back({v, w});
		}
	}
	dfs(1, -1);
	for (int i = 1; i < LOG; ++i) {
		for (int u = 1; u <= n; ++u) if ((1 << i) <= h[u]) {
			P[u][i] = P[P[u][i - 1]][i - 1];
		}
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		int res = path(u, v);
		res = min(res, path(u, X) + W + path(Y, v));
		res = min(res, path(u, Y) + W + path(X, v));
		cout << res << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskK.INP", "r", stdin);
	freopen("TaskK.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}