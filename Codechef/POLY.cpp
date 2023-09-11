#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 5, oo = 1e18;
struct func {
	int a, b, c, d;
	func() {}
	func(int _a, int _b, int _c, int _d) : a(_a), b(_b), c(_c), d(_d) {}
	int val(int x) {
		return a * x * x * x + b * x * x + c * x + d;
	}
} equa[N];

int bound;

struct LiChao {
	vector <func> st;
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
 
	void update(int id, int L, int R, func a) {
		if (L == R) {
			if (st[id].a == oo) st[id] = a;
			else if (st[id].val(L + bound) > a.val(L + bound))
				st[id] = a;
			return;
		}
		int mid = (L + R) >> 1;
		if (st[id].a == oo) {
			st[id] = a;
			return;
		}
		bool l = (st[id].val(L + bound) > a.val(L + bound)), r =(st[id].val(R + bound) > a.val(R + bound)), 
			 m1 = (st[id].val(mid + bound) > a.val(mid + bound)), m2 = (st[id].val(mid + 1 + bound) > a.val(mid + 1 + bound));
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
 
	void addLine(func a) {
		update(1, 1, n, a);
	}
	int query(int id, int L, int R, int x) {
		int ret;
		if (st[id].a == oo) ret = oo;
		else ret = st[id].val(x + bound);
		if (L == R) return ret;
		int mid = (L + R) >> 1;
		if (x > mid) return min(ret, query(Right(id), mid + 1, R, x));
		else return min(ret, query(Left(id), L, mid, x));
	}
	int query(int x) {
		return query(1, 1, n, x - bound);
	}
} Solver;

int n, q, ans[N];

void init() {
	memset(ans, -1, sizeof ans);
}

void solve() {
	init();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a, b, c, d;
		cin >> d >> c >> b >> a;
		equa[i] = {a, b, c, d};
	}
	bound = 350;
	Solver = LiChao((int)1e5);
	for (int i = 1; i <= n; ++i)
		Solver.addLine(equa[i]);
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t <= bound) {
			if (~ans[t]) {
				cout << ans[t] << endl;
				continue;
			}
			ans[t] = oo;
			for (int i = 1; i <= n; ++i)
				ans[t] = min(ans[t], equa[i].val(t));
			cout << ans[t] << endl;
		} else {
			cout << Solver.query(t) << endl;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("POLY.INP", "r", stdin);
	freopen("POLY.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}