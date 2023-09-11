#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, oo = 1e9 + 7;
int s[N], a[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; ++i) {
		s[i] = 0;
		a[i] = -oo;
	}
	for (int i = n - k + 1; i <= n; ++i) {
		cin >> s[i];
		if (i != n - k + 1) {
			a[i] = s[i] - s[i - 1];
			cerr << a[i] << endl;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] < a[i - 1]) {
			cerr << i << endl;
			cout << "No" << endl;
			return;
		}
	}
	a[n + 1] = oo;
	int threshold = a[n - k + 2];
	if (threshold * (n - k + 1) < s[n - k + 1]) {
		cout << "NO" << endl;
	} else cout << "YES" << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	// freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}