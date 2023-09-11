#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
int n, m, a[N][N], dp[N][N], l[N], r[N], res = 0;

void solve_basecase() { // case when the rectangle has width <= 2
	for (int i = 1; i <= n; ++i) {
		int lst = 1;
		for (int j = 3; j <= m; ++j) {
			if (a[i][j] - a[i][j - 1] != a[i][j - 1] - a[i][j - 2]) {
				lst = j - 1;
			}
			res = max(res, j - lst + 1);
		}
	}
	for (int i = 1; i < n; ++i) {
		int lst = 1;
		for (int j = 3; j <= m; ++j) {
			if (a[i][j] - a[i][j - 1] != a[i][j - 1] - a[i][j - 2] || a[i + 1][j] - a[i + 1][j - 1] != a[i + 1][j - 1] - a[i + 1][j - 2])
				lst = j - 1;
			res = max(res, (j - lst + 1) * 2); 
		}
	}
	for (int j = 1; j <= m; ++j) {
		int lst = 1;
		for (int i = 3; i <= n; ++i) {
			if (a[i][j] - a[i - 1][j] != a[i - 1][j] - a[i - 2][j])
				lst = i - 1;
			res = max(res, i - lst + 1);
		}
	}
	for (int j = 1; j < m; ++j) {
		int lst = 1;
		for (int i = 3; i <= n; ++i) {
			if (a[i][j] - a[i - 1][j] != a[i - 1][j] - a[i - 2][j] || a[i][j + 1] - a[i - 1][j + 1] != a[i - 1][j + 1] - a[i - 2][j + 1])
				lst = i - 1;
			res = max(res, (i - lst + 1) * 2);
		}
	}
}

void solve() {
	cin >> n >> m;
	res = 2;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 2; i < n; ++i) {
		for (int j = 2; j < m; ++j) {
			bool ok = true;
			for (int k = i - 1; k <= i + 1; ++k) 
				if (a[k][j] - a[k][j - 1] != a[k][j + 1] - a[k][j]) ok = false;
			for (int k = j - 1; k <= j + 1; ++k)
				if (a[i][k] - a[i - 1][k] != a[i + 1][k] - a[i][k]) ok = false;
			dp[i][j] = ok;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!dp[i][j]) dp[i][j] = 0;
			else {
				dp[i][j] = dp[i - 1][j] + 1;
			}
		}
	}
	memset(l, 0, sizeof l); memset(r, 0, sizeof r);
	solve_basecase();
	for (int i = 2; i < n; ++i) {
		vector <int> st; st.clear();
		memset(l, 0, sizeof l); memset(r, 0, sizeof r);
		for (int j = 2; j < m; ++j) {
			while (!st.empty() && dp[i][st.back()] >= dp[i][j])
				st.pop_back();
			if (st.empty()) l[j] = 2;
			else l[j] = st.back() + 1;
			st.push_back(j);
		} 
		st.clear();
		for (int j = m - 1; j > 1; --j) {
			while (!st.empty() && dp[i][st.back()] >= dp[i][j])
				st.pop_back();
			if (st.empty()) r[j] = m - 1;
			else r[j] = st.back() - 1;
			st.push_back(j);
		}
		for (int j = 2; j < m; ++j) {
			res = max(res, (dp[i][j] + 2) * (r[j] - l[j] + 3));
		}
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("ARITHREC.INP", "r", stdin);
	freopen("ARITHREC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}