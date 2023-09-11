#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n;
	int res = (int)1e9 + 5;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		res = min(res, a[i]);
	}
	cout << res * (n - 1) << endl;

	return 0;
}