#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, a[N];
map <int, int> cnt;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("LCMPAIR.INP", "r", stdin);
	// freopen("LCMPAIR.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res += cnt[a[i]] * (cnt[a[i]] - 1) / 2;
		cnt[a[i]] = 0;
	}
	cout << res << endl;

	return 0;
}