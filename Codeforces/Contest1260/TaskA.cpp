#include <bits/stdc++.h>

using namespace std;
#define int long long

main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.inp", "r", stdin);
	freopen("TaskA.out", "w", stdout);

	int q;
	cin >> q;
	while (q--) {
		int n, m = 0;
		cin >> n >> m;
		int res = 0;
		int k = m / n, q = (m % n);
		for (int i = 1; i <= q; ++i) {
			res += (k + 1) * (k + 1);
		}
		for (int i = 1; i <= n - q; ++i) {
			res += k * k;
		}
		cout << res << endl;
	}

	return 0;
}