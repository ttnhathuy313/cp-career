#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskL.INP", "r", stdin);
	freopen("TaskL.OUT", "w", stdout);

	int tc;
	cin >> tc;
	set <int> S; S.clear();
	while (tc--) {
		int n;
		S.clear();
		cin >> n;
		int lim = (int)1e6;
		for (int i = 1; i <= lim; ++i) {
			int x = i * (i + 1);
			if (n % x == 0) {
				S.insert(i);
			}
		}
		for (int k = 1; k <= lim; ++k) if (n % k == 0) {
			int t = n / k;
			int delta = 1 + 4 * t;

			//chinh phuong
			int can = (int)sqrt(delta);
			bool ok = false;
			int v = -1;
			for (int k = can - 1; k <= can + 1; ++k) {
				if (k * k == delta) {
					ok = true;
					v = k;
					break;
				}
			}
			if (!ok) continue;
			can = v;
			// chinh phuong
			int b = 1;
			int x1 = -b + can, x2 = -b - can;
			if (x1 % 2 == 0) {
				if (x1 / 2 > 0 && x1 / 2 <= n)
					S.insert(x1 / 2);
			}
			if (x2 % 2 == 0) {
				if (x2 / 2 > 0 && x2 / 2 <= n)
					S.insert(x2 / 2);
			}
		}
		if (S.size() == 0) cout << -1 << endl;
		else {
			for (int i : S) cout << i << ' ';
				cout << endl;
		}
	}

	return 0;
}