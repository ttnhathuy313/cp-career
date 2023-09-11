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
		int a, b, d;
		cin >> a >> b >> d;
		int r1 = (d - (a % d)), r2 = (d - (b % d));
		r1 %= d;
		r2 %= d;
		int res = 0;
		bool ok = true;
		for (int i = 0; i < 32; ++i) {
			if ((r1 & (1 << i)) && (r2 & (1 << i))) {
				bool found = false;
				for (int j = 0; j <= 59; ++j) {
					if (a & (1 << j)) {
						continue;
					}
					if (b & (1 << j)) {
						continue;
					}
					if ((1 << j) % d == (1 << i)) {
						res += (1 << j);
						found = true;
						break;
					}
				}

				ok &= found;
			} else if (r1 & (1 << i)) {
				bool found = false;
				for (int j = 0; j < 32; ++j) if (b & (1 << j)) {
					if (a & (1 << j)) {
						continue;
					}
					if ((1 << j) % d == (1 << i)) {
						res += (1 << j);
						found = true;
						break;
					}
				}
				if (found == false) {
					cerr << i << endl;
				}
				ok &= found;
			} else if (r2 & (1 << i)) {
				bool found = false;
				for (int j = 0; j < 32; ++j) if (a & (1 << j)) {
					if (b & (1 << j)) {
						continue;
					}
					if ((1 << j) % d == (1 << i)) {
						res += (1 << j);
						found = true;
						break;
					}
				}
				ok &= found;
			}
		}
		if (!ok) {
			cout << -1 << endl;
		} else cout << res << endl;
	}

	return 0;
}