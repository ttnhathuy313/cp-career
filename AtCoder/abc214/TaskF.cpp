#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, MOD = 1e9 + 7;
int n, lst[28], dp[N], pre[28];
string s;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> s;
	n = s.size();
	s = ' ' + s;
	memset(pre, -1, sizeof pre);
	memset(lst, -1, sizeof lst);
	for (int i = 1; i <= n; ++i) {
		for (int ch = 0; ch <= ('z' - 'a'); ++ch) if (~lst[ch]) {
			if (lst[ch] != i - 1) dp[i] = (dp[i] + dp[lst[ch]]) % MOD;
			else if (~pre[ch]) dp[i] = (dp[i] + dp[pre[ch]]) % MOD;
		}
		for (int j = 0; j <= ('z' - 'a'); ++j) {
			pre[j] = lst[j];
		}
		dp[i]++;
		lst[s[i] - 'a'] = i;
	}
	int res = 0;
	for (int i = 0; i <= ('z' - 'a'); ++i) if (~lst[i]) {
		res = (res + dp[lst[i]]) % MOD;
	}
	cout << res << endl;

	return 0;
}