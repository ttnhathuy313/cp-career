#include <bits/stdc++.h>
 
using namespace std;
typedef pair <int, int> ii;
 
const int N = 1e5 + 5;
int n, deg[N], m;
bool mark[N];
vector <int> adj[N], path;
set <ii> still;
 
void hierholzer(int u) {
	mark[u] = 1;
	for (int v : adj[u]) if (still.find({u, v}) != still.end()) {
		still.erase({u, v});
		still.erase({v, u});
		hierholzer(v);
	}
	path.push_back(u);
}
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
 	freopen("TaskB.inp", "r", stdin);
 	freopen("TaskB.out", "w", stdout);
	int tc;
	tc = 1;
	while (tc--) {
		memset(deg, 0, sizeof deg);
		memset(mark, 0, sizeof mark);
		path.clear();
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			adj[i].clear();
		int st = 0;
		for (int i = 1; i <= m; ++i) {
			int u, v;
			cin >> u >> v;
			st = u;
			adj[u].push_back(v);
			adj[v].push_back(u);
			still.insert({u, v});
			still.insert({v, u});
			deg[u]++; deg[v]++;
		}
		int res = n;
		for (int i = 1; i <= n; ++i) if (deg[i] & 1) {
			adj[n + 1].push_back(i);
			adj[i].push_back(n + 1);
			still.insert({i, n + 1}); still.insert({n + 1, i});
			--res;
		}
		for (int i = 1; i <= n; ++i) if (!mark[i] && deg[i]) {
			hierholzer(i);
			for (int j = 0; j < path.size() - 1; ++j) {
				if (path[j] != n + 1 && path[j + 1] != n + 1)
					cout << path[j] << ' ' << path[j + 1] << '\n';
			}
			path.clear();
		}
	}
 
	return 0;
}