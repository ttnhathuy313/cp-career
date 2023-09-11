#include <bits/stdc++.h>

using namespace std;
#define int long long

int solve(int n, int m) {
	int ret = n * (m / 3);
	ret += (m % 3) * ((n + 2) / 3);
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		int res = min(solve(n, m), solve(m, n));
		cout << res << endl;
	}

	return 0;
}