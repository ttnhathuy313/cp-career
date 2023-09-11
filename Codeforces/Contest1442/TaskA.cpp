#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 3e5 + 5;
int n, a[N], suf[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	suf[n] = 0;
	for (int i = n - 1; i >= 1; --i) {
		suf[i] = suf[i + 1];
		if (a[i] > a[i + 1]) suf[i] += a[i] - a[i + 1];
	}
	int L, R;
	for (L = 1; L <= n; ++L) {
		if (a[L] < a[L + 1]) break;
	}
	if (L == n) {
		cout << "YES" << endl;
		return;
	}
	for (R = n; R >= 1; --R) {
		if (suf[R] > a[R]) break;
	}
	R++;
	if (L + 1 < R) {
		cout << "NO" << endl;
		return;
	}
	for (int i = R; i <= L + 1; ++i) {
		int pre = a[i - 1];
		if (suf[i] <= pre) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
	return;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}