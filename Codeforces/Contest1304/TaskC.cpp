#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 105, oo = 1e9 + 2;
int t[N], l[N], r[N], n, m;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		bool ok = true;	
		int maxU = 0, maxD = 0;
		t[0] = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> t[i] >> l[i] >> r[i];
			if (m > r[i]) {
				maxD = maxD + t[i] - t[i - 1];
				if (m - maxD <= r[i]) {
					maxD -= m - r[i];
				} else {
					ok = false;
					break;
				}
				m = r[i];
				maxU = 0;
				maxD = min(maxD, r[i] - l[i]);
			} else if (m < l[i]) {
				maxU += t[i] - t[i - 1];
				if (m + maxU >= l[i]) {
					maxU -= l[i] - m;
				} else {
					ok = false;
					break;
				}
				maxU = min(maxU, r[i] - l[i]);
				maxD = 0;
				m = l[i];
			} else {
				maxD += t[i] - t[i - 1];
				maxU += t[i] - t[i - 1];
				maxD = min(maxD, m - l[i]);
				maxU = min(maxU, r[i] - m);
			}
			// cerr << maxU << ' ' << maxD << ' ' << m << endl;
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}