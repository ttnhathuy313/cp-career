#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 1e5 + 5, LOGA = 22;
int n, P[N][LOGA], d[N];
vector <int> adj[N], consist[N];
bool taken[N], elim[N];

void dfs(int u, int pre) {
	P[u][0] = pre;
	if (pre == -1) d[u] = 0;
	else d[u] = d[pre] + 1;
	for (int i = 1; i < LOGA; ++i) if ((1 << i) <= d[u])
		P[u][i] = P[P[u][i - 1]][i - 1];
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
	}
}

int LCA(int u, int v) {
	if (d[u] < d[v]) swap(u, v);
	for (int i = LOGA - 1; i >= 0; --i) if ((1 << i) <= d[u] - d[v])
		u = P[u][i];
	if (u == v) return v;
	for (int i = LOGA - 1; i >= 0; --i) if ((1 << i) <= d[u] && P[u][i] != P[v][i])
		u = P[u][i], v = P[v][i];
	return P[u][0];
}

bool cmp(ii a, ii b) {
	return d[LCA(a.first, a.second)] > d[LCA(b.first, b.second)];
}

void dfs2(int u, int pre, vector <int> &w) {
	for (int k : consist[u]) w.push_back(k);
	consist[u].clear();
	for (int v : adj[u]) {
		if (v == pre || taken[v]) continue;
		dfs2(v, u, w);
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	freopen("TaskC.out", "w", stdout);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	int m;
	cin >> m;
	vector <ii> path; path.clear();
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		path.push_back(ii(u, v));
	}
	sort(path.begin(), path.end(), cmp);
	for (int i = 0; i < m; ++i) {
		consist[path[i].first].push_back(i);
		consist[path[i].second].push_back(i);
	}
	memset(elim, 0, sizeof elim);
	vector <int> res; res.clear();
	for (int i = 0; i < m; ++i) if (!elim[i]) {
		int u = path[i].first, v = path[i].second;
		int head = LCA(u, v);
		res.push_back(head);
		vector <int> affected;
		affected.clear();
		dfs2(head, P[head][0], affected);
		for (int k : affected) elim[k] = true;
		taken[head] = true;
	}
	cout << res.size() << endl;
	for (int d : res) cout << d << ' ';

	return 0;
}