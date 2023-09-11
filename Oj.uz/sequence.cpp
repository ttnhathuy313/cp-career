#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair <ll, ll> ii;
 
const ll N = 1e5 + 5, oo = 1e18, K = 200;
ll a[N], pref[N], n, dp[2][N];
int trace[N][K];
 
struct Line {
	ll a, b, id;
	Line() {}
	Line(ll _a, ll _b, ll _id) : a(_a), b(_b), id(_id) {}
	ll val(ll x) {
		return a * x + b;
	}
};
 
struct CHT {
	deque <Line> st;
	CHT() {st.clear();}
	bool bad(Line a, Line b, Line c) {
		return (1.0 * (c.b - a.b) / (a.a - c.a) < 1.0 * (c.b - b.b) / (b.a - c.a));
	}
	void addLine(Line d) {
		if (!st.empty() && d.a == st.back().a && d.b == st.back().b) return;
		while (st.size() >= 2 && bad(d, st.back(), st[st.size() - 2])) {
			// cerr << "delete Line y = " << st.back().a << "x + " << st.back().b << endl;
			st.pop_back();
		}
		// cerr << "addLine y = " << d.a << "x + " << d.b << endl;
		st.push_back(d);
	}
	ii query(ll x) {
		ll ans = -oo, id = -1;
		while (st.size() >= 2 && st[0].val(x) < st[1].val(x))
			st.pop_front();
		return {st[0].val(x), st[0].id};
	}
};
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("sequence.INP", "r", stdin);
	freopen("sequence.OUT", "w", stdout);
 
 	ll k;
	cin >> n >> k;
	for (ll i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (ll i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + a[i];
	}
	memset(dp, -1, sizeof dp);
	for (ll i = 1; i <= n; ++i) {
		dp[1][i] = pref[i] * (pref[n] - pref[i]);
	}
	ll res = -1, id = -1;
	for (ll t = 2; t <= k; ++t) {
		CHT Solver;
		ll ff = t & 1;
		for (ll i = 1; i <= n; ++i) {
			if (i >= t) {
				ii d = Solver.query(pref[i]);
				trace[i][t] = d.second;
				dp[ff][i] = d.first + pref[i] * (pref[n] - pref[i]);
			}
			if (t == k && res < dp[ff][i]) res = max(res, dp[ff][i]), id = i;
			// cerr << i << ' ' << t << ' '  << (~dp[ff][i]?dp[ff][i] - pref[i] * pref[n] : -1) << endl;
			if (~dp[ff ^ 1][i]) Solver.addLine({pref[i], dp[ff ^ 1][i] - pref[i] * pref[n], i});
		}
		memset(dp[ff ^ 1], -1, sizeof dp[ff ^ 1]);
	}
	if (k == 1) {
		ll t = -1, dd = 0;
		for (ll i = 1; i <= n; ++i) if (t < dp[1][i])
			t = dp[1][i], dd = i;
		cout << t << endl << dd << endl;
		return 0;
	}
	cout << res << endl;
	vector <ll> nn; nn.clear();
	for (ll i = k; i >= 1; --i) {
		nn.push_back(id);
		id = trace[id][i];
	}
	reverse(nn.begin(), nn.end());
	for (ll v : nn) cout << v << ' ';
 
	return 0;
}