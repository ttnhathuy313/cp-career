#include <bits/stdc++.h>
 
using namespace std;
#define int long long
typedef pair <int, int> ii;
 
const int N = 1e5 + 5;
int n, deg[N], m, mark[N];
vector <int> adj[N], ans;
set <ii> edges; 
 
void find_eulertour(int u) {
	mark[u] = 1;
	for (int v : adj[u]) {
		int a = u, b = v;
		if (a > b) swap(a, b);
		if (edges.find({a, b}) != edges.end()) {
			edges.erase({a, b});
			find_eulertour(v);
		}
	}
	ans.push_back(u);
}
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("EulerTour.INP", "r", stdin);
	// freopen("EulerTour.OUT", "w", stdout);
 
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++; deg[v]++;
		edges.insert({u, v});
	}
	for (int i = 1; i <= n; ++i) {
		if (deg[i] & 1) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}
	find_eulertour(1);
	if (ans.size() != m + 1) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	for (int v : ans) {
		cout << v << ' ';
	}
 
	return 0;
}