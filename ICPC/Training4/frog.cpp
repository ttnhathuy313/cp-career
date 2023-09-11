#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 55;
int n, dp[N], d, cnt = 0;
string s;

void solve() {
	cin >> n >> d;
	cin >> s;
	dp[1] = 0;
	for (int i = 2; i <= n; ++i) dp[i] = n + 1;
	for (int i = 2; i <= n; ++i) if (s[i - 1] == '.') {
		for (int j = 1; j < i; ++j) if (s[j - 1] == '.' && i - j - 1 <= d)
			dp[i] = min(dp[i], dp[j] + 1);
	}
	if (cnt != 0) cout << endl;
	int res = (dp[n] == n + 1 ? 0 : dp[n]);
	cout << "Day #" << (++cnt) << endl;
	cout << n << ' ' << d << endl;
	cout << s << endl;
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("frog.INP", "r", stdin);
	freopen("frog.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}