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
		int n, k;
		cin >> n >> k;
		int l1, l2, r1, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		int un = max(r1, r2) - min(l1, l2);
		int connect = max(l1, l2) - min(r1, r2);
		int res = (int)1e18;
		if (connect < 0) {
			connect *= -1;
			k -= connect * n;
			if (k < 0) {
				cout << 0 << endl;
				continue;
			}
			un -= connect;
			for (int i = 1; i <= n; ++i) {
				int val = un * i;
				if (val >= k) {
					res = min(res, k);
				} else {
					res = min(res, val + (k - val) * 2);
				}
			}
			cout << res << endl;
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			int val = un * i;
			if (val >= k) {
				res = min(res, connect * i + k);
			} else {
				int rem = k - val;
				res = min(res, connect * i + val + rem * 2);
			}
		}
		cout << res << endl;
	}

	return 0;
}