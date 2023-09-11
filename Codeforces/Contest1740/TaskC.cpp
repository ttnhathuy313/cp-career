#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, a[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int res = a[n] - a[1];
	res = max(res, a[n] * 2 - a[1] - a[n - 1]);
	for (int i = n - 1; i >= 3; --i) {
		res = max(res, a[i] + min(a[i] - a[i - 1], a[i + 1] - a[i]) - a[1]);
	}
	for (int i = n - 2; i >= 2; --i) {
		res = max(res, a[n] - a[i] + min(a[i + 1] - a[i], a[i] - a[i - 1]));
	}
	res = max(res, a[n] - 2 * a[1] + a[2]);

	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}