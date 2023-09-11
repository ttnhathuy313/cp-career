#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, oo = 1e18;
int a[N], suf[N], pref[N], n;

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
	bool bad(Line a, Line b, Line c) {
		return (1.0 * (c.b - a.b) / (a.a - c.a) < 1.0 * (c.b - b.b) / (b.a - c.a));
	}
	void addLine(Line d) {
		while (st.size() >= 2 && bad(d, st.back(), st[st.size() - 2])) {
			// cerr << "delete Line y = " << st.back().a << "x + " << st.back().b << endl;
			st.pop_back();
		}
		// cerr << "addLine y = " << d.a << "x + " << d.b << endl;
		st.push_back(d);
	}
	int query(int x) {
		int l = 0, r = st.size() - 1, ans = -oo;
		while (l <= r) {
			int mid = (l + r) >> 1;
			int cur = st[mid].val(x); 
			ans = max(ans, cur);
			if (mid != st.size() - 1 && st[mid + 1].val(x) > cur) l = mid + 1;
			else if (mid != 0 && st[mid - 1].val(x) > cur) r = mid - 1;
			else break;
		}
		return ans;
	}
};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = n; i >= 1; --i)
		suf[i] = suf[i + 1] + a[i];
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + suf[i];
	}
	int res = 0;
	CHT Solver;
	Solver.addLine({0, 0});
	// cerr << suf[10] << ' ' << pref[9] << ' ' << pref[4] << endl;
	for (int i = 1; i <= n; ++i) {
		res = max(res, pref[i] - suf[i + 1] * i + Solver.query(suf[i + 1]));
		// cerr << i << " " << pref[i] - suf[i + 1] * i + Solver.query(suf[i + 1]) << endl;
		Solver.addLine({i, -pref[i]});
	}
	cout << res << endl;

	return 0;
}