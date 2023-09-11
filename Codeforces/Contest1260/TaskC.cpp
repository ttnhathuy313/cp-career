#include <bits/stdc++.h>

using namespace std;
#define int long long

main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	freopen("TaskC.out", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b, k;
		cin >> a >> b >> k;
		if (a > b) swap(a, b);
		int f = __gcd(a, b);
		if (a == b && a == 1) {
			if (k > 1) cout << "OBEY" << endl;
			else cout << "REBEL" << endl;
			continue;
		}
		if (a == 1) {
			if (b > k) {
				cout << "REBEL" << endl;
			} else cout << "OBEY" << endl;
			continue;
		}
		int lcm = a * b / f;
		if (k >= lcm) {
			cout << "OBEY" << endl;
			continue;
		}
		if (f + (k - 1) * a < b) {
			cout << "REBEL" << endl;
			continue;
		}
		cout << "OBEY" << endl;
	}

	return 0;
}