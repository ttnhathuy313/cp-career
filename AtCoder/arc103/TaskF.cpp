#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, d[N], subSize[N], f[N], g[N], tot;
map <int, int> ind;
vector <int> adj[N];

void dfs(int u, int pre, int s) {
	g[u] = s;
	for (int v : adj[u]) {
		if (v == pre) continue;
		tot += subSize[v];
		dfs(v, u, s - 2 * subSize[v] + n);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
		f[i] = d[i];
		ind[d[i]] = i;
	}
	vector <ii> res; res.clear();
	sort(d + 1, d + 1 + n);
	for (int i = 1; i <= n; ++i)
		subSize[i] = 1;
	for (int i = n; i >= 2; --i) {
		int v = ind[d[i]];
		int du = d[i] + 2 * subSize[v] - n;
		if (ind.find(du) == ind.end()) {
			cout << -1 << endl;
			return 0;
		}
		int u = ind[du];
		if (u == v) {
			cout << -1 << endl;
			return 0;
		}
		subSize[u] += subSize[v];
		adj[u].push_back(v);
		adj[v].push_back(u);
		res.push_back({u, v});
	}
	dfs(ind[d[1]], -1, 0);
	for (int i = 1; i <= n; ++i) if (f[i] != g[i] + tot) {
		cout << -1 << endl;
		return 0;
	}
	for (ii d : res)
		cout << d.first << ' ' << d.second << endl;

	return 0;
}