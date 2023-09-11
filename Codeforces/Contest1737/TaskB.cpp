#include <bits/stdc++.h>

using namespace std;
#define int long long

int ans(int x) {
	int s = sqrt(x);
	int res = (s - 1) * 3;
	if (s * (s + 1) <= x) res++;
	if (s * (s + 2) <= x) res++;
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int l, r;
		cin >> l >> r;
		cout << ans(r) - ans(l - 1) << endl;
	}

	return 0;
}