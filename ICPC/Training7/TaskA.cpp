#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		res = max(res, a[i]);
	}
	cout << res << endl;

	return 0;
}