#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 3e5 + 5, oo = 1e18;
int n, block_size, ans[N], a[N], b[N], type[N], time_end[N];

struct Line {
	int a, b;
	Line() {}
	Line(int _a, int _b) : a(_a), b(_b) {}
	val(int x) {
		return a * x + b;
	}
};

struct ConvexHull {
	vector <Line> st;
	ConvexHull() {
		st.clear();
	}
	int bad(Line a, Line b, Line c) {
		return (c.b - a.b) * (b.a - c.a) < (c.b - b.b) * (a.a - c.a);
	}
	void addLine(Line a) {
		if (st.size() && st.back().a == a.a && st.back().b == a.b) st.pop_back();
		while (st.size() >= 2 && bad(a, st.back(), st[st.size() - 2]))
			st.pop_back();
		st.push_back(a);
	}
	void query(int x) {
		int ans = -oo, l = 0, r = st.size() - 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			ans = max(ans, st[mid].val(x));
			int lmid = (mid == 0 ? -oo : st[mid - 1].val(x)), rmid = (mid == st.size() - 1 ? -oo : st[mid + 1].val(x));
			if (lmid > rmid) r = mid - 1; 
			else if (rmid > lmid) l = mid + 1;
			else break;
		}
	}
} cht;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> type[i] >> a[i];
		if (type[i] == 1) cin >> b[i];
		if (type[i] == 2) time_end[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) if (time_end[i] == 0) time_end[i] = n + 1;
	block_size = (int)sqrt(n);
	for (int L = 1; L <= n; L += block_size) {
		int R = L + block_size - 1;
		vector <ii> lines; lines.clear();
		vector <int> process; process.clear();
		for (int i = 1; i <= R; ++i) if (type[i] == 1) {
			if (time_end[i] > R && i < L) lines.push_back({a[i], b[i]});
			if (time_end[i] >= L) process.push_back(i);
		}
		sort(lines.begin(), lines.end());
		cht = ConvexHull();
		for (ii d : lines) cht.addLine(Line(d.first, d.second));
		for (int i = L; i <= R; ++i) if (type[i] == 3) {
			int x = a[i];
			ans[i] = cht.query(x);
			for (int j : process) if (j < i && time_end[j] > i)
				ans[i] = min(ans[i], a[j] * x + b[j]);
		}
	}
	for (int i = 1; i <= n; ++i) if (type[i] == 3)
		cout << ans[i] << endl;

	return 0;
}