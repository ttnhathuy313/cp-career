#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, oo = 1e18;
int n, a[N], b[N], c[N], d[N], dp1[N], dp2[N], tot, bound;
unordered_map <int, int> inv;
set <int> val;

struct SegmentTree {
	int n;
	vector <int> st;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, oo);
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}
	void update(int id, int L, int R, int i, int val) {
		if (L > i || R < i) return;
		if (L == R) {
			st[id] = min(st[id], val);
			return;
		}
		int mid = (L + R) >> 1;
		update(Left(id), L, mid, i, val);
		update(Right(id), mid + 1, R, i, val);
		st[id] = min(st[Left(id)], st[Right(id)]);
	}
	int get(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return oo;
		if (L >= i && R <= j) {
			return st[id];
		}
		int mid = (L + R) >> 1;
		return min(get(Left(id), L, mid, i, j), get(Right(id), mid + 1, R, i, j));
	}
	void update(int i, int val) {
		update(1, 1, n, i, val);
	}
	int get(int i, int j) {
		return get(1, 1, n, i, j);
	}
};

void solve1() {
	SegmentTree solver = SegmentTree(tot);
	for (int i = 1; i <= n; ++i)
		dp1[i] = oo;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 1) {
			solver.update(inv[c[i]], d[i]);
			dp1[i] = d[i];
			continue;
		}
		int u = *(val.lower_bound(a[i]));
		auto it = val.upper_bound(b[i]);
		it--;
		int v = *it;
		dp1[i] = min(dp1[i], solver.get(inv[u], inv[v]) + d[i]);
		solver.update(inv[c[i]], solver.get(inv[u], inv[v]) + d[i]);
	}
}

void solve2() {
	SegmentTree solver = SegmentTree(tot);
	for (int i = 1; i <= n; ++i)
		dp2[i] = oo;
	for (int i = 1; i <= n; ++i) {
		if (b[i] == bound) {
			solver.update(inv[c[i]], d[i]);
			dp2[i] = d[i];
			continue;
		}
		int u = *(val.lower_bound(a[i]));
		auto it = val.upper_bound(b[i]);
		it--;
		int v = *it;
		dp2[i] = min(dp2[i], solver.get(inv[u], inv[v]) + d[i]);
		solver.update(inv[c[i]], solver.get(inv[u], inv[v]) + d[i]);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("JOI14_pinball.inp", "r", stdin);
	freopen("JOI14_pinball.out", "w", stdout);

	cin >> n >> bound;
	val.clear();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		val.insert(c[i]);
	}
	for (int v : val) {
		inv[v] = ++tot;
	}
	solve1();
	solve2();
	int res = oo;
	for (int i = 1; i <= n; ++i)
		res = min(res, dp1[i] + dp2[i] - d[i]);
	if (res == oo) res = -1;

	cout << res << endl;

	return 0;
}