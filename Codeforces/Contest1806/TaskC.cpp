#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 4e5 + 5;
int n, p[N], pref[N], suf[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= 2 * n; ++i) {
			cin >> p[i];
		}
		if (n == 1) {
			cout << abs(p[1] - p[2]) << endl;
			continue;
		}
		int res = (int)1e18;
		if (n == 2) {
			vector <int> y = {0, 2, 2, 2, 2};
			int temp = 0;
			for (int i = 1; i <= 2 *n; ++i) {
				temp += abs(y[i] - p[i]);
			}
			res = min(res, temp);
			 y = {0, 0, 0, 0, 0};
			temp = 0;
			for (int i = 1; i <= 2 *n; ++i) {
				temp += abs(y[i] - p[i]);
			}
			res = min(res, temp);
		}

		int tmp = 0;
		for (int i = 1; i <= 2 * n; ++ i) {
			tmp += abs(p[i]);
		}

		res = min(res, tmp);

		for (int i = 1; i <= 2 * n; ++i) {
			pref[i] = pref[i - 1] + abs(p[i] + 1);
		}
		if (n % 2 == 0) {
			suf[2 * n + 1] = 0;
			for (int i = 2 *n; i >= 1; --i) {
				suf[i] = suf[i + 1] + abs(p[i] + 1);
			}
			for (int i = 1; i <= 2 * n; ++i) {
				res = min(res, pref[i - 1] + suf[i + 1] + abs(n - p[i]));
			}
		}
		cout << res << endl;
	}


	return 0;
}