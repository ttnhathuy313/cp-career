#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5005, offset = 5000;
int k, n;
double p[N], dp[N][N + offset];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}	
	sort(p + 1, p + 1 + n, greater <double>());
	double res = 0;

	dp[0][offset] = 1.0;
	for (int i = 1; i <= n; ++i) {
		double cur = 0;
		for (int j = -n; j <= n; ++j) {
			dp[i][j + offset] = dp[i - 1][j + offset - 1] * p[i] + dp[i - 1][j + offset + 1] * (1.0 - p[i]);
			if (j >= k) {
				cur += dp[i][j + offset];
			}
		}
		res = max(res, cur);
	}


	cout << fixed << setprecision(9) << res << endl;

	return 0;
}