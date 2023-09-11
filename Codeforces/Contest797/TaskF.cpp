#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 5005, oo = 1e18;
int n, m, x[N], dp[N][N];
ii p[N];

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> x[i];
	for (int i = 1; i <= m; ++i)
		cin >> p[i].first >> p[i].second;
	sort(x + 1, x + 1 + n);
	sort(p + 1, p + 1 + m);
	for (int i = 1; i <= n; ++i) dp[0][i] = oo;
	int res = oo;
	for (int i = 1; i <= m; ++i) {
		deque <ii> dq; dq.clear();
		dq.push_back({0LL, 0LL});
		int pref = 0;
		for (int j = 1; j <= n; ++j) {
			pref += abs(x[j] - p[i].first);
			while (!dq.empty() && dq.front().second < j - p[i].second) dq.pop_front();
			while (!dq.empty() && dq.back().first > dp[i - 1][j] - pref) dq.pop_back();
			dq.push_back({dp[i - 1][j] - pref, j});
			dp[i][j] = dq.front().first + pref;
			if (j == n) res = min(res, dp[i][j]);
		}
	}
	if (res != oo) cout << res << endl;
	else cout << -1 << endl;

	return 0;
}