#include <bits/stdc++.h>

using namespace std;
#define int long long

int a[500], b[500];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		bool ok = true;
		for (int i= 1; i <= n; ++i) cin >> a[i];
		for (int i= 1; i <= n; ++i) cin >> b[i];
		for (int i = 1; i <= n; ++i) {
			if (a[i] + b[n - i + 1] > x) ok = false;
		}

		if (ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}