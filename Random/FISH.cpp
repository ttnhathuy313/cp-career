#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, m, q, a[N], dep[N], par[N], pos[N], chainID[N], nchain, thutu, head[N], vertex[N], subSize[N];
int tin[N], tout[N], dfsTime;
vector <int> adj[N];

void prepare(int u, int pre) {
	subSize[u] = 1;
	tin[u] = ++dfsTime;
	for (int v : adj[u]) {
		if (v == pre) continue;
		dep[v] = dep[u] + 1;
		par[v] = u;
		prepare(v, u);
		subSize[u] += subSize[v];
	}
	tout[u] = ++dfsTime;
}

void HLD(int u, int pre) {
	pos[u] = ++thutu;
	vertex[thutu] = u;
	if (!chainID[u]) 
		chainID[u] = ++nchain, head[nchain] = u;
	int maxSz = 0, bigChild = -1;
	for (int v : adj[u]) {
		if (v == pre) continue;
		if (subSize[v] > maxSz) {
			maxSz = subSize[v];
			bigChild = v;
		}
	}
	if (~bigChild) {
		chainID[bigChild] = nchain;
		HLD(bigChild, u);
	}
	for (int v : adj[u]) {
		if (v == pre || v == bigChild) continue;
		HLD(v, u);
	}
}

struct Node {
	int sum, mx, cnt, lazy;
	Node() {}
	Node(int _sum, int _mx, int _cnt, int lz) : sum(_sum), mx(_mx), cnt(_cnt), lazy(lz) {}
};

Node combine(Node A, Node B) {
	Node ret; 
	ret.sum = A.sum + B.sum;
	ret.mx = max(A.mx, B.mx);
	ret.cnt = A.cnt + B.cnt;
	ret.lazy = 0;
	return ret;
}

struct SegmentTree {
	int n;
	vector <Node> st;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, Node(0, 0, 0, 0));
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}
	void build(int id, int L, int R) {
		if (L == R) {
			if (a[vertex[L]] == m) {
				st[id] = Node(m, -1, 1, 0);
			} else st[id] = Node(a[vertex[L]], a[vertex[L]], 0, 0);
			return;
		}
		int mid = (L + R) >> 1;
		build(Left(id), L, mid);
		build(Right(id), mid + 1, R);
		st[id] = combine(st[Left(id)], st[Right(id)]);
	}
	void push(int id, int L, int R) {
		int mid = (L + R) >> 1;
		if (~st[Left(id)].mx) {
			st[Left(id)].mx += st[id].lazy;
			st[Left(id)].sum += (mid - L + 1 - st[Left(id)].cnt) * st[id].lazy;
			st[Left(id)].lazy += st[id].lazy;
		}
		if (~st[Right(id)].mx) {
			st[Right(id)].mx += st[id].lazy;
			st[Right(id)].sum += (R - mid - st[Right(id)].cnt) * st[id].lazy;
			st[Right(id)].lazy += st[id].lazy;
		}
		st[id].lazy = 0;
	}
	void update(int id, int L, int R, int i, int j, int val) {
		if (L > j || R < i) return;
		if (L >= i && R <= j) {
			st[id].mx += val;
			st[id].sum += (R - L + 1 - st[id].cnt) * val;
			st[id].lazy += val;
			return;
		}
		int mid = (L + R) >> 1;
		push(id, L, R);
		update(Left(id), L, mid, i, j, val);
		update(Right(id), mid + 1, R, i, j, val);
		st[id] = combine(st[Left(id)], st[Right(id)]);
	}
	int query(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return 0;
		if (L >= i && R <= j) {
			return st[id].sum;
		}
		int mid = (L + R) >> 1;
		push(id, L, R);
		int ret = query(Left(id), L, mid, i, j) + query(Right(id), mid + 1, R, i, j);
		st[id] = combine(st[Left(id)], st[Right(id)]);
		return ret;
	}
	void recorrect(int id, int L, int R) {
		if (st[id].mx < m) return;
		if (L == R) {
			st[id].mx = -1;
			st[id].sum = m;
			st[id].cnt = 1;
			return;
		}
		int mid = (L + R) >> 1;
		push(id, L, R);
		recorrect(Left(id), L, mid);
		recorrect(Right(id), mid + 1, R);
		st[id] = combine(st[Left(id)], st[Right(id)]);
	}
	void update(int i, int j, int val) {
		update(1, 1, n, i, j, val);
		recorrect(1, 1, n);
	}
	int get(int i, int j) {
		return query(1, 1, n, i, j);
	}
} Solver;

void upd(int u, int v, int x) {
	for (; chainID[u] != chainID[v]; v = par[head[chainID[v]]]) {
		if (dep[head[chainID[u]]] > dep[head[chainID[v]]]) swap(u, v);
		Solver.update(pos[head[chainID[v]]], pos[v], x);
	}
	if (tin[u] > tin[v]) swap(u, v);
	Solver.update(pos[u], pos[v], x);
}

int bruh(int u, int v) {
	int ret = 0;
	for (; chainID[u] != chainID[v]; v = par[head[chainID[v]]]) {
		if (dep[head[chainID[u]]] > dep[head[chainID[v]]]) swap(u, v);
		ret += Solver.get(pos[head[chainID[v]]], pos[v]);
	}
	if (tin[u] > tin[v]) swap(u, v);
 	ret += Solver.get(pos[u], pos[v]);
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("FISH.INP", "r", stdin);
	freopen("FISH.OUT", "w", stdout);

	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	prepare(1, -1);
	HLD(1, -1);
	// for (int i = 1; i <= thutu; ++i) {
	// 	cerr << vertex[i] << ' ';
	// } cerr << endl;
	Solver = SegmentTree(n);
	Solver.build(1, 1, n);
	for (int i = 1; i <= q; ++i) {
		int type, u, v;
		cin >> type >> u >> v;
		if (tin[u] > tin[v]) swap(u, v);
		if (type == 0) {
			int x;
			cin >> x;
			upd(u, v, x);
		} else {
			cout << bruh(u, v) << endl;
		}
	}

	return 0;
}