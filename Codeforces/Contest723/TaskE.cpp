#include <bits/stdc++.h>

using namespace std;

const int N = 205;
int n, deg[N], m;
bool exist[N][N], mark[N];
vector <int> adj[N], path;

void hierholzer(int u) {
	mark[u] = 1;
	for (int v : adj[u]) if (exist[u][v]) {
		exist[u][v] = exist[v][u] = 0;
		hierholzer(v);
	}
	path.push_back(u);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(exist, 0, sizeof exist);
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
			exist[u][v] = exist[v][u] = 1;
			deg[u]++; deg[v]++;
		}
		int res = n;
		for (int i = 1; i <= n; ++i) if (deg[i] & 1) {
			adj[n + 1].push_back(i);
			adj[i].push_back(n + 1);
			exist[i][n + 1] = exist[n + 1][i] = 1;
			--res;
		}
		cout << res << endl;
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