#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, a[N], b[N], c[N], p[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("TRIPLEINC.INP", "r", stdin);
	// freopen("TRIPLEINC.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) cin >> b[i];
	for (int i = 1; i <= n; ++i) cin >> c[i];
	sort(a + 1, a + 1 + n); sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i - 1] + (lower_bound(a + 1, a + 1 + n, b[i]) - a - 1);
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res += p[lower_bound(b + 1, b + 1 + n, c[i]) - b - 1];
	}
	cout << res << endl;

	return 0;
}