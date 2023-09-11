#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
deque <int> a;
string s;
int dp[N], n;

int psolve() {
	for (int i = 0; i < n; ++i)
		dp[i] = N;
	for (int i = 1; i < n; ++i) {
		int cost = 0;
		cost += (a[i] != 1) + (a[i - 1] != 0);
		dp[i] = min(dp[i], (i == 1 ? 0 : dp[i - 2]) + cost);
		if (i == 1) continue;
		cost = 0;
		cost += (a[i] != 1) + (a[i - 2] != 0);
		dp[i] = min(dp[i], (i == 2 ? 0 : dp[i - 3]) + cost);
		if (i == 2) continue;
		cost = (a[i] != 1) + (a[i - 1] != 1) + (a[i - 2] != 0) + (a[i - 3] != 0);
		dp[i] = min(dp[i], (i == 3 ? 0 : dp[i - 4]) + cost);
	}
	return dp[n - 1];
}

void solve() {
	a.clear();
	int res = N;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		a.push_back(s[i] == 'L' ? 1 : 0);
	res = psolve();
	int v = a[0]; a.pop_front(); a.push_back(v);
	res = min(res, psolve());
	v = a[0]; a.pop_front(); a.push_back(v);
	res = min(res, psolve());
	v = a[0]; a.pop_front(); a.push_back(v);
	res = min(res, psolve());
	cout << res << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}