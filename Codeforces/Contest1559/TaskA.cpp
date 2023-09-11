#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 3333;
int n, a[N], cnt[333];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			for (int j = 0; j < 33; ++j) if (a[i] & (1LL << j)) {
				cnt[j]++;
			}
		}
		int res = 0;
		for (int i = 0; i < 33; ++i) {
			if (cnt[i] == n) res += (1LL << i);
		}
		cout << res << endl;
	}

	return 0;
}