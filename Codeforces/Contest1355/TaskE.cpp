#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, oo = 1e18;
int h[N], n, up, down, m;

int calc(int mid) {
	int low, high; low = high = 0;
	for (int i = 1; i <= n; ++i) 
		if (h[i] < mid) low += mid - h[i];
		else if (h[i] > mid) high += h[i] - mid;
	int ret = 0;
	ret += min(low, high) * min(m, up + down);
	if (low > high) ret += (low - high) * up;
	else ret += (high - low) * down;
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> up >> down >> m;
	for (int i = 1; i <= n; ++i)
		cin >> h[i];
	if (up == 0 || down == 0) {
		cout << 0 << endl;
		return 0;
	}
	if (m == 0) {
		int s = 0;
		for (int i = 1; i <= n; ++i) s += h[i];
		int medium = s / n, rem = s % n;
		cout << min(rem * down, (n - rem) * up);
		return 0;
	}
	int l = 0, r = (int)1e9, ans = oo;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int cur = calc(mid);
		// cerr << l << ' ' << r << ' ' << mid << ' ' << cur << endl;
		if (cur < ans) {
			ans = cur;
		}
		int la, lb; la = lb = oo;
		if (mid) la = calc(mid - 1);
		if (mid != oo) lb = calc(mid + 1);
		if (la > lb) l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;

	return 0;
}