#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 5;
int n, k, a[N];
multiset <int> S;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("GIFTS.INP", "r", stdin);
	freopen("GIFTS.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (int i = k + 1; i <= n - k + 1; ++i) {
		S.insert(a[i + k - 1] - a[i - 1]);
	}
	int res = (int)1e18;
	for (int i = k; i <= n; ++i) {
		if (i - k >= k) S.insert(a[i - k] - a[i - 2 * k]);
		res = min(res, *(S.rbegin()));
		if (i + k <= n) S.erase(S.find(a[i + k] - a[i]));
	}
	cout << res << endl;

	return 0;
}