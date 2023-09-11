#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, a[N], q[N];
ii ans[N];

struct Line {
	int a, b;
	Line() {}
	Line(int _a, int _b) : a(_a), b(_b) {}
	int val(int x) {
		return a * x + b;
	}
};

bool bad1(Line a, Line b, Line c) {
	return (c.b - a.b) * (b.a - c.a) > (c.b - b.b) * (a.a - c.a);
}

bool bad2(Line a, Line b, Line c) {
	return (c.b - a.b) * (b.a - c.a) < (c.b - b.b) * (a.a - c.a);	
}

ii intersec(Line a, Line b) {
	return {b.b - a.b, a.a - b.a};
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("falling.in", "r", stdin);
	freopen("falling.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> q[i];
	vector <int> ind;
	ind.clear();
	for (int i = 1; i <= n; ++i) ind.push_back(i);
	sort(ind.begin(), ind.end(), [](int i, int j) {
		return a[i] < a[j];
	});
	vector <Line> st;
	st.clear();
	for (int i : ind) {
		Line cur = Line(-i, a[i]);
		while (st.size() > 1 && bad1(cur, st.back(), st[st.size() - 2]))
			st.pop_back();
		st.push_back(cur);
		if (a[q[i]] < a[i]) {
			int l = 0, r = st.size() - 1, id = -1;
			int x, y; x = y = -1;
			Line query = Line(-q[i], a[q[i]]);
			while (l <= r) {
				int mid = (l + r) >> 1;
				ii v = intersec(st[mid], query);
				if (v.first * y > v.second * x) {
					x = v.first;
					y = v.second;
					id = mid;
				}
				if (mid == 0) l = mid + 1;
				else if (mid == st.size() - 1) r = mid - 1;
				else {
					ii u = intersec(st[mid - 1], query);
					v = intersec(st[mid + 1], query);
					if (u.first * v.second > v.first * u.second) r = mid - 1;
					else l = mid + 1;
				}
			}
			ans[i] = {x / __gcd(x, y), y / __gcd(x, y)};
		}
	}

	sort(ind.begin(), ind.end(), [](int i, int j) {
		return i < j;
	});
	st.clear();
	for (int i : ind) {
		Line cur = Line(-i, a[i]);
		while (st.size() > 1 && bad1(cur, st.back(), st[st.size() - 2])) {
			cerr << "Popping line " << st.back().a << "x + " << st.back().b << endl;
			st.pop_back();
		}
		cerr << "Adding line -" << i << "x + " << a[i] << endl;
		st.push_back(cur);
		if (q[i] < i) {
			int l = 0, r = st.size() - 1, id = -1;
			int x, y; x = -1; y = -33333333;
			Line query = Line(-q[i], a[q[i]]);
			while (l <= r) {
				int mid = (l + r) >> 1;
				ii v = intersec(st[mid], query);
				if (i == 2 && mid == 1) cerr << v.first << ' ' << v.second << endl;
				if (v.first * y > v.second * x) {
					x = v.first;
					y = v.second;
					id = mid;
				}
				if (mid == 0) l = mid + 1;
				else if (mid == st.size() - 1) r = mid - 1;
				else {
					ii u = intersec(st[mid - 1], query);
					v = intersec(st[mid + 1], query);
					if (u.first * v.second > v.first * u.second) r = mid - 1;
					else l = mid + 1;
				}
			}
			ans[i] = {x / __gcd(x, y), y / __gcd(x, y)};
			cerr << "got ans : " << ans[i].first << "/" << ans[i].second << endl;
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		cout << ans[i].first << '/' << ans[i].second << endl;
	}

	return 0;
}