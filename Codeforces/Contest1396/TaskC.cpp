#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 5, oo = 1e18;
int n, r1, r2, r3, d, a[N], dp[N][2];

int cost(int i) {
	return min(r1, r3) * a[i] + r3;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n >> r1 >> r2 >> r3 >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}	
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) {
			dp[i][j] = oo;
		}
	}
	dp[1][0] = cost(1);
	dp[0][0] = -d;
	int loop_cost = r2 + min(r3, r1);
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + d + cost(i);
		int lc = min(loop_cost, a[i] * (r1, r3) + min(r1 * 2, r3));
		dp[i][1] = dp[i - 1][1] + lc + 3 * d;
		dp[i][1] = min(dp[i][1], min(dp[i - 2][0], dp[i - 2][1]) + 4 * d + lc 
			+ min(loop_cost, a[i - 1] * min(r1, r3) + min(r1 * 2, r3)));
	}
	int res = min(dp[n][0], dp[n][1]), cur = cost(n);
	for (int i = n - 1; i >= 1; --i) {
		cur += 2 * d + min(loop_cost, a[i] * min(r1, r3) + min(r1 * 2, r3));
		res = min(res, cur + d + dp[i - 1][0]);
	}
	cout << res << endl;

	return 0;
}