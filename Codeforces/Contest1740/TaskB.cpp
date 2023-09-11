#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, a[N], b[N];

void solve() {
	cin >> n;
	int res = 0, mx = 0, ans = (int)1e18;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		if (a[i] < b[i]) {
			swap(a[i], b[i]);
		}
		mx = max(mx, a[i]);
		res += 2 * b[i];
	}
	res += 2 * mx;
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}