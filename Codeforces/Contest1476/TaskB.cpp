#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 105;
int n, k, a[N], b[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		int pref = a[1], mx = 0;
		for (int i = 2; i <= n; ++i) {
			b[i] = 100 * a[i] - pref * k;
			pref += a[i];
			mx = max(mx, b[i]);
		}
		cout << (mx + k - 1) / k << endl;
	}

	return 0;
}