#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int p[N], pos[N], a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, d;
		cin >> n >> m >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
			pos[p[i]] = i;
		}
		for (int i = 1; i <= m; ++i) {
			cin >> a[i];
		}
		bool not_good = true;
		for (int i = 1; i < m; ++i) {
			if (pos[a[i]] >= pos[a[i + 1]])
				not_good = false;
			if (pos[a[i + 1]] > pos[a[i]] + d)
				not_good = false;
		}
		if (!not_good) {
			cout << 0 << endl;
			continue;
		}
		int res = n * n;
		for (int i = 1; i < m; ++i) {
			res = min(res, pos[a[i + 1]] - pos[a[i]]);
			if (abs(pos[a[i + 1]] - pos[a[i]] - d) + 1 <= pos[a[i]] - 1 + (n - pos[a[i + 1]])) res = min(res, abs(pos[a[i + 1]] - pos[a[i]] - d) + 1);
		}
		cout << res << endl;
	}

	return 0;
}