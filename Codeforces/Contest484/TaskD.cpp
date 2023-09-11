#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;

struct Node {
	int mx, plus;
	Node() {}
	Node(int _mi, int _plus) : mx(_mi), plus(_plus) {}
};

struct SegmentTree {
	vector <Node> st;
	int n;
	bool print;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.resize(4 * n + 5);
		for (int i = 0; i <= 4 * n + 4; ++i) st[i] = Node(0, 0);
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}

	void push(int id) {
		st[Left(id)].mx += st[id].plus;
		st[Left(id)].plus += st[id].plus;
		st[Right(id)].mx += st[id].plus;
		st[Right(id)].plus += st[id].plus;
		st[id].plus = 0;
	}

	void update(int id, int L, int R, int i, int j, int val) {
		if (L > j || R < i) return;
		if (L >= i && R <= j) {
			st[id].mx += val;
			st[id].plus += val;
			return;
		}
		int mid = (L + R) >> 1;
		push(id);
		update(Left(id), L, mid, i, j, val); update(Right(id), mid + 1, R, i, j, val);
		st[id].mx = max(st[Left(id)].mx, st[Right(id)].mx);
	}

	int get(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return 0;
		if (L >= i && R <= j) {
			return st[id].mx;
		}
		int mid = (L + R) >> 1;
		push(id);
		return max(get(Left(id), L, mid, i, j), get(Right(id), mid + 1, R, i, j));
	}

	int get(int i, int j) {
		if (i > j) return 0;
		return get(1, 1, n, i, j);
	}
	void update(int i, int j, int val) {
		if (i > j) return;
		update(1, 1, n, i, j, val);
	}
} IT;

const int N = 1e6 + 5;
int a[N], dp[N], n;
stack <int> mi, mx;

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	IT = SegmentTree(n);
	int res = 0;
	mx.push(0); mi.push(0);
	for (int i = 1; i <= n; ++i) {
		while (mx.size() > 1 && a[mx.top()] < a[i]) {
			int cur = mx.top(); mx.pop();
			IT.update(mx.top() + 1, cur, a[i] - a[cur]);
		}
		while (mi.size() > 1 && a[mi.top()] > a[i]) {
			int cur = mi.top(); mi.pop();
			IT.update(mi.top() + 1, cur, a[cur] - a[i]);
		}
		mi.push(i); mx.push(i);
		IT.update(i, i, dp[i - 1]);
		dp[i] = IT.get(1, i);
		res = max(res, dp[i]);
	}
	cout << res << endl;

	return 0;
}