#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, ans[N];
vector <int> adj[N];
bool mark[N];

void dfs(int u, vector <int> &d) {
	d.push_back(u);
	mark[u] = 1;
	for (int v : adj[u]) if (!mark[v]) dfs(v, d);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.inp", "r", stdin);
	freopen("TaskB.out", "w", stdout);

	int q;
	cin >> q;
	while (q--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) adj[i].clear();
		for (int i = 1; i <= n; ++i) {
			int j;
			cin >> j;
			adj[i].push_back(j);
		}
		for (int i = 1; i <= n; ++i) mark[i] = false, ans[i] = 0;
		for (int i = 1; i <= n; ++i) if (!mark[i]) {
			vector <int> d;
			d.clear();
			dfs(i, d);
			for (int v : d) ans[v] = d.size();
		}
		for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
		cout << endl;
	}

	return 0;
}