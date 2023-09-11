#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, MOD = 1e9 + 7;
int dp[N];

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	freopen("TaskC.out", "w", stdout);

	string s;
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1];
		if (s[i] == 'u' && s[i - 1] == 'u') (dp[i] += dp[i - 2]) %= MOD;
		if (s[i] == 'n' && s[i - 1] == 'n') (dp[i] += dp[i - 2]) %= MOD;
	}
	for (int i = 1; i <= n; ++i) if (s[i] == 'w' || s[i] == 'm') {
		cout << 0 << endl;
		return 0;
	}
	cout << dp[n] << endl;
 
	return 0;
}