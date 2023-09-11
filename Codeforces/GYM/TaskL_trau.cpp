#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int pref[N], dp[N];

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	s = ' ' + s;
	memset(pref, 0, sizeof pref);
	for (int i = 1; i <= n; ++i) dp[i] = N;
	for (int i = 2; i <= n; ++i) {
		if (s[i] == s[i - 1]) pref[i]++;
	}
	for (int i = 1; i <= n; ++i) {
		pref[i] += pref[i - 1];
	}
	dp[0] = -1;
	for (int i = 1; i <= n; ++i) {
		bool ok = false;
		for (int j = i; j >= max(1, i - k + 1); --j) {
			if (j != i && s[j] == s[j + 1]) ok = true;
			if (ok || j == i) dp[i] = min(dp[i], dp[j - 1] + 1);
		}
		// int l = max(1, i - k + 1), r = i, ans = r;
		// if (pref[r] - pref[l] > 0) dp[i] = dp[l - 1] + 1;
		// else dp[i] = dp[i - 1] + 1;
	}
	//cerr << dp[2] << endl;
	cout << dp[n] << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskL.inp", "r", stdin);
	freopen("TaskL.ans", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}