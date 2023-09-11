#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, dp[N][2], a[N][2];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		string r1, r2;
		cin >> r1 >> r2;
		for (int i = 0; i < n; ++i) {
			if (r1[i] == 'W') a[i + 1][0] = 0;
			else a[i + 1][0] = 1;
		}
		for (int i = 0; i < n; ++i) {
			if (r2[i] == 'W') a[i + 1][1] = 0;
			else a[i + 1][1] = 1;
		}
		for (int i = 0; i <= n; ++i) {
			dp[i][0] = dp[i][1] = 0;
		}
		dp[0][0] = dp[0][1] = 1;
		for (int i = 1; i <= n; ++i) {
			if (a[i][0] == 0) {
				dp[i][0] = 0;
			} else dp[i][0] = dp[i - 1][0];
			if (a[i][1] == 0) {
				dp[i][1] = 0;
			} else dp[i][1] = dp[i - 1][1];
			if (a[i][0] == 1 && a[i][1] == 1) {
				if (a[i - 1][0] & a[i - 1][1]) {
					dp[i][0] = dp[i - 1][1];
					dp[i][1] = dp[i - 1][0];
				} else if (a[i - 1][0]) {
					dp[i][1] = dp[i - 1][0];
					dp[i][0] = 0;
				} else if (a[i - 1][1]) {
					dp[i][0] = dp[i - 1][1];
					dp[i][1] = 0;
				} 

			}
		}
		if (dp[n][0] | dp[n][1]) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;
	}

	return 0;
}