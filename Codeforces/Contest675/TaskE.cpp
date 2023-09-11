#include <bits/stdc++.h>

using namespace std;
#define int long long

struct SegmentTree {
	vector <pair <int, int> > st;
	int n;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.resize(4 * n + 5);
		for (int i = 0; i < 4 * n + 5; ++i) st[i] = make_pair(0, 0);
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}

	void update(int id, int L, int R, int i, int val) {
		if (L > i || R < i) return;
		if (L == R) {
			st[id] = make_pair(val, i);
			return;
		} else {
			int mid = (L + R) >> 1;
			update(Left(id), L, mid, i, val);
			update(Right(id), mid + 1, R, i, val);
			st[id] = max(st[Left(id)], st[Right(id)]);
		}
	}

	pair <int, int> query(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return make_pair(0, 0);
		if (L >= i && R <= j) return st[id];
		int mid = (L + R) >> 1;
		return max(query(Left(id), L, mid, i, j), query(Right(id), mid + 1, R, i, j));
	}

	void update(int i, int val) {update(1, 1, n, i, val);}
	int query(int i, int j) {
		return query(1, 1, n, i, j).second;
	}

	void printTree(int id, int L, int R) {
		cerr << "[" << L << ", " << R << "] : " << st[id].first << endl;
		if (L != R) {
			int mid = (L + R) >> 1;
			printTree(Left(id), L, mid);
			printTree(Right(id), mid + 1, R);
		}
	}
};

const int N = 1e5 + 5;
int a[N], n, dp[N];

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);

	cin >> n;
	SegmentTree IT(n);
	for (int i = 1; i <= n - 1; ++i) {
		cin >> a[i];
		IT.update(i, a[i]);
	}
	int res = 0;
	for (int i = n - 1; i >= 1; --i) {
		int id = IT.query(i + 1, a[i]);
		if (a[id] > a[i]) dp[i] = n - a[i] + id - i + dp[id];
		else dp[i] = a[i] - i + dp[a[i]] + n - a[i];
		res += dp[i];
	}
	cout << res << endl;

	return 0;
}