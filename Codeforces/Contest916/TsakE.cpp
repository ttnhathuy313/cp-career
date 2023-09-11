#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

struct Node {
	int lazy, sum;
}

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

	void push(int id) {
		st[Left(id)].lazy += st[id].lazy;
		st[Left(id)].sum += st[id].lazy;
		st[Right(id)].lazy += st[id].lazy;
		st[Right(id)].sum += st[id].lazy;
		st[id].lazy = 0;
	}

	void update(int id, int L, int R, int i, int j, int val) {
		if (L > j || R < i) return;
		if (L >= i && R <= j) {
			st[id].sum += val;
			st[id].lazy += val;
			return;
		}
		int mid = (L + R) >> 1;
		push(id);
		update(Left(id), L, mid, i, j, val);
		update(Right(id), mid + 1, R, i, j, val);
		st[id].sum = st[Left(id)].sum + st[Right(id)].sum;
	}

	int query(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return 0;
		if (L >= i && R <= j) return st[id].sum;
		int mid = (L + R) >> 1;
		push(id);
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

int dist(int a, int b) {
	int f = LCA(a, b);
	return d[a] + d[b] - 2 * d[f];
}

int main(int argc, char const *argv[])
{
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
			if (ur + vr - 2 * dist(lca, x) == len) {
				IT.update(tin[u], tout[u], x);
			} else if (ur + vr == len) {
				IT.update(1, 2 * n, x);
			} else {
				int z = LCA(u, root);
				if (ur + vr - 2 * dist(z, x) == len) {
					ii A = lmao(u, root);
					if (tin[A.second] < tin[root] && tout[root] < tout[A.second])
						swap(A.second, A.first);
					IT.update(1, 2 * n, x);
					IT.update(tin[A.first], tout[A.first], -x);
				}
			}
		} else {
			int v;
			cin >> v;
			cout << IT.query(tin[v], tout[v]) / 2 << endl;
		}
	}

	return 0;
}