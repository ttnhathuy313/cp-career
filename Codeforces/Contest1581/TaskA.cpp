#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int res = 1;
		int n;
		cin >> n;
		n *= 2;
		for (int i = 3; i <= n; ++i) {
			res = (res * i) % MOD;
		}
		cout << res << endl;
	}

	return 0;
}