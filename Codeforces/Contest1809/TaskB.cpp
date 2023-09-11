#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int l = 1, r = (int)1e9, ans = r + 99;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (mid * mid >= n) {
				ans = min(ans, mid);
				r = mid - 1;
			} else l = mid + 1;
		}
		cout << ans - 1 << endl;
	}

	return 0;
}