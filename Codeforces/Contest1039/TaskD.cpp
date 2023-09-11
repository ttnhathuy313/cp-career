// anti dfs
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, m, f[N], g[N], memo[N], par[N];
vector <int> adj[N], topo;

void dfs(int u, int pre) {
	par[u] = pre;
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
	}
	topo.push_back(u);
}

int solve(int k) {
	if (~memo[k]) return memo[k];
	memo[k] = 0;
	for (int i = 1; i <= n; ++i) g[i] = 1;
	memset(f, 0, sizeof f);
	for (int u : topo) {
		if (f[u])memo[k]++;
		else {
			if (g[u] + g[par[u]] >= k) f[par[u]] = 1;
			else g[par[u]] = max(g[par[u]], g[u] + 1);
		}
	}
	return memo[k];
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(memo, -1, sizeof memo);
	dfs(1, 0); memo[1] = n;
	for (int i = 1; i <= min(400, n); ++i)
		cout << solve(i) << endl;
	int i = min(400, n);
	while (i < n) {
		i++;
		int cur = solve(i);
		int l = i, r = n, id = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (solve(mid) != cur) r = mid - 1;
			else l = mid + 1, id = mid;
		}
		for (int j = i; j <= id; ++j) cout << cur << endl;
		i = id;
	}

	return 0;
}