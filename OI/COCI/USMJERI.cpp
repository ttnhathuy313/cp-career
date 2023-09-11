#include <bits/stdc++.h>

/*
	Things need to accomplish : 
	- Finding LCA : done
	- Have time_in, time_out : done
	- Decompose into components of demands from predec to ancestor : done
	- Bipartiting
*/

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 3e5 + 5, MOD = 1e9 + 7, lg = 26;
int n, m, d[N], tin[N], tout[N], P[N][lg], x[N], y[N], dfsTime, par[2 * N];
vector <int> adj[N];
bool inGraph[N * 2]; // Create a new graph, with nodes are edges and the compenents, they has edges if both points to the same direction
bool taken[N * 4];

void prepare(int u, int pre) {
	tin[u] = ++dfsTime;
	if (~pre) d[u] = d[pre] + 1;
	for (int v : adj[u]) {
		if (v == pre) continue;
		P[v][0] = u;
		prepare(v, u);
	}
	tout[u] = ++dfsTime;
}

int lca(int u, int v, ii &tw) {
	bool swapped = false;
	if (d[v] > d[u]) {
		swapped = true;
		swap(u, v);
	}
	for (int i = lg - 1; i >= 0; --i) if ((1 << i) <= d[u] - d[v])
		u = P[u][i];
	if (u == v) return u;
	for (int i = lg - 1; i >= 0; --i) if ((1 << i) <= d[u] && P[u][i] != P[v][i])
		u = P[u][i], v = P[v][i];
	if (swapped) swap(u, v);
	tw.first = u, tw.second = v;
	return P[u][0];
}

struct dsu_t {
	int n;
	vector <int> lab, sz;
	dsu_t() {}
	dsu_t(int _n) {
		this -> n = _n;
		sz.assign(n + 5, 1);
		lab.assign(n + 5, -1);
	}
	int root(int x) {
		return lab[x] == -1 ? x : lab[x] = root(lab[x]);
	}
	void merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return;
		lab[y] = x;
		sz[x] += sz[y];
	}
};

int ops(int i) {
	if (i > 2 * n) return i - 2 * n;
	else return i + 2 * n;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("USMJERI.INP", "r", stdin);
	freopen("USMJERI.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i];
	}
	prepare(1, -1);
	for (int i = 1; i < lg; ++i) {
		for (int u = 1; u <= n; ++u) {
			P[u][i] = P[P[u][i - 1]][i - 1];
		}
	}
	dsu_t one = dsu_t(n);
	for (int i = 1; i <= m; ++i) {
		int u = x[i], v = y[i];
		if (tin[u] > tin[v]) swap(u, v);
		if (!(tin[u] < tin[v] && tout[u] > tout[v])) continue;
		u = one.root(u), v = one.root(v);
		while (v != u) {
			// if (v == u) continue;
			one.merge(P[v][0], v);
			v = one.root(P[v][0]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		// cerr << "At " << i << ": " << one.root(i) << endl;
		if (one.root(i) == i) {
			inGraph[i] = 1;
			inGraph[i + n] = 1;
			par[i] = i + n;
			par[i + n] = one.root(P[i][0]);
			if (one.root(P[i][0]) == 1) cerr << i << endl;
		}
	}
	dsu_t two = dsu_t(4 * n);
	for (int i = 1; i <= m; ++i) if (x[i] != y[i]) {
		int u = x[i], v = y[i];
		if (tin[u] > tin[v]) swap(u, v);
		if (tin[u] < tin[v] && tout[u] > tout[v]) continue;
		ii d;
		int uv = lca(u, v, d);
		if (d.first != one.root(d.first)) d.first = one.root(d.first);
		else d.first = one.root(d.first) + n;
		if (d.second != one.root(d.second)) d.second = one.root(d.second);
		else d.second = one.root(d.second) + n;
		if (d.first == d.second) {
			cout << 0 << endl;
			return 0;
		}
		if (u != one.root(u)) {
			u = one.root(u);
		} else u = one.root(u) + n;
		if (v != one.root(v)) {
			v = one.root(v);
		} else v = one.root(v) + n;

		while (u != d.first) {
			int pre = two.root(par[u]);
			if (pre == 0) {
				break;
			}
			two.merge(pre, u);
			two.merge(pre + n * 2, u + 2 * n);
			u = pre;
		}
		while (v != d.second) {
			int pre = two.root(par[v]);
			if (pre == 0) break;
			two.merge(pre, v);
			two.merge(pre + n * 2, v + 2 * n);
			v = pre;
		}		
	}
	for (int i = 1; i <= m; ++i) if (x[i] != y[i]) {
		int u = x[i], v = y[i];
		if (tin[u] > tin[v]) swap(u, v);
		if (tin[u] < tin[v] && tout[u] > tout[v]) continue;
		ii d;
		int uv = lca(u, v, d);
		if (d.first != one.root(d.first)) d.first = one.root(d.first);
		else d.first = one.root(d.first) + n;
		if (d.second != one.root(d.second)) d.second = one.root(d.second);
		else d.second = one.root(d.second) + n;
		two.merge(d.second + 2 * n, d.first);
		two.merge(d.first + 2 * n, d.second);

	}
	for (int i = 1; i <= 2 * n; ++i) if (inGraph[i] && two.root(i) == two.root(i + 2 * n)) {
		cout << 0 << endl;
		return 0;
	}
	int res = 1;
	for (int i = 1; i <= 4 * n; ++i) if (inGraph[i > 2 * n ? i - 2 * n : i] && two.root(i) == i) {
		if (i == n + 1 || i == 3 * n + 1) continue;
		inGraph[i > 2 * n ? i - 2 * n : i] = 0;
		int u = i > 2 * n ? i - 2 * n : i;
		if (u <= n && two.sz[u] == 1 && one.sz[u] == 1) continue;
		if (taken[two.root(ops(i))]) continue;
		taken[i] = 1;
		if (u > n) u -= n, u *= -1;
		res = (res * 2) % MOD;
	}
	cout << res << endl;

	return 0;
}