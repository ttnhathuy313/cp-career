#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
typedef pair <int, int> ii;

struct Node {
	int lazy, sum;
};

struct SegmentTree {
	vector <Node> st;
	int n;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, {0, 0});
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}

	void push(int id, int L, int R) {
		int mid = (L + R) >> 1;
		st[Left(id)].lazy += st[id].lazy;
		st[Left(id)].sum += st[id].lazy * (mid - L + 1);
		st[Right(id)].lazy += st[id].lazy;
		st[Right(id)].sum += st[id].lazy * (R - mid);
		st[id].lazy = 0;
	}

	void update(int id, int L, int R, int i, int j, int val) {
		if (L > j || R < i) return;
		if (L >= i && R <= j) {
			st[id].sum += (R - L + 1) * val;
			st[id].lazy += val;
			return;
		}
		int mid = (L + R) >> 1;
		push(id, L, R);
		update(Left(id), L, mid, i, j, val);
		update(Right(id), mid + 1, R, i, j, val);
		st[id].sum = st[Left(id)].sum + st[Right(id)].sum;
	}

	int query(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return 0;
		if (L >= i && R <= j) return st[id].sum;
		int mid = (L + R) >> 1;
		push(id, L, R);
		return query(Left(id), L, mid, i, j) + query(Right(id), mid + 1, R, i, j);
	}

	void update(int i, int j, int val) {
		update(1, 1, n, i, j, val);
	}
	int get(int l, int r) {
		return query(1, 1, n, l, r);
	}
};

const int N = 1e5 + 5, LOG = 22;
int n, q, a[N], tin[N], tout[N], dfsTime, P[N][LOG], d[N];
vector <int> adj[N];

void dfs(int u, int pre) {
	tin[u] = ++dfsTime;
	if (pre != -1) d[u] = d[pre] + 1;
	P[u][0] = pre;
	for (int i = 1; i <= LOG; ++i) if ((1 << i) <= d[u])
		P[u][i] = P[P[u][i - 1]][i - 1];
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
	}
	tout[u] = ++dfsTime;
}

int LCA(int u, int v) {
	if (d[u] < d[v]) swap(u, v);
	for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= d[u] - d[v])
		u = P[u][i];
	if (u == v) return v;
	for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= d[u] && P[u][i] != P[v][i])
		u = P[u][i], v = P[v][i];
	return P[u][0];
}

ii lmao(int u, int v) {
	if (d[u] < d[v]) swap(u, v);
	for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= d[u] - d[v])
		u = P[u][i];
	if (u == v) return {u, u};
	for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= d[u] && P[u][i] != P[v][i])
		u = P[u][i], v = P[v][i];
	return {u, v};
}

int climb(int u, int dep) {
	for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= dep) {
		dep -= (1 << i);
		u = P[u][i];
	}
	return u;
}

int dist(int a, int b) {
	int f = LCA(a, b);
	return d[a] + d[b] - 2 * d[f];
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
 		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1); 
	SegmentTree IT(2 * n);
	for (int i = 1; i <= n; ++i) {
		IT.update(tin[i], tin[i], a[i]);
		IT.update(tout[i], tout[i], a[i]);
	}
	int root = 1;
	for (int i = 1; i <= q; ++i) {
		int type;
		cin >> type;
		if (type == 1) {
			int v;
			cin >> v;
			root = v;
		} else if (type == 2) {
			int u, v, x;
			cin >> u >> v >> x;
			int lca = LCA(u, v), len = dist(u, v);
			int ur = dist(u, root), vr = dist(v, root);
			if (ur + vr - 2 * dist(lca, root) == len) {
				if (lca == root) {
					IT.update(1, 2 * n, x);
					continue;
				}
				if (tin[lca] <= tin[root] && tout[root] <= tout[lca]) {
					int z = root;
					for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= d[z] - d[lca] - 1)
						z = P[z][i];
					IT.update(1, 2 * n, x);
					IT.update(tin[z], tout[z], -x);
					continue;
				}
				IT.update(tin[lca], tout[lca], x);
			} else if (ur + vr == len) {
				IT.update(1, 2 * n, x);
			} else {
				int z = LCA(u, root);
				if (ur + vr - 2 * dist(z, root) == len) {
					int pp = climb(root, d[root] - d[z] - 1);
					// if (i == 2) cerr << "lmao " << pp << endl;
					IT.update(1, 2 * n, x);
					IT.update(tin[pp], tout[pp], -x);
					continue;
				}
				z = LCA(v, root);
				if (ur + vr - 2 * dist(z, root) == len) {
					int pp = climb(root, d[root] - d[z] - 1);
					IT.update(1, 2 * n, x);
					IT.update(tin[pp], tout[pp], -x);
					continue;
				}
			}
		} else {
			int v;
			cin >> v;
			if (v == root) {
				cout << IT.get(1, 2 * n) / 2 << endl;
				continue;
			}
			if (tin[v] <= tin[root] && tout[root] <= tout[v]) {
				int z = root;
				for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= d[z] - d[v] - 1)
					z = P[z][i];
				cout << (IT.get(1, 2 * n) - IT.get(tin[z], tout[z])) / 2 << endl;
				continue;
			}
			cout << IT.get(tin[v], tout[v]) / 2 << endl;
		}
	}

	return 0;
}