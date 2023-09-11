#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, up[N], down[N], ans[N], k, res, leaf[N], ld[N];
vector <int> adj[N];

void gop(int &a, int &b, int c) {
	if (c >= a) {
		swap(a, b);
		a = c;
	} else if (c > b) {
		b = c;
	}
}

void dfs(int u, int pre) {
	int cnt = 0, x1=  0, x2 = 0;
	for (int v : adj[u]) {
		if (v == pre) continue;
		leaf[u]++;
		dfs(v, u);
		gop(x1, x2, down[v] + 1);
		ld[u] = max(ld[u], ld[v]);
		down[u] = max(down[u], down[v] + 1);
	}
	ld[u] = max(ld[u], x1 + x2);
}

void dfs2(int u, int pre) {
	vector <int> p1, p2, s1, s2;
	p1.assign(adj[u].size(), 0); p2.assign(adj[u].size(), 0); s1.assign(adj[u].size(), 0); s2.assign(adj[u].size(), 0);
	int i = 0;
	vector <int> V; V.clear(); V.push_back(up[u]);
	for (int id = 0; id < adj[u].size(); ++id) {
		if (adj[u][id] == pre) continue;
		p1[i] = (i == 0 ? 0 : p1[i - 1]), p2[i] = (i == 0 ? 0 : p2[i - 1]);
		gop(p1[i], p2[i], down[adj[u][id]] + 1);
		V.push_back(down[adj[u][id]] + 1);
		i++;
	}
	sort(V.begin(), V.end(), greater <int> ());
	if (V.size() >= 4 && k == 2) {
		res = max(res, V[0] + V[1] + V[2] + V[3]);
	}
	i--;
	for (int id = adj[u].size() - 1; id >= 0; --id) {
		if (adj[u][id] == pre) continue;
		s1[i] = (i == leaf[u] - 1 ? 0 : s1[i + 1]), s2[i] = (i == leaf[u] - 1 ? 0 : s2[i + 1]);
		gop(s1[i], s2[i], down[adj[u][id]] + 1);
		i--;
	}
	if (!leaf[u]) {
		res = max(res, ans[u] - 1);
		return;
	}
	res = max(res, s1[0] + s2[0]);
	if (k == 2) {
		res = max(res, ans[u] + ld[u]);
		res = max(res, up[u] + s1[0] + s2[0]);
	}
	i = 0;
	for (int id = 0; id < adj[u].size(); ++id) {
		int v = adj[u][id];
		if (v == pre) continue;
		up[v] = max(up[u] + 1, max(i == 0 ? 0 : p1[i - 1], i == leaf[u] - 1 ? 0 : s1[i + 1]) + 1);
		int x1 = up[u], x2 = 0;
		if (i) gop(x1, x2, p1[i - 1]), gop(x1, x2, p2[i - 1]);
		if (i != leaf[u] - 1) gop(x1, x2, s1[i + 1]), gop(x1, x2, s2[i + 1]);
		ans[v] = max(ans[u], x1 + x2);
		dfs2(v, u);
		i++;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("PATROL.INP", "r", stdin);
	freopen("PATROL.OUT", "w", stdout);

	cin >> n >> k; 
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	dfs2(1, -1);
	cout << 2 * (n - 1) - res + k << endl;

	return 0;
}