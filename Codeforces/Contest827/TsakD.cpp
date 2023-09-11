#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int N = 2e5 + 5, LOG = 22;
int n, m, inTree[N], P[N][LOG], mi[N][LOG], mx[N][LOG], d[N], ans[N];
vector <ii> adj[N];
vector <iii> E;

struct dsu_t {
	int n;
	vector <int> lab, Rank;
	dsu_t() {}
	dsu_t(int _n) {
		this -> n = _n;
		lab.assign(n + 5, -1);
		Rank.assign(n + 5, 1);
	}
	int root(int x) {
		return (lab[x] == -1 ? x : lab[x] = root(lab[x]));
	}
	bool merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return false;
		if (Rank[x] < Rank[y]) swap(x, y);
		lab[y] = x;
		Rank[x] += (Rank[x] == Rank[y]);
		return true;
	}
};

void dfs(int u, int pre) {
	if (~pre) {
		P[u][0] = pre;
		d[u] = d[pre] + 1;
	}
	for (int i = 0; i < LOG; ++i) if ((1 << i) <= d[u]) {
		P[u][i] = P[P[u][i - 1]][i - 1];
		mx[u][i] = max(mx[u][i - 1], mx[P[u][i - 1]][i - 1]);
	}
	for (ii v : adj[u]) {
		if (v.first == pre) continue;
		mx[v.first][0] = v.second;
		dfs(v.first, u);
	}
}

int lca(int u, int v, int value) {
	int ret = 0;
	if (d[u] < d[v]) swap(u, v);
	for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= d[u] - d[v]) {
		mi[u][i] = min(mi[u][i], value);
		ret = max(ret, mx[u][i]);
		u = P[u][i];
	}
	if (u == v) return ret;
	for (int i = LOG - 1; i >= 0; --i) if (P[u][i] != P[v][i]) {
		mi[u][i] = min(mi[u][i], value);
		mi[v][i] = min(mi[v][i], value);
		ret = max(ret, max(mx[u][i], mx[v][i]));
		u = P[u][i], v = P[v][i];
	}
	mi[u][0] = min(mi[u][0], value);
	mi[v][0] = min(mi[v][0], value);
	ret = max(ret, max(mx[u][0], mx[v][0]));
	return ret;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		E.push_back({c, {u, v}});
	}
	dsu_t dsu = dsu_t(n);
	sort(E.begin(), E.end());
	int i = 0;
	for (iii e : E) {
		int u = e.second.first, v = e.second.second;
		if (dsu.merge(u, v)) {
			adj[u].push_back({v, e.first});
			adj[v].push_back({u, e.first});
			inTree[i] = 1;
		}
		i++;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < LOG; ++j)
			mi[i][j] = (int)1e9;
	}
	dfs(1, -1);

	for (int i = 0; i < m; ++i) if (!inTree[i]) {
		ans[i] = lca(E[i].second.first, E[i].second.second, E[i].first) - 1;
	}
	for (int i = LOG - 1; i > 0; --i) {
		for (int u = 1; u <= n; ++u) {
			mi[u][i - 1] = min(mi[u][i - 1], mi[u][i]);
			mi[P[u][i - 1]][i - 1] = min(mi[P[u][i - 1]][i - 1], mi[u][i]);
		}
	}
	i = 0;
	for (iii &e : E) {
		if (!inTree[i]) continue;
		if (d[e.second.first] > d[e.second.second]) swap(e.second.first, e.second.second);
		ans[i] = mi[e.second.second][0] - 1;
		i++;
	}
	for (int i = 0; i < m; ++i)
		cout << ans[i] << ' ';

	return 0;
}