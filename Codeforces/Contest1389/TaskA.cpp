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
		int l, r;
		cin >> l >> r;
		if (l * 2 > r) {
			cout << "-1 -1" << endl;
		} else cout << l << ' ' << l * 2 << endl;
	}

	return 0;
}