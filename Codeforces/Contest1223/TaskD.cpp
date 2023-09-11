#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

void solve() {
	vector <int> beg, lst, a, len, dp;
	int n, diffs = 0;
	cin >> n;
	a.assign(n + 5, 0); beg.assign(n + 5, 0); lst.assign(n + 5, 0); len.assign(n + 5, 0); dp.assign(n + 5, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (beg[a[i]] == 0) beg[a[i]] = i, diffs++;
		len[a[i]]++;
		lst[a[i]] = i;
	}
	int res = 1, pre = 0;

	for (int i = 1; i <= n; ++i) if (beg[i] != 0) {
		if (lst[pre] < beg[i]) dp[i] = dp[pre] + 1;
		else dp[i] = 1;
		res = max(res, dp[i]);
		pre = i;
	}

	cout << diffs - res << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) solve();

	return 0;
}