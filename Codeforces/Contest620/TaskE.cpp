#include <bits/stdc++.h>

using namespace std;
#define int long long

struct Node {
	int val, lazy;
	bool tag;
};

struct SegmentTree {
	vector <Node> st;
	int n;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, {0, 0, 0});
	}

	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}

	void push(int id) {
		st[Left(id)].tag = true;
		st[Left(id)].val = st[Left(id)].lazy = st[id].lazy;
		st[Right(id)].tag = true;
		st[Right(id)].val = st[Right(id)].lazy = st[id].lazy;
		st[id].tag = false;
	}

	void update(int id, int L, int R, int i, int j, int val) {
		if (L > j || R < i) return;
		if (L >= i && R <= j) {
			st[id].tag = true;
			st[id].val = st[id].lazy = (1LL << val);
			return;
		}
		int mid = (L + R) >> 1;
		if (st[id].tag) push(id);
		update(Left(id), L, mid, i, j, val);
		update(Right(id), mid + 1, R, i, j, val);
		st[id].val = st[Left(id)].val | st[Right(id)].val;
	}
	int query(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return 0;
		if (L >= i && R <= j)
			return st[id].val;
		int mid = (L + R) >> 1;
		if (st[id].tag) push(id);
		return query(Left(id), L, mid, i, j) | query(Right(id), mid + 1, R, i, j);
	}
	int get(int l, int r) {
		return __builtin_popcountll(query(1, 1, n, l, r));
	}
	void update(int i, int j, int val) {
		update(1, 1, n, i, j, val);
	}
};

const int N = 4e5 + 5;
int n, m, c[N], dfsTime, tin[N], tout[N];
vector <int> adj[N];

void dfs(int u, int pre) {
	tin[u] = ++dfsTime;
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
	}
	tout[u] = ++dfsTime;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	SegmentTree IT(dfsTime);
	for (int i = 1; i <= n; ++i)
		IT.update(tin[i], tin[i], c[i]);
	for (int i = 1; i <= m; ++i) {
		int type;
		cin >> type;
		if (type == 1) {
			int v, d;
			cin >> v >> d;
			IT.update(tin[v], tout[v], d);
		} else {
			int v;
			cin >> v;
			cout << IT.get(tin[v], tout[v]) << endl;
		}
	}

	return 0;
}