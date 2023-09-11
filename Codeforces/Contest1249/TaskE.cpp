#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int dp[N][2], a[N], b[N];

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);

	int n, c;
	cin >> n >> c;
	for (int i = 1; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i) cin >> b[i];
	dp[1][0] = 0;
	for (int i = 2; i <= n; ++i) {
		if (i == 2) {
			dp[i][0] = a[1];
			dp[i][1] = c + b[1];
			continue;
		}
		for (int j = 0; j < 2; ++j) {
			if (j == 0) {
				dp[i][j] = min(dp[i - 1][j] + a[i - 1], dp[i - 1][j ^ 1] + a[i - 1]);
			} else {
				dp[i][j] = min(dp[i - 1][j ^ 1] + c + b[i - 1], dp[i - 1][j] + b[i - 1]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << min(dp[i][0], dp[i][1]) << ' ';
	}

	return 0;
}