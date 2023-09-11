#include <bits/stdc++.h>

using namespace std;

const int N = 505, MOD = 1e9 + 7;
int dp[2][N][N], n, m;
string a[N];

bool fit(int x, int y) {
	return (x > 0 && x <= n && y > 0 && y <= m);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = ' ' + a[i];
	}
	int tot = n + m - 2;
	if (a[1][1] != a[n][m]) {
		cout << 0 << endl;
		return 0;
	}
	dp[0][0][0] = 1;
	int res = 0;
	for (int step = 0; step <= tot / 2 + 1; ++step) {
		int i = (step & 1);
		for (int t1 = 0; t1 <= min(step, n - 1); ++t1) {
			for (int t2 = 0; t2 <= min(step, n - 1); ++t2) {
				int x1 = 1 + t1, y1 = 1 + step - t1;
				if (!fit(x1, y1)) continue;
				int x2 = n - t2, y2 = m - step + t2;
				if (!fit(x2, y2)) continue;
				if (x1 > x2) continue;
				if (y1 > y2) continue;
				// cerr << step << " (" << x1 << ", " << y1 << ") ; (" << x2 << ", " << y2 << ") : " << dp[i][t1][t2] << endl;
				for (int d1 = 0; d1 < 2; ++d1) {
					for (int d2 = 0; d2 < 2; ++d2) {
						if (d1) x1++; else y1++;
						if (d2) x2--; else y2--;
						if (!fit(x1, y1) || !fit(x2, y2)) {
							if (d1) x1--; else y1--;
							if (d2) x2++; else y2++;
							continue;
						}
						if (a[x1][y1] == a[x2][y2]) {
							(dp[i ^ 1][t1 + d1][t2 + d2] += dp[i][t1][t2]) %= MOD;
						}
						if (d1) x1--; else y1--;
						if (d2) x2++; else y2++;
					}
				}
				if (abs(x1 - x2) + abs(y1 - y2) <= 1) {
					(res += dp[i][t1][t2]) %= MOD;
				}
			}
		}
		memset(dp[i], 0, sizeof dp[i]);
	}
	cout << res << endl;

	return 0;
}