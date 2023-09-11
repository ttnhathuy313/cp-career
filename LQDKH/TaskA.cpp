#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
const int N = 1e5 + 5;
int n, k, a[N];
 
bool check(int mid) {
	int need = 0, s = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > mid) continue;
		if (a[i] * (i - 1) - s >= (a[i] - 1) * k) return false;
		s += a[i];
	}
	for (int i = 1; i <= n; ++i) {
		need += max(0LL, mid - a[i]);
	}
	return (need <= mid * k);
}
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.inp", "r", stdin);
	freopen("TaskA.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	check(7);
	// sort(a + 1, a + 1 + n);
	// int l = 0, r = (int)1e9, ans = 0;
	// while (l <= r) {
	// 	int mid = (l + r) >> 1;
	// 	if (check(mid)) l = mid + 1, ans = mid;
	// 	else r = mid - 1;
	// }
	// cout << ans << endl;
 
	return 0;
}