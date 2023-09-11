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
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int res = 0;
		if (b > a) res++;
		if (c > a) res++;
		if (d > a) res++;
		cout << res << endl;
	}

	return 0;
}