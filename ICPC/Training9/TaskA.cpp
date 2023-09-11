#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, X, po[100];

int power(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = ret * x;
		x = x * x;
		y >>= 1;
	}
	return ret;
}

int pages(int Y) {
	int dig = (int)log10(Y) + 1;
	int res = (Y - po[dig - 1] + 1) * dig;
	res = min(res, (int)1e18);
	for (int i = dig - 1; i >= 1; --i) {
		res += 9 * po[i - 1] * i;
		res = min(res, (int)1e18);
	}
	return res;
}

int check(int mid) {
	return (pages(X + mid - 1) - pages(X - 1));
}

void solve() {
	cin >> n >> X;
	int l = 1, r = (int)1e15, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid) >= n) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	if (check(ans) != n) cout << -1 << endl;
	else cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	po[0] = 1;
	for (int i = 1; i <= 20; ++i) {
		po[i] = po[i - 1] * 10;
		po[i] = min(po[i], (int)1e18);
	}

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}