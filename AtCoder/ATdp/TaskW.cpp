#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 3e5 + 5, oo = 2e18;

struct SegmentTree {
	vector <int> st, lazy;
	int n;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, -oo);
		lazy.assign(4 * n + 5, 0);
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}

	void push(int id) {
		lazy[Left(id)] += lazy[id];
		st[Left(id)] += lazy[id];
		lazy[Right(id)] += lazy[id];
		st[Right(id)] += lazy[id];
		st[id] = max(st[Left(id)], st[Right(id)]);
		lazy[id] = 0;
	}

	void add(int id, int L, int R, int i, int j, int x) {
		if (L > j || R < i) return;
		if (L >= i && R <= j) {
			st[id] += x;
			lazy[id] += x;
			return;
		}
		int mid = (L + R) >> 1;
		push(id);
		add(Left(id), L, mid, i, j, x);
		add(Right(id), mid + 1, R, i, j, x);
		st[id] = max(st[Left(id)], st[Right(id)]);
	}

	int get(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return -oo;
		if (L >= i && R <= j)
			return st[id];
		int mid = (L + R) >> 1;
		push(id);
		int val = max(get(Left(id), L, mid, i, j), get(Right(id), mid + 1, R, i, j));
		st[id] = max(st[Left(id)], st[Right(id)]);
		return val;
	}

	void add(int i, int j, int x) {
		add(1, 1, n, i, j, x);
	}
	int get(int i, int j) {
		if (i > j) return 0;
		return get(1, 1, n, i, j);
	}
};

int n, m, sum[N];
vector <ii> endPoints[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskW.INP", "r", stdin);
	freopen("TaskW.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int l, r, a;
		cin >> l >> r >> a;
		sum[r] += a;
		endPoints[r].push_back({l, a});
	}
	SegmentTree IT = SegmentTree(n);
	for (int i = 1; i <= n; ++i) {
		int cur = IT.get(1, i - 1) + sum[i];
		for (ii v : endPoints[i]) {
			int j = v.first, val = v.second;
			if (j < i) IT.add(j, i - 1, val);
		}
		IT.add(i, i, cur + oo);
	}
	cout << max(0LL, IT.get(1, n)) << endl;

	return 0;
}