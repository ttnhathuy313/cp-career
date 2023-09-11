#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; ++i)

const int N = 3005;
int n, m, a[N][N], dp[N][N], l[N], r[N], res = 0;

void solve() {
	cin >> n >> m;
	res = 2;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	FOR(x1, 1, n) FOR(y1, 1, m) FOR(x2, x1, n) FOR(y2, y1, m) {
		bool ok = true;
		FOR(i, x1, x2) {
			FOR(j, y1 + 2, y2) if (a[i][j] - a[i][j - 1] != a[i][j - 1] - a[i][j - 2])
				ok = false;
		}
		FOR(j, y1, y2) {
			FOR(i, x1 + 2, x2) if (a[i][j] - a[i - 1][j] != a[i - 1][j] - a[i - 2][j])
				ok = false;
		}
		if (ok) res = max(res, (y2 - y1 + 1) * (x2 - x1 + 1));
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("ARITHREC.INP", "r", stdin);
	freopen("ARITHREC.ANS", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}