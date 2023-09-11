#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 205;
int n, a[N], b[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		int mx = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		for (int i = 1; i <= n; ++i) {
			cin >> b[i];
			mx = max(mx, a[i]);
			if (a[i] < b[i]) {
				swap(a[i], b[i]);
			}
		}
		bool ok = true;
		for (int i = 1; i <= n; ++i) if (a[i] > a[n]) {
			ok = false;
		}
		
		for (int i = 1; i <= n; ++i) if (b[i] > b[n]) {
			ok = false;
		}

		if (ok) {
			cout << "Yes" << endl;
		} else cout << "No" << endl;
	}

	return 0;
}