#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);

	int tc;
	cin >> tc;
	// for (int i = 1; i < (1 << 3); ++i) if (i & 1) {
	// 	int s = 0;
	// 	for (int j = 0; j < 3; ++j) if (i & (1 << j))
	// 		s += j + 1;
	// 	cerr << s << endl;
	// }
	while (tc--) {
		int x;
		cin >> x;
		if (x == 2) {
			cout << 3 << endl;
			continue;
		}
		int i;
		for (i = 1; i <= sqrt(2 * x); ++i) {
			if (i * (i + 1) / 2 >= x && i * (i + 1) / 2 - 1 != x && x != 2) break;
		}
		int res = i + i * (i + 1) / 2 - x;
		cout << i << endl;
	}

	return 0;
}