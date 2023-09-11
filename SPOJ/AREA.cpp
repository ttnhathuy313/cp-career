#include <bits/stdc++.h>

using namespace std;
#define int long long
struct obj {
	int cnt, len;
};
struct SegmentTree {
	int n;
	vector <obj> st;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.resize(4 * n + 5);
		for (int i = 0; i < 4 * n + 5; ++i)
			st[i] = {0, 0};
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}
	void add(int id, int L, int R, int i, int j, int type) {
		if (L > j ||  R < i) return;
		if (L >= i && R <= j) {
			st[id].cnt += type;
			if (type == 1) st[id].len = R - L + 1;
			else if (st[id].cnt == 0) {
				if (L == R) st[id].len = 0;
				else st[id].len = st[Left(id)].len + st[Right(id)].len;
			}
			return;
		}
		int mid = (L + R) >> 1;
		add(Left(id), L, mid, i, j, type);
		add(Right(id), mid + 1, R, i, j, type);
		if (st[id].cnt == 0 && L != R) st[id].len = st[Left(id)].len + st[Right(id)].len;
	}
	void add(int i, int j, int type) {
		if (i > j) return;
		add(1, 0, n, i, j, type);
	}
	int query() {
		return st[1].len;
	}
} Solver;

struct line {
	int y1, y2, x, type;
};
bool operator < (const line &a, const line &b) {
	if (a.x != b.x) return a.x < b.x;
	else {
		return a.type < b.type;
	}
}

const int N = 1e4 + 5;
int n;
vector <line> A;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("AREA.INP", "r", stdin);
	// freopen("AREA.OUT", "w", stdout);

	Solver = SegmentTree(3);
	Solver.add(1, 3, 1);
	Solver.add(1, 1, 0);
	cout << Solver.query() << endl;

	// cin >> n;
	// int mxy = 0;
	// for (int i = 1; i <= n; ++i) {
	// 	int x1, x2, y1, y2;
	// 	cin >> x1 >> y1 >> x2 >> y2;
	// 	if (x1 == x2 || y1 == y2) continue;
	// 	A.push_back({y1, y2, x1, 1});
	// 	A.push_back({y1, y2, x2, -1});
	// 	mxy = max(mxy, y2);
	// }
	// SegmentTree IT = SegmentTree(mxy);
	// sort(A.begin(), A.end());
	// n = A.size();
	// int lst = 0, res = 0;
	// for (int i = 0; i < n; ++i) {
	// 	res += IT.query() * (A[i].x - lst);
	// 	IT.add(A[i].y1, A[i].y2 - 1, A[i].type);
	// 	lst = A[i].x;
	// }
	// cout << res << endl;

	return 0;
}