#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 6;
int n, m, f[N], g[N];

void solve() {
	cin >> n >> m;
	int res = m, rem = m;
	for (int i = n; i >= 2; --i) {
		f[i] = (n / i) * (n / i - 1) / 2;
		g[i] = f[i];
		for (int j = i * 2; j <= n; j += i) {
			g[i] -= g[j];
		}
		if (rem >= (i - 1)) {
			int available = g[i] / (i - 1);
			if (rem > available * (i - 1)) {
				rem -= available * (i - 1);
				res += available;
				continue;
			} else {
				res += rem / (i - 1);
				rem = rem % (i - 1);
			}
		}
	}
	if (rem > 0) {
		cout << -1 << endl;
	} else cout << res << endl;

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}