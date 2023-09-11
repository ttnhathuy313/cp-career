#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 7e4 + 5, LG = 22;
int n, P[N][LG], d[N], q, ans[N];
vector <int> adj[N];

void dfs(int u, int pre) {
	for (int v : adj[u]) {
		if (v == pre) continue;
		P[v][0] = u;
		d[v] = d[u] + 1;
		dfs(v, u);
	}
}

int LCA(int u, int v) {
	if (u == 0) return v;
	if (v == 0) return u;
	if (d[u] < d[v]) swap(u, v);
	for (int i = LG; i >= 0; --i) if ((1 << i) <= d[u] - d[v])
		u = P[u][i];
	if (u == v) return u;
	for (int i = LG; i >= 0; --i) if ((1 << i) <= d[u] && P[u][i] != P[v][i])
		u = P[u][i], v = P[v][i];
	return P[u][0];
}

struct SegmentTree {
	int n;
	vector <int> st;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, 0);
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}
	void build(int id, int L, int R) {
		if (L == R) {
			st[id] = L;
			return;
		}
		int mid = (L + R) >> 1;
		build(Left(id), L, mid);
		build(Right(id), mid + 1, R);
		st[id] = LCA(st[Left(id)], st[Right(id)]);
	}
	int get(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return 0;
		if (L >= i && R <= j) {
			return st[id];
		}
		int mid = (L + R) >> 1;
		return LCA(get(Left(id), L, mid, i, j), get(Right(id), mid + 1, R, i, j));
	}
	int get(int i, int j) {
		return get(1, 1, n, i, j);
	}
};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("VOTREE.INP", "r", stdin);
	freopen("VOTREE.OUT", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	for (int i = 1; i < LG; ++i) {
		for (int u = 1; u <= n; ++u) {
			P[u][i] = P[P[u][i - 1]][i - 1];
		}
	}
	SegmentTree Solver = SegmentTree(n);
	Solver.build(1, 1, n);
	for (int i = 1; i <= q; ++i) {
		int u, v;
		cin >> u >> v;
		cout << Solver.get(u, v) << endl;
	}

	return 0;
}