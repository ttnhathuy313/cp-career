#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		sort(a + 1, a + 1 + n);
		int res = n / 2;
		for (int i = n; i >= 2; --i) {
			if (a[i] != a[i - 1]) {
				res = max(res, (i - 1) * (n - i + 1));
			}
		}
		cout << res << endl;
	}

	return 0;
}