#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		if (n - m - 1 <= m) {
			cout << n * (n + 1) / 2 - n + m << endl;
		} else {
			cerr << n << " " << m << endl;
			int avg = (n - m) / (m + 1), mod = (n - m) % (m + 1);
			cerr << avg << ' ' << mod << endl;
			int x1 = avg * (avg + 1) / 2, x2 = (avg + 1) * (avg + 2) / 2;
			int res = (m + 1 - mod) * x1 + mod * x2;
			cout << n * (n + 1) / 2 - res << endl;
		}
	}

	return 0;
}