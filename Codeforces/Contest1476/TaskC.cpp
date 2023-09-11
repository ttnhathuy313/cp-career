#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, a[N], b[N], c[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	int pref = 0, ans = 0;
	for (int i = 2; i <= n; ++i) {
		if (a[i] > b[i]) swap(a[i], b[i]);
		if (i == 2) {
			pref += b[i] - a[i] + 1;
			ans = max(ans, pref + c[i]);
			continue;
		}
		if (a[i] == b[i]) {
			pref = 1;
			ans = max(ans, pref + c[i]);
			continue;
		}
		pref += a[i] + c[i - 1] - b[i] + 1;
		ans = max(ans, pref + c[i]);
	}
	cout << ans << endl;
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