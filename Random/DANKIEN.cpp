#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 5;
int cnt[N], pref[N], suf[N], n, a[N], x[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("DANKIEN.INP", "r", stdin);
	freopen("DANKIEN.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> x[i];
	for (int i = 1; i <= n; ++i) {
		cnt[i] = cnt[i - 1] + a[i];
		pref[i] = pref[i - 1] + a[i] * x[i];
	}
	for (int i = n; i >= 1; --i) {
		suf[i] = suf[i + 1] + a[i] * x[i];
	}
	int res = (int)1e18;
	for (int i = 1; i <= n; ++i) {
		res = min(res, x[i] * (2 * cnt[i] - cnt[n]) - pref[i] + suf[i + 1]);
	}
	cout << res << endl;

	return 0;
}