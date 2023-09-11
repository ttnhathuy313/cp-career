#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 1e18;

struct Line {
	int a, b;
	Line() {}
	Line(int _a, int _b) : a(_a), b(_b) {}
	int val(int x) {
		return a * x + b;
	}
};

struct CHT {
	vector <Line> st;
	CHT() {st.clear();}
	bool bad(Line l1, Line l2, Line l3) {
		return 1.0 * (l1.b - l3.b) / (l3.a - l1.a) < 1.0 * (l1.b - l2.b) / (l2.a - l1.a);
	}
	void addLine(Line a) {
		while (st.size() > 1 && bad(st[st.size() - 2], st.back(), a)) {
			st.pop_back();
		}
		st.push_back(a);
	}
	int query(int id) {
		int ans = oo;
		int l = 0, r = st.size() - 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			ans = min(ans, st[mid].val(id));
			int cur = st[mid].val(id);
			if (mid != 0 && st[mid - 1].val(id) < cur) r = mid - 1;
			else if (mid != st.size() - 1 && st[mid + 1].val(id) < cur) l = mid + 1;
			else break;
		}
		return ans;
	}
} Solver;

const int N = 1e5 + 5;
int a[N], b[N], n, f[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	freopen("TaskC.out", "w" , stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	f[1] = 0;
	Solver.addLine(Line(b[1], 0));
	for (int i = 2; i <= n; ++i) {
		f[i] = Solver.query(a[i]);
		Solver.addLine(Line(b[i], f[i]));
	}
	cout << f[n] << endl;

	return 0;
}