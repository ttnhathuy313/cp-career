#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 3005, oo = 1e18;
int n, x[N], c[N], dp[N][N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TIENPHAT.INP", "r", stdin);
	freopen("TIENPHAT.OUT", "w", stdout);

	cin >> n;
	vector <ii> val; val.clear();
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> c[i];
		val.push_back({x[i], c[i]});
	}
	sort(val.begin(), val.end());
	for (int i = 0; i < n; ++i) {
		x[i + 1] = val[i].first;
		c[i + 1] = val[i].second;
	}
	for (int i = 1; i <= n + 1; ++i) {
		for (int j = 0; j <= n + 1; ++j)
			dp[i][j] = oo;
	}
	dp[n + 1][0] = 0;
	for (int i = n; i >= 1; --i) {
		for (int j = 0; j <= (n - i + 1); ++j) {
			if (j == 0) {
				for (int k = 0; k <= n; ++k)
					dp[i][j] = min(dp[i][j], dp[i + 1][k] + (x[i + 1] - x[i]) * k + c[i]);
			} else dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + (x[i + 1] - x[i]) * (j - 1));
		}
	}
	cout << dp[1][0] << endl;

	return 0;
}