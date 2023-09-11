#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, a, b, h[N], t[N];

bool check(int mid) {
	for (int i = 1; i <= n; ++i) t[i] = h[i] - mid * b;
	int once = a - b, need = 0;
	for (int i = 1; i <= n; ++i) if (t[i] > 0) {
		need += t[i] / once + (t[i] % once != 0);
	}
	return (need <= mid);
}

signed main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> a >> b;
	for (int i = 1; i <= n; ++i) cin >> h[i];
	int l = 1, r = (int)1e9, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans << endl;

	return 0;
}