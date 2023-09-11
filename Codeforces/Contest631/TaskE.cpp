#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18, offset = 1000001;

struct Line {
	int a, b;
	Line() {}
	Line(int _a, int _b) : a(_a), b(_b) {}
	int val(int x) {
		return a * x + b;
	}
	bool operator == (const Line other) const {
		return (a == other.a && b == other.b);
	}
};

struct LiChao {
	vector <Line> st;
	int n;
	LiChao() {}
	LiChao(int _n) {
		this -> n = _n;
		st.resize(4 * n + 5);
		for (int i = 0; i < 4 * n + 5; i++) 
			st[i].a = oo;
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}

	void update(int id, int L, int R, Line a) {
		if (L == R) {
			if (st[id].a == oo) st[id] = a;
			else if (st[id].val(L) < a.val(L))
				st[id] = a;
			return;
		}
		int mid = (L + R) >> 1;
		if (st[id].a == oo) {
			st[id] = a;
			return;
		}
		bool l = (st[id].val(L) < a.val(L)), r =(st[id].val(R) < a.val(R)), 
			 m1 = (st[id].val(mid) < a.val(mid)), m2 = (st[id].val(mid + 1) < a.val(mid + 1));
		if (l && r) {
			st[id] = a;
			return;
		}
		if (!l && !r) {
			return;
		}
		if (l && m1) {
			update(Right(id), mid + 1, R, st[id]);
			st[id] = a;
			return;
		}
		if (!l && !m1) {
			update(Right(id), mid + 1, R, a);
			return;
		}
		if (m2 && r) {
			update(Left(id), L, mid, st[id]);
			st[id] = a;
			return;
		}
		if (!m2 && !r) {
			update(Left(id), L, mid, a);
			return;
		}
	}

	void addLine(Line a) {
		update(1, 1, n, a);
	}
	int query(int id, int L, int R, int x) {
		int ret;
		if (st[id].a == oo) ret = -oo;
		else ret = st[id].val(x);
		if (L == R) return ret;
		int mid = (L + R) >> 1;
		if (x > mid) return max(ret, query(Right(id), mid + 1, R, x));
		else return max(ret, query(Left(id), L, mid, x));
	}
	int query(int x) {
		return query(1, 1, n, x);
	}
} Solver;

struct LiChao2 {
	vector <Line> st;
	int n;
	LiChao2() {}
	LiChao2(int _n) {
		this -> n = _n;
		st.resize(4 * n + 5);
		for (int i = 0; i < 4 * n + 5; i++) 
			st[i].a = oo;
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}

	void update(int id, int L, int R, Line a) {
		if (L == R) {
			if (st[id].a == oo) st[id] = a;
			else if (st[id].val(L - offset) < a.val(L - offset))
				st[id] = a;
			return;
		}
		int mid = (L + R) >> 1;
		if (st[id].a == oo) {
			st[id] = a;
			return;
		}
		bool l = (st[id].val(L - offset) < a.val(L - offset)), r =(st[id].val(R - offset) < a.val(R - offset)), 
			 m1 = (st[id].val(mid - offset) < a.val(mid - offset)), m2 = (st[id].val(mid + 1 - offset) < a.val(mid + 1 - offset));
		if (l && r) {
			st[id] = a;
			return;
		}
		if (!l && !r) {
			return;
		}
		if (l && m1) {
			update(Right(id), mid + 1, R, st[id]);
			st[id] = a;
			return;
		}
		if (!l && !m1) {
			update(Right(id), mid + 1, R, a);
			return;
		}
		if (m2 && r) {
			update(Left(id), L, mid, st[id]);
			st[id] = a;
			return;
		}
		if (!m2 && !r) {
			update(Left(id), L, mid, a);
			return;
		}
	}

	void addLine(Line a) {
		update(1, 1, n, a);
	}
	int query(int id, int L, int R, int x) {
		int ret;
		if (st[id].a == oo) ret = -oo;
		else ret = st[id].val(x - offset);
		if (L == R) return ret;
		int mid = (L + R) >> 1;
		if (x > mid) return max(ret, query(Right(id), mid + 1, R, x));
		else return max(ret, query(Left(id), L, mid, x));
	}
	int query(int x) {
		return query(1, 1, n, x + offset);
	}
} S;

const int N = 2e5 + 5;
int a[N], pref[N], n;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);

	cin >> n;
	int tmp = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		tmp += a[i] * i;
		pref[i] = pref[i - 1] + a[i];
	}
	int res = 0;
	Solver = LiChao(n);
	Solver.addLine(Line(a[1], 0));
	for (int i = 2; i <= n; ++i) {
		res = max(res, Solver.query(i) - pref[i]);
		Solver.addLine(Line(a[i], - a[i] * i + pref[i]));
	}
	S = LiChao2(2000001);
	S.addLine(Line(1, 0));
	for (int i = 2; i <= n; ++i) {
 		res = max(res, S.query(a[i]) + pref[i - 1] - a[i] * i);
		S.addLine(Line(i, -pref[i - 1]));
	}
	cout << tmp + res << endl;

	return 0;
}