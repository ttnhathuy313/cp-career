#include <bits/stdc++.h>

using namespace std;

const int N = 55;
int n, m, sz;
long long p[N];
bool mark[N];
vector <int> adj[N];

void dfs(int u) {
	sz++;
	mark[u] = 1;
	for (int v : adj[u]) if (!mark[v])
		dfs(v);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n >> m;
	p[0] = 1;
	for (int i = 1; i <= n; ++i)
		p[i] = p[i - 1] * 2;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	long long res = 1;
	memset(mark, 0, sizeof mark);
	for (int i = 1; i <= n; ++i) if (!mark[i]) {
		sz = 0;
		dfs(i);
		res *= p[sz - 1];
	}
	cout << res << endl;

	return 0;
}