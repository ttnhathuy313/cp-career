#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 105, oo = 2e18;
int n, m, b, x[N], k[N], solvable[N], dp[2][(1 << 20)];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n >> m >> b;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> k[i];
		int d;
		cin >> d;
		for (int j = 1; j <= d; ++j) {
			int x;
			cin >> x; x--;
			solvable[i] ^= (1 << x);
		}
	}
	vector <int> ind; ind.clear();
	for (int i = 1; i <= n; ++i) ind.push_back(i);
	sort(ind.begin(), ind.end(), [](int i, int j) {
		return k[i] < k[j];
	});
	memset(dp, -1, sizeof dp);
	dp[0][0] = dp[1][0] = 0;
	int res = oo;
	for (int j = 0; j < n; ++j) {
		int i = ind[j], id = j & 1;
		memset(dp[id], -1, sizeof dp[id]);
		for (int mask = 0; mask < (1 << m); ++mask) {
			if (~dp[id ^ 1][mask]) {
				int d = dp[id][mask | solvable[i]];
				if (d == -1) dp[id][mask | solvable[i]] = oo, d = oo;
				dp[id][mask | solvable[i]] = min(d, dp[id ^ 1][mask] + x[i] + (j == 0 ? k[i] : k[i] - k[ind[j - 1]]) * b);
				d = dp[id][mask];
				if (d == -1) dp[id][mask] = oo, d = oo;
				dp[id][mask] = min(d, dp[id ^ 1][mask] + (j == 0 ? k[i] : k[i] - k[ind[j - 1]]) * b);
			}
		}
		if (~dp[id][(1 << m) - 1]) {
			res = min(res, dp[id][(1 << m) - 1]);
		}
	}
	if (res == oo) res = -1;
	cout << res << endl;

	return 0;
}