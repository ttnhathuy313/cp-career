#include <bits/stdc++.h>

using namespace std;

const int N = 405;
int n, m, a[N][N], lst[N][N * N], dp[N][N];
bool mark[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("TaskD.INP", "r", stdin);
	// freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	}
	memset(dp, 0, sizeof dp);
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int l = m; l >= 1; --l) {
			for (int r = l; r <= m; ++r) {
				if (l == r) {
					dp[l][r] = max(dp[l][r], lst[r][a[i][l]]);
				} else {
					dp[l][r] = max(dp[l][r], max(dp[l + 1][r], dp[l][r - 1]));
					dp[l][r] = max(dp[l][r], max(lst[l][a[i][r]], lst[r][a[i][l]]));
					if (a[i][l] == a[i][r]) dp[l][r] = i;
				}
				res = max(res, (r - l + 1) * (i - dp[l][r]));
			}
		}
		for (int j = 1; j <= m; ++j) lst[j][a[i][j]] = i;
	}
	cout << res << endl;

	return 0;
}