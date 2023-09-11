#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, a[N], k;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int res = 0;
	int pop = 2 * k - n;
	for (int i = 1; i <= n - pop; ++i) res = max(res, a[i] + a[n - pop - i + 1]);
	for (int i = max(1LL, n - pop + 1); i <= n; ++i) res = max(res, a[i]);
	cout << res << endl;

	return 0;
}