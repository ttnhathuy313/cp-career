#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 5;
int n, d, a[N], res, mark[N], cycle;
vector <int> adj[N];

void dfs(int u, int dep) {
	mark[u] = 1;
	res = max(res, dep);
	for (int v : adj[u]) {
		if (mark[v]) {
			cycle = 1;
			return;
		}
		dfs(v, dep + 1);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> d;
		res = 0, cycle = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			adj[i].clear();
			mark[i] = 0;
		}
		for (int i = 0; i < n; ++i) if (a[i] == 1) {
			adj[(i - d + n) % n].push_back(i); 
		}
		for (int i = 0; i < n; ++i) if (a[i] == 0) {
			dfs(i, 0);
		}
		for (int i = 0; i < n; ++i) if (a[i] == 1 && !mark[i])
			cycle = 1;
		if (cycle) {
			cout << -1 << endl;
		} else cout << res << endl;
	}

	return 0;
}