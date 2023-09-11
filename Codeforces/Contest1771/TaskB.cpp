#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, m;
vector <int> adj[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
		}
		for (int i = 1; i <= m; ++i) {
			int u, v;
			cin >> u >> v;
			if (u > v) {
				swap(u, v);
			}
			adj[v].push_back(u);
		}
		int res = 0;
		priority_queue <int> q;
		while (!q.empty()) q.pop();
		q.push(0);
		for (int i = 1; i <= n; ++i) {
			for (int j : adj[i]) {
				q.push(j);
			}
			res += i - q.top();
		}
		cout << res << endl;
	}

	return 0;
}