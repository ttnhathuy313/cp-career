#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, oo = 1e9 + 1;
int n, k, a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		int mx = -oo, mi = oo;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			mx = max(mx, a[i]);
			mi = min(mi, a[i]);
		}
		for (int i = 1; i <= n; ++i) {
			a[i] = mx - a[i];
		}
		k--;
		int d = mx - mi;
		if (k & 1) {
			for (int i = 1; i <= n; ++i) a[i] = d - a[i];
		}
		for (int i = 1; i <= n; ++i) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}

	return 0;
}