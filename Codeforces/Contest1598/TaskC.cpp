#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, sum = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		if (((2 * sum) % n) != 0) {
			cout << 0 << endl;
			continue;
		}
		int need = 2 * sum / n;
		map <int, int> cnt;
		cnt.clear();
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			res += cnt[need - a[i]];
			cnt[a[i]]++;
		}
		cout << res << endl;
	}	

	return 0;
}