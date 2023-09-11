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
		int u, v;
		cin >> u >> v;
		int lcm = u * v / __gcd(u, v);
		int x = lcm / v, y = lcm / u;
		x = - (x * x), y = y * y;
		cout << x << ' ' << y  << endl;
		if (1.0 * x / u + 1.0* y / v != 1.0 * (x + y) / (u + v)) cerr << "cc" << endl;
	}

	return 0;
}