#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, m, d[N], tin[N], dfsTime;
vector <ii> adj[N];
bool mark[N];

void dfs(int u) {
	tin[u] = ++dfsTime;
	mark[u] = 1;
	for (ii p : adj[u]) {
		int v = p.first, w = p.second;
		if (!mark[v]) {
			d[v] = d[u] + w;
			dfs(v);
		} else if (tin[v] > tin[u]) {
			if (d[v] - d[u] != w) {
				cout << "No";
				exit(0);
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int l, r, x;
		cin >> l >> r >> x;
		adj[r].push_back({l, x});
		adj[l].push_back({r, -x});
	}
	for (int i = 1; i <= n; ++i) if (!mark[i])
		dfs(i);
	cout << "Yes";

	return 0;
}