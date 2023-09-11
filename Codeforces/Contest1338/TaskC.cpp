#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n; --n;
	int vm = n % 3;
	n /= 3;
	int cmult = 1;
	while (n >= cmult) {
		n -= cmult;
		cmult *= 4;
	}
	int a = n + cmult, b = 2 * cmult;
	int cx = 1;
	while (cx < cmult) {
		int v = n % 4;
		if (v) b += cx * ((v % 3) + 1);
		cx *= 4;
		n /= 4;
	}
	if (vm == 0) cout << a;
	else if (vm == 1) cout << b;
	else cout << (a ^ b);
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--)
		solve();	

	return 0;
}