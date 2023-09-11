#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e5 + 5;
int n, a[N], dp[N], lst[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	memset(lst, -1, sizeof lst);
	dp[n] = n;
	if (a[n] > 0) lst[a[n]] = n;

	for (int i = n - 1; i >= 1; --i) {
		dp[i] = dp[i + 1];
		if (~lst[abs(a[i])] && a[i] < 0) {
			dp[i] = min(dp[i], lst[abs(a[i])] - 1);
		}
		if (a[i] > 0) lst[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i)
		cout << dp[i] - i  + 1 << ' ';


	return 0;
}