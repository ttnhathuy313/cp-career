#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int pref[2 * N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);


	int tc;
	cin >> tc;
	while (tc--) {
		int n, x, p;
		bool res = false;
		cin >> n >> x >> p;
		for (int i = 1; i < 2 * n; ++i) {
			pref[i] = pref[i - 1] + i;
			pref[i] %= n;
		}
		// x + f * (f + 1) / 2 mod n = 0
		for (int i = 0; i < 2 * n; ++i) if (i <= p) {
			if (i == 0 && p < n) {
				continue;
			}
			int j = (i + 1) % n;
			if ((x + pref[i]) % n == 0) {
				res = true;
			}
		}
		if (res) {
			cout << "Yes\n";
		} else cout << "No\n";
	}

	return 0;
}