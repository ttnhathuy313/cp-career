#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		int res = 0, cur = 1;
		for (int i = 0; i < 32; ++i) {
			if (k & (1 << i)) {
				res = (res + cur) % MOD;
			}
			cur = cur * n % MOD;
		}
		cout << res << endl;
	}

	return 0;
}