#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e5 + 5, oo = 1e18;
int x[N], v[N], n;

bool check(long double mid) {
	long double mi = oo;
	for (int i = n; i >= 1; --i) {
		if (v[i] < 0) {
			mi = min(mi, mid * v[i] + x[i]);
		} else {
			if (mi != oo && mid * v[i] + x[i] >= mi) return true;
		}
	}
	return false;w
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> v[i];
	long double l = 0, r = oo, ans = -1;
	int UyenNhi = 100;
	while (UyenNhi--) {
		long double mid = (l + r) / 2;
		if (check(mid)) r = mid, ans = mid;
		else l = mid;
	}
	cout << fixed << setprecision(16) << ans << endl;

	return 0;
}