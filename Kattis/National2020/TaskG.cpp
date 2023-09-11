#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5, LOG = 25;
int n, a[N], dist[N], tin[N], tout[N], dfsTime, depth[N], path[N], lg[N], V[N];
vector <int32_t> mp[N * 10], ver;
vector <ii> adj[N];
ii P[N][LOG];

void prepare(int u, int pre) {
	tin[u] = dfsTime++;
	ver.push_back(u);
	for (ii d : adj[u]) {
		int v = d.first;
		if (v == pre) continue;
		depth[v] = depth[u] + 1;
		path[v] = path[u] + d.second;
		prepare(v, u);
		ver.push_back(u);
		tout[u] = dfsTime;
		dfsTime++;
	}
	if (!tout[u]) {
		ver.push_back(u);
		tout[u] = dfsTime++;
	}
}

void prepare_lca() {
	for (int i = 0; i < ver.size() - 1; ++i) {
		P[i][0] = {depth[ver[i]], ver[i]};
		lg[i] = (int)log2(i);
	}
	for (int j = 1; j < LOG; ++j) {
		for (int i = 0; i < ver.size(); ++i) if (i + (1 << j) < ver.size()) {
			P[i][j] = min(P[i][j - 1], P[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int get_path(int u, int v) {
	if (u == v) return 0;
	int lca = -1;
	if (tin[u] > tin[v]) swap(u, v);
	if (tout[u] > tout[v]) lca = u;
	else {
		int len = tin[v] - tout[u]; // (tout[u], tin[v]);
		int j = lg[len];
		ii d = min(P[tout[u]][j], P[tin[v] - (1 << j)][j]);
		lca = d.second;
	}
	return path[u] + path[v] - 2 * path[lca];
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mp[a[i]].push_back(i);
	}
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	prepare(1, -1);
	prepare_lca();
	int res = 0, pt = 0;
	for (int gcd = 1; gcd <= (int)1e6; ++gcd) {
		pt = 0;
		for (int j = gcd; j <= (int)1e6; j += gcd) {
			for (int v : mp[j]) V[pt++] = v;
		}
		int len = 0, id;
		for (int i = 1; i < pt; ++i) {
			if (get_path(V[0], V[i]) > len) {
				len = get_path(V[0], V[i]);
				id = i;
			}
		}
		for (int i = 0; i < pt; ++i) {
			len = max(len, get_path(V[id], V[i]));
		}
		// cerr << gcd << ' ' << len << endl;
		res = max(res, len * gcd);
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	while (cin >> n && n) {
		solve();
	}

	return 0;
}