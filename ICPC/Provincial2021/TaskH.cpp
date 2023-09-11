#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, a[N], down[N], q, Up[N], ans[N];
vector <int> adj[N];
vector <ii> Q[N];
vector <int> suf[N];

void dfs1(int u, int pre) {
	suf[u].assign((int)adj[u].size() + 5, 0);
	int j = 0;
	bool isLeaf = 1;
	for (int v : adj[u]) {
		if (v != pre) {
			isLeaf = false;
			dfs1(v, u);
			down[u] = max(down[u], down[v]);
			suf[u][j] = down[v] + 1;
		}
		j++;
	}
	for (int i = (int)adj[u].size() - 2; i >= 0; --i) {
		suf[u][i] = max(suf[u][i], suf[u][i + 1]);
	}
	down[u]++;
	if (isLeaf) down[u] = 0;
}

void dfs2(int u, int pre, int val) {
	int curMx = 0;
	if (pre == -1) Up[u] = 0;
	else {
		Up[u] = max(Up[pre], val) + 1;
	}
	int j = 0;
	vector <int> w; w.clear();
	if (pre != -1) w.push_back(Up[u]);
	for (int v : adj[u]) {
		if (v != pre) {
			w.push_back(down[v] + 1);
			dfs2(v, u, max(curMx, suf[u][j + 1]));
			curMx = max(curMx, down[v] + 1);
		}
		j++;
	}
	sort(w.begin(), w.end());
	for (ii D : Q[u]) {
		int t = D.first, id = D.second;
		int safe = upper_bound(w.begin(), w.end(), t) - w.begin();
		ans[id] = (int)adj[u].size() - safe;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("TaskH.INP", "r", stdin);
	// freopen("TaskH.OUT", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= q; ++i) {
		int x, t;
		cin >> x >> t;
		Q[x].push_back({t, i});
	}
	dfs1(1, -1);
	dfs2(1, -1, 0);
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << endl;
	}

	return 0;
}