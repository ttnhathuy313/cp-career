#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 5, oo = 1e18;
int n, a[N], b[N], rem[N];

int check(int mid) {
	for (int i = 1; i <= n; ++i) rem[i] = a[i];
	rem[1] -= mid;
	rem[2] -= min(rem[2], b[1] - mid);
	for (int i = 2; i < n; ++i) {
		if (rem[i] > b[i]) return -oo;
		rem[i + 1] -= min(rem[i + 1], b[i] - rem[i]);
		rem[i] = 0;
	}
	return b[n] - rem[n] - rem[1];
	if (rem[n] + rem[1] <= b[n]) return true;
	else return false;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	int l = 0, r = min(b[1], a[1]), mx = -1;
	while (l < r) {
		int mid = (l + r) >> 1;
		int d1 = check(mid), d2 = check(mid + 1);
		mx = max(mx, max(d1, d2));
		if (d1 >= d2) r = mid;
		else l = mid + 1;
	}
	if (~mx) cout << "YES" << endl;
	else cout << "NO" << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}