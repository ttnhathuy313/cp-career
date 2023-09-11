#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 105;
int n, t[N], d[N], p[N], dp[N][2005];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("LULUT.INP", "r", stdin);
	freopen("LULUT.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> d[i] >> p[i];
	}
	vector <int> ind; ind.clear();
	for (int i = 1; i <= n; ++i)
		ind.push_back(i);
	sort(ind.begin(), ind.end(), [](int i, int j) {
		if (d[i] == d[j]) return t[i] < t[j];
		else return d[i] < d[j];
	});
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	if (t[ind[0]] < d[ind[0]]) dp[0][t[ind[0]]] = p[ind[0]];
	for (int j = 0; j < n - 1; ++j) {
		int i = ind[j];
		for (int T = 0; T <= 2000; ++T) if (~dp[j][T]) {
			dp[j + 1][T] = max(dp[j + 1][T], dp[j][T]);
			if (T + t[ind[j + 1]] < d[ind[j + 1]])
				dp[j + 1][T + t[ind[j + 1]]] = max(dp[j + 1][T + t[ind[j + 1]]], dp[j][T] + p[ind[j + 1]]);
		}
	}
	int res = 0;
	for (int T = 0; T <= 2000; ++T)
		res = max(res, dp[n - 1][T]);
	cout << res << endl;

	return 0;
}