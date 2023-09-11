#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b, c;
		cin >> a >> b >> c;
		int mi = min(a, min(b, c ));
		int cost = a + b + c - 3 * mi;
		if (cost % 3 != 0) {
			cout << "NO" << endl;
			continue;
		}
		mi -= (cost + 5) / 6;
		cerr << mi << endl;
		if (mi % 3 == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}