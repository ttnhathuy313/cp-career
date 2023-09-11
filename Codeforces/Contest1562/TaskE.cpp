#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5005;
int n, lcp[N][N], dp[N];
string s;

void solve() {
	cin >> n >> s;
	s = ' ' + s;
	for(int i = 1; i <= n + 1; ++i) {
		for (int j = 1; j <= n + 1; ++j) {
			lcp[i][j] = 0;
		}
	}
	for (int i = n; i >= 1; --i) {
		for (int j = n; j >= 1; --j) {
			if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
			else lcp[i][j] = 0;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = (n - i + 1);
		for (int j = 1; j < i; ++j) {
			if (s[i + lcp[i][j]] < s[j + lcp[i][j]]) continue;
			dp[i] = max(dp[i], dp[j] + (n - i + 1) - lcp[i][j]);
		}
		res = max(res, dp[i]);
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}