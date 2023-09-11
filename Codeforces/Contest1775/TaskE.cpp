#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, oo = 1e18;
int n, a[N], pref[N];

void solve() {
	cin >> n;
	int mn = 0, mx = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
		if (pref[i] < 0) mn = min(mn, pref[i]);
		else mx = max(mx, pref[i]);
	}
	cout << mx - mn << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}