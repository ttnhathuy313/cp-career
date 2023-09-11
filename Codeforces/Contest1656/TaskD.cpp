#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int times = 2;
		while (n % 2 == 0) {
			n /= 2;
			times *= 2;
		}
		if (n == 1) {
			cout << -1 << endl;
			continue;
		}
		cout << min(times, n) << endl;
	}

	return 0;
}