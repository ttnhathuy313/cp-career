#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, a[N], k;

bool check(int mid) {
	for (int i = mid; i <= n; ++i) if (a[i] - a[i - mid] <= k)
		return true;
	return false;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] ^= 1;
		a[i] += a[i - 1];
	}
	int l = 1, r = n, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("SPC3.INP", "r", stdin);
	freopen("SPC3.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}