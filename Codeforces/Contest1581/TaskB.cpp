#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	k--;
	if (k == -1 || k == 0) {
		cout << "NO" << endl;
		return;
	}
	if (k == 1) {
		if (n == 1 && m == 0) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;
		return;
	}

	if (m > n * (n - 1) / 2) {
		cout << "NO" << endl;
		return;
	}

	if (k == 2) {
		if (n * (n - 1) / 2 == m) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;
		return;
	}

	if (m >= n - 1) {
		cout << "YES" << endl;
	} else cout << "NO" << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}