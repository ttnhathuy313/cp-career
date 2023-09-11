#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int mi = N, mx = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			mi = min(mi, a[i]);
			mx = max(mx, a[i]);
		}
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] == mi) cnt1++;
			else if (a[i] == mx) cnt2++;
		}

		if (mi == mx) {
			cout << n * (n - 1) << endl;
		} else {
			cout << 2 * cnt1 * cnt2 << endl;
		}
	}

	return 0;
}