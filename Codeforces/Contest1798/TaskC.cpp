#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, a[N], b[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
	}
	int gcdab = -1, i = 1, j = 1, res = 1, lcmb = 1;
	while (j <= n) {
		lcmb = lcmb * b[j] / __gcd(lcmb, b[j]);
		if (~gcdab) gcdab = __gcd(gcdab, a[j] * b[j]);
		else gcdab = a[j] * b[j];
		if (lcmb > (int)1e14 || (gcdab % lcmb != 0)) {
			gcdab = -1;
			i = j;
			lcmb = 1;
			res++;
			continue;
		}
		j++;
	}
	cout << res << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}