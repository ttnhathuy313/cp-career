#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 3e3 + 5, MOD = 1e9 + 7;
int n, x[N], p2[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
	}

	p2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		p2[i] = p2[i - 1] * 2 % MOD;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int dist = x[j] - x[i];
			int l = 1, r = i - 1, ans = 0;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (x[mid] > x[i] - dist - 1) {
					r = mid - 1;
				} else {
					l = mid + 1;
					ans = mid;
				}
			}
			int cur = p2[ans];
			l = j + 1, r = n, ans = n + 1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (x[mid] < x[j] + dist) {
					l = mid + 1;
				} else {
					r = mid - 1;
					ans = mid;
				}
			}
			cur = cur * p2[n - ans + 1] % MOD;
			res = (res + cur) % MOD;
		}
	}

	cout << res << endl;


	return 0;
}