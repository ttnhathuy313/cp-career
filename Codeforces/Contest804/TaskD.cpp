#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, m, q, down[N], up[N], f[N], comp[N], cc = 0, diameter[N];
vector <int> adj[N], incl[N], val[N];
vector <vector <int>> pref;
map <ii, double> res;

void dfs1(int u, int pre) {
	comp[u] = cc;
	incl[cc].push_back(u);
	down[u] = 0;
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs1(v, u);
		down[u] = max(down[u], down[v] + 1);
	}
}

void dfs2(int u, int pre) {
	comp[u] = cc;
	multiset <int> S; S.clear();
	for (int v : adj[u]) {
		if (v == pre) continue;
		S.insert(down[v]);
	}
	if (pre == -1) up[u] = 0;
	for (int v : adj[u]) {
		if (v == pre) continue;
		up[v] = up[u] + 1;
		S.erase(S.find(down[v]));
		if (!S.empty()) up[v] = max(up[v], *S.rbegin() + 2);
		S.insert(down[v]);
	}
	for (int v : adj[u]) if (v != pre) dfs2(v, u);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m >> q;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(comp, -1, sizeof comp);
	for (int i = 1; i <= n; ++i) if (comp[i] == -1) {
		++cc;
		dfs1(i, -1);
	}
	cc = 0;
	memset(comp, -1, sizeof comp);
	for (int i = 1; i <= n; ++i) if (comp[i] == -1) {
		++cc;
		dfs2(i, -1);
	}
	for (int i = 1; i <= n; ++i) {
		f[i] = max(up[i], down[i]);
		diameter[comp[i]] = max(diameter[comp[i]], f[i]);
	}
	pref.resize(cc + 4);
	for (int i = 1; i <= cc; ++i) {
		pref[i].resize(incl[i].size() + 4);
		for (int v : incl[i]) val[i].push_back(f[v]);
		sort(val[i].begin(), val[i].end());
		for (int j = 0; j < val[i].size(); ++j) {
			if (j == 0) pref[i][j] = val[i][0];
			else pref[i][j] = pref[i][j - 1] + val[i][j];
		}
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		if (comp[u] == comp[v]) {
			cout << -1 << endl;
			continue;
		}
		if (incl[comp[u]].size() > incl[comp[v]].size())
			swap(u, v);
		int x = comp[u], y = comp[v];
		if (res.find({x, y}) != res.end()) {
			cout << fixed << setprecision(9) << res[{x, y}] << endl;
			continue;
		}	
		int ans = 0;
		int sx = val[comp[u]].size(), sy = val[comp[v]].size();
		for (int i : incl[comp[u]]) {
			int dia = max(diameter[comp[u]], diameter[comp[v]]);
			int bound = dia - f[i] - 1;
			if (val[comp[v]].back() <= bound) {
				ans += sy * dia;
				continue;
			}
			int j = upper_bound(val[comp[v]].begin(), val[comp[v]].end(), bound) - val[comp[v]].begin();
			if (j == 0) ans += pref[comp[v]][sy - 1] + sy + f[i] * sy;
			else ans += pref[comp[v]][sy - 1] - pref[comp[v]][j - 1] + j * dia + (f[i] + 1) * (sy - j);
		}
		res[{x, y}] = 1.0 * ans / (sx * sy);
		cout << fixed << setprecision(9) << 1.0 * ans / (sx * sy) << endl;
	}

	return 0;
}