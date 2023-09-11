#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int a[N];

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
			st[id] = max(st[id], val);
			return;
		}
		int mid = (L + R) >> 1;
		update(Left(id), L, mid, i, val);
		update(Right(id), mid + 1, R, i, val);
		st[id] = max(st[Left(id)], st[Right(id)]);
	}

	int get(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return 0;
		if (L >= i && R <= j) return st[id];
		int mid = (L + R) >> 1;
		return max(get(Left(id), L, mid, i, j), get(Right(id), mid + 1, R, i, j));
	}

	void update(int i, int val) {
		update(1, 1, n, i, val);
	}
	int get(int i, int j) {
		return get(1, 1, n, i, j);
	}
} IT1, IT2;

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		IT1 = SegmentTree(n); IT2 = SegmentTree(n);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			IT1.update(i, a[i]);
		}
		int m;
		cin >> m;
		for (int i = 1; i <= m; ++i) {
			int p, s;
			cin >> p >> s;
			IT2.update(s, p);
		}
		int i = 1;
		bool fucoff = false;
		int res = 0;
		while (i <= n) {
			int l = i, r = n, ans = -1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				int mx = IT1.get(i, mid);
				if (IT2.get(mid - i + 1, n) >= mx) {
					l = mid + 1;
					ans = mid;
				} else r = mid - 1;
			}
			if (ans == -1) fucoff = true;
			if (fucoff) break;
			res++;
			i = ans + 1;
		}
		if (fucoff) {
			cout << -1 << endl;
		} else cout << res << endl;
	}

	return 0;
}	