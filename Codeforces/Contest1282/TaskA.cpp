#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b, c, r;
		cin >> a >> b >> c >> r;
		if (a > b) swap(a, b);
		int L = c - r, R = c + r;
		cout << max(0LL, min(L, b) - a) + max(0LL, b - max(R, a)) << endl;
	}	

	return 0;
}