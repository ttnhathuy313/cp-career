#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, a[N], b[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b + 1, b + 1 + n);
		bool ok = true;
		for (int i = 1; i <= n; ++i) if (max(i - 1, n - i) < x) {
			if (a[i] != b[i]) ok = false;
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}