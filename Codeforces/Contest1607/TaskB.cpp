#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int x, n;
		cin >> x >> n;
		int t = (n / 4) * 4, orginal = x;
		for (int i = t + 1; i <= n; ++i) {
			if (i % 4 == 1) x -= i * ((orginal % 2 == 0) ? 1 : -1);
			else x += i * ((orginal % 2 == 0) ? 1 : -1);
		}
		cout << x << endl;
	}

	return 0;
}