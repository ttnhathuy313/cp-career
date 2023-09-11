#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1005;
int a[N][10];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 5; ++j) {
				cin >> a[i][j];
			}
		}
		bool ok = false;
		for (int d1 = 0; d1 < 5; ++d1) {
			for (int d2 = d1 + 1; d2 < 5; ++d2) {
				int cnt1 = 0, cnt2 = 0, cnt12 = 0;
				for (int i = 1; i <= n; ++i) {
					if (a[i][d1] && a[i][d2]) {
						cnt12++;
					} else if (a[i][d1]) {
						cnt1++;
					} else if (a[i][d2]) {
						cnt2++;
					}
				}
				if (cnt1 + cnt2 + cnt12 != n) continue;
				if (cnt1 < cnt2) swap(cnt1, cnt2);
				if (cnt2 + cnt12 >= cnt1) {
					ok = true;
				}
			}
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	

	return 0;
}