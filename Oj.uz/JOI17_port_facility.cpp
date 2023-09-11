#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e6 + 6, MOD = 1e9 + 7;
int n, a[N], b[N], id[2 * N], color[N];
bool mark[N];

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
	void update(int id, int L, int R, int i, int val) {
		if (L > i || R < i) return;
		if (L == R) {
			st[id] = val;
			return;
		}
		int mid = (L + R) >> 1;
		update(Left(id), L, mid, i, val);
		update(Right(id), mid + 1, R, i, val);
		st[id] = max(st[Left(id)], st[Right(id)]);
	}
	int get(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return 0;
		if (L >= i && R <= j)
			return st[id];
		int mid = (L + R) >> 1;
		return max(get(Left(id), L, mid, i, j), get(Right(id), mid + 1, R, i, j));
	}
	void update(int i, int val) {
		update(1, 1, n, i, val);
	}
	int get(int i, int j) {
		if (i > j) return 0;
		return get(1, 1, n, i, j);
	}
} solver, solver2;

struct IT {
	int n;
	vector <int> st;
	IT() {}
	IT(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, 0);
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}
	void update(int id, int L, int R, int i, int val) {
		if (L > i || R < i) return;
		if (L == R) {
			st[id] = val;
			return;
		}
		int mid = (L + R) >> 1;
		update(Left(id), L, mid, i, val);
		update(Right(id), mid + 1, R, i, val);
		st[id] = st[Left(id)] + st[Right(id)];
	}
	int get(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return 0;
		if (L >= i && R <= j)
			return st[id];
		int mid = (L + R) >> 1;
		return get(Left(id), L, mid, i, j) + get(Right(id), mid + 1, R, i, j);
	}
	void update(int i, int val) {
		update(1, 1, n, i, val);
	}
	int get(int i, int j) {
		if (i > j) return 0;
		return get(1, 1, n, i, j);
	}
} dem[2], anti[2];


void dfs(int u) {
	mark[u] = 1;
	if (dem[color[u]].get(a[u] + 1, b[u] - 1)) {
		cout << 0 << endl;
		exit(0);
	}
	while (1) {
		int val = solver.get(a[u] + 1, b[u] - 1);
		if (val < b[u]) break;
		int v = id[val];
		solver.update(a[v], 0);
		solver2.update(b[v], 0);
		color[v] = color[u] ^ 1;
		dem[color[v]].update(a[v], 1);
		anti[color[v]].update()
		dfs(v);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("JOI17_port_facility.INP", "r", stdin);
	freopen("JOI17_port_facility.OUT", "w", stdout);

	cin >> n;
	solver = SegmentTree(2 * n);
	dem[1] = IT(2 * n);
	dem[0] = IT(2 * n);
	anti[1] = IT(2 * n);
	anti[0] = IT(2 * n);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		solver.update(a[i], b[i]);
		id[b[i]] = i;
	}
	int cc = 0;
	for (int i = 1; i <= n; ++i) if (!mark[i]) {
		dfs(i);
		cc++;
	}
	int res = 1;
	while (cc--) {
		res = (res * 2) % MOD;
	}
	cout << res << endl;

	return 0;
}