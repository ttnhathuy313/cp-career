#include <bits/stdc++.h>
 
using namespace std;
#define int long long
typedef pair <int, int> ii;
 
const int N = 1e5 + 5, oo = 1e18, K = 200;
int a[N], suf[N], pref[N], n, dp[K][N], trace[N][K];
 
struct Line {
	int a, b, id;
	Line() {}
	Line(int _a, int _b, int _id) : a(_a), b(_b), id(_id) {}
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
	ii query(int x) {
		int l = 0, r = st.size() - 1, ans = -oo, id = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			int cur = st[mid].val(x);
			if (ans < cur) ans = max(ans, cur), id = st[mid].id;
			if (mid != st.size() - 1 && st[mid + 1].val(x) > cur) l = mid + 1;
			else if (mid != 0 && st[mid - 1].val(x) > cur) r = mid - 1;
			else break;
		}
		return {ans, id};
	}
};
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("sequence.INP", "r", stdin);
	freopen("sequence.ANS", "w", stdout);
 
 	int k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + a[i];
	}
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= n; ++i) {
		dp[1][i] = pref[i] * (pref[n] - pref[i]);
	}
	// cerr << dp[1][1] << endl;
	int res = -1, id = -1;
	for (int t = 2; t <= k; ++t) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j < i; ++j) if (~dp[t - 1][j])
				dp[t][i] = max(dp[t][i], dp[t - 1][j] + (pref[i] - pref[j]) * (pref[n] - pref[i]));
			if (t == k) res = max(res, dp[t][i]);
		}
	}
	if (k == 1) {
		int t = -1, dd = 0;
		for (int i = 1; i <= n; ++i) if (t < dp[1][i])
			t = dp[1][i], dd = i;
		cout << t << endl;
		return 0;
	}
	cout << res << endl;
 
	return 0;
}