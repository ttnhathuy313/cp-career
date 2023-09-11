#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e4 + 5;
int dp[N][(int)1e3 + 5], f[N], p[(int)1e6 + 5], d[N], n, m;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> m >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
	}
	int r, g;
	cin >> g >> r;
	sort(d + 1, d + 1 + n);
	for (int i = 1; i <= n; ++i) {
		p[d[i]] = i;
	}
	dp[n][0] = n;
	for (int i = n - 1; i >= 1; --i) {
		dp[i][0] = i;
		if (d[i] + g >= d[n]) dp[i][g] = n;
		for (int j = d[i + 1] - d[j]; j <= g; ++j) if (dp[i + 1][j] == i + 1) 
		for (int j = 1; j <= g; ++j) {
			if (d[i] + j >= d[n]) dp[i][j] = n;
			if (j >= d[i + 1] - d[i]) dp[i][j] = max(dp[i][j], dp[i + 1][j + d[i] - d[i + 1]]);
			if (j >= 2 * (d[i + 1] - d[i])) dp[i][j] = max(dp[i][j], dp[i][j - 2 * (d[i + 1] - d[i])]);
		}
	}
	int cur = 1, res = 0;
	while (cur < n) {
		if (dp[cur][g] == cur || dp[cur][g] == 0) {
			cout << -1 << endl;
			return 0;
		}
		if (dp[cur][g] != n) res += r + g;
		else res += d[n] - d[cur];
		cur = dp[cur][g];
	}
	cout << res << endl;

	return 0;
}