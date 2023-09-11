#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

const int oo = 1e18;

struct Node {
	int ans, lsum, rsum, sum;
	Node() {}
	Node(int a, int b, int c, int d) : ans(a), lsum(b), rsum(c), sum(d) {}
};

Node combine(Node left, Node right) {
	if (left.sum == oo) return right;
	if (right.sum == oo) return left;
	Node ret;
	ret.sum = left.sum + right.sum;
	ret.ans = max(left.ans, right.ans);
	ret.ans = max(ret.ans, left.rsum + right.lsum);
	ret.lsum = max(left.lsum, left.sum + right.lsum);
	ret.rsum = max(right.rsum, left.rsum + right.sum);
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
	void add(int id, int L, int R, int i, int val) {
		if (L > i || R < i) return;
		if (L == R) {
			st[id].sum += val;
			st[id].lsum = max(0LL, st[id].sum);
			st[id].rsum = st[id].lsum;
			st[id].ans = max(0LL, st[id].sum);
			return;
		}
		int mid = (L + R) >> 1;
		add(Left(id), L, mid, i, val);
		add(Right(id), mid + 1, R, i, val);
		st[id] = combine(st[Left(id)], st[Right(id)]);
	}
	Node query(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return Node(oo, 0, 0, 0);
		if (L >= i && R <= j) {
			return st[id];
		}
		int mid = (L + R) >> 1;
		return combine(query(Left(id), L, mid, i, j), query(Right(id), mid + 1, R, i, j));
	}
	void add(int i, int j) {
		add(1, 1, n, i, j);
	}
	int query() {
		return st[1].ans;
	}
};

int n, m, k, d;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("ICESKATES.INP", "r", stdin);
	freopen("ICESKATES.OUT", "w", stdout);

	cin >> n >> m >> k >> d;
	SegmentTree Solver = SegmentTree(n);
	for (int i = 1; i <= n; ++i) {
		Solver.add(i, -k);
	}
	for (int i = 1; i <= m; ++i) {
		int r, x;
		cin >> r >> x;
		Solver.add(r, x);
		int v = Solver.query();
		if (v > k * d) {
			cout << "NIE" << endl;
		} else cout << "TAK" << endl;
	}

	return 0;
}