#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
const int oo = 1e18;

struct Node {
	int v1, id1, v2, id2;
};

Node combine(Node a, Node b) {
	Node ret;
	ret.v1 = max(a.v1, b.v1), ret.id1 = (a.v1 > b.v1 ? a.id1 : b.id1);
	if (a.v1 > b.v1) a.v1 = a.v2, a.id1 = a.id2; else b.v1 = b.v2, b.id1 = b.id2;
	ret.v2 = max(a.v1, b.v1), ret.id2 = (a.v1 > b.v1 ? a.id1 : b.id1);
	return ret;
}

struct SegmentTree {
	int n;
	vector <Node> st;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n + 5;
		st.assign(4 * n + 5, {-oo, 0, -oo, 0});
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}

	void update(int id, int L, int R, int i, int val) {
		if (L > i || R < i) return;
		if (L == R) {
			st[id].v1 = val;
			st[id].id1 = L;
			return;
		}
		int mid = (L + R) >> 1;
		update(Left(id), L, mid, i, val);
		update(Right(id), mid + 1, R, i, val);
		st[id] = combine(st[Left(id)], st[Right(id)]);
	}

	Node get(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return {-oo, 0, -oo, 0};
		if (L >= i && R <= j) {
			return st[id];
		}
		int mid = (L + R) >> 1;
		return combine(get(Left(id), L, mid, i, j), get(Right(id), mid + 1, R, i, j));
	}

	void update(int id, int val) {
		update(1, 1, n, id, val);
	}

	Node get(int i, int j) {
		return get(1, 1, n, i, j);
	}
} S1, S2;

const int N = 3e5 + 5;
int n, q, d[N], h[N], p[N];

int solve(int l, int r) {
	Node x = S1.get(l, r), y = S2.get(l, r);
	if (x.id1 != y.id1) {
		return x.v1 + y.v1;
	} else {
		return max(x.v1 + y.v2, x.v2 + y.v1);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("MONKEY.INP", "r", stdin);
	// freopen("MONKEY.OUT", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
		d[i + n] = d[i];
	}
	for (int i = 1; i <= 2 * n; ++i) {
		p[i] = p[i - 1] + d[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
		h[n + i] = h[i];
	}
	S1 = SegmentTree(2 * n); S2 = SegmentTree(2 * n);
	for (int i = 1; i <= 2 * n; ++i) {
		S1.update(i, -p[i - 1] + 2 * h[i]);
	}
	for (int i = 1; i <= 2 * n; ++i) {
		S2.update(i, p[i - 1] + 2 * h[i]);
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (r < l) {
			cout << solve(r + 1, l - 1) << endl;
		} else {
			cout << max(solve(1, l - 1), solve(r + 1, l - 1 + n)) << endl;
		}
	}

	return 0;
}