#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, m;
bool mark[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			mark[i] = 0;
		for (int i = 1; i <= m; ++i) {
			int u, v, c;
			cin >> u >> v >> c;
			mark[v] = 1;
		}
		int id = -1;
		for (int i = 1; i <= n; ++i) if (!mark[i])
			id = i;
		for (int i = 1; i <= n; ++i) if (i != id) {
			cout << i << ' ' << id << endl;
		}
	}

	return 0;
}