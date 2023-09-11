#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 505, oo = 1e18;
int n, l, k, d[N], a[N], dp[2][N][N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n >> l >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for (int i = 0; i <= 1; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int del = 0; del <= k; ++ del) {
				dp[i][j][del] = oo;
			}
		}
	}

	int res = oo;
	dp[1][1][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			for (int del = 0; del <= k; ++ del) {
				int nextId = (i + 1) & 1;
				int curValue = dp[i & 1][j][del];

				if (curValue == oo) {
					continue;
				}
				// cerr << "dp[" << i << "][" << j << "][" << del << "] : " << curValue << endl;
				if (i == n) {
					res = min(res, curValue + a[j] * (l - d[i]));
					continue;
				}
				// delete the next road sign
				dp[nextId][j][del + 1] = min(dp[nextId][j][del + 1], curValue + a[j] * (d[i + 1] - d[i]));

				// keep the next road sign
				dp[nextId][i + 1][del] = min(dp[nextId][i + 1][del], curValue + a[j] * (d[i + 1] - d[i]));
			}
		}

		for (int j = 1; j <= n; ++j) {
			for (int del = 0; del <= k; ++del) {
				dp[i & 1][j][del] = oo;
			}
		}
	}

	cout << res << endl;

	return 0;
}