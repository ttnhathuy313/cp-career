#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 4e5 + 5;
int n, s[N], t[N], pref[N], ans[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i + n] = s[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
		t[i + n] = t[i];
	}
	for (int i = 1; i <= n * 2; ++i) {
		pref[i] = s[i] + pref[i - 1];
	}
	int mi = (int)1e18;
	for (int i = 1; i <= 2 * n; ++i) {
		ans[i] = min(mi + pref[i - 1], t[i]);
		mi = min(mi, t[i] - pref[i - 1]);
	}
	for (int i = 1; i <= n; ++i) {
		cout << min(ans[i], ans[i + n]) << endl;
	}

	return 0;
}