#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.inp", "r", stdin);
	
	int tc;
	cin >> tc;

	while (tc--) {
		int a, b;
		cin >> a >> b;
		if (1.0 * a / b > 2) {	
			cout << "1" << endl;
			continue;
		} else {
			double ab = 1.0 * a / b;
			if (ab * ab > 2) {
				cout << "1" << endl;
			} else cout << "2" << endl;
		}
	}

	return 0;
}