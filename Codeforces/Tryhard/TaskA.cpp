#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int down[N], up[N], s[N], n;
vector <int> adj[N];

void dfs1(int u, int pre) {
	down[u] = 1;
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs1(v, u);
		if (down[v] == 1) down[u] = 0;
		s[u] += down[v];
	}
}

void dfs2(int u, int pre) {
	if (~pre) {
		if (!up[pre]) up[u] = true;
		if (s[pre] - down[u] != 0) up[u] = true;
	} else up[u] = 1;
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs2(v, u);
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1, -1);
	dfs2(1, -1);
	for (int i = 1; i <= n; ++i) {
		if (up[i] == 1 && down[i] == 1) cout << 1 << ' ';
		else cout << 2 << ' ';
	}

	return 0;
}