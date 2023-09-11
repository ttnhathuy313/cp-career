#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int a[N], m, n, col[N], mark[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			a[i] = col[i] = mark[i] = 0;
		for (int i = 1; i <= m; ++i) {
			int u, v;
			cin >> u >> v;
			a[u] = v;
			col[v] = u;
		}
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			if (!a[i] || mark[i]) continue;
			if (col[i]) {
				res += 3;
				mark[col[i]] = 1;
				continue;
			} else {
				if (a[i] == i) continue;
				else res++;
			}
		}
		cout << res << endl;
	}

	return 0;
}