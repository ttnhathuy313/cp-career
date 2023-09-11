#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 55;
int n, a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		int odd = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] & 1) {
				odd++;
			}
		}
		if (odd % 2 == 0) {
			cout << 0 << endl;
			continue;
		}
		int res = N;
		for (int i = 1; i <= n; ++i) {
			int type = (a[i] & 1);
			int cnt = 1, x = a[i];
			x >>= 1;
			if (x == 1 - type) {
				res = 1;
				break;
			}
			while (x % 2 == type) {
				x >>= 1;
				cnt++;
			}
			res = min(res, cnt);
		}
		cout << res << endl;
	}

	return 0;
}