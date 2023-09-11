#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, d[N];
vector <int> adj[N];
double res;

void dfs(int u, int pre) {
	if (pre == -1) d[u] = 1;
	else d[u] = d[pre] + 1;
	res += 1.0 / d[u];
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	cout << fixed << setprecision(9) << res << endl;

	return 0;
}