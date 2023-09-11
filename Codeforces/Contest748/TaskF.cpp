#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, k, subSize[N], mark[N];
vector <int> adj[N];

void get(int u, int pre, vector <int> &w) {
	if (mark[u]) w.push_back(u);
	for (int v : adj[u]) {
		if (v == pre) continue;
		get(v, u, w);
	}
}

void dfs(int u, int pre) {
	int mx = 0;
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
		subSize[u] += subSize[v];
	}
}

int get_ct(int u, int pre) {
	for (int v : adj[u]) {
		if (v == pre) continue;
		if (subSize[v] > k) return get_ct(v, u);
	}
	return u;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= 2 * k; ++i) {
		int v;
		cin >> v;
		subSize[v] = 1;
		mark[v] = 1;
	}
	dfs(1, -1);
	int u = get_ct(1, -1);
	cout << 1 << endl << u << endl;
	vector <int> cur; cur.clear();
	get(u, -1, cur);
	for (int i = 0; i < k; ++i) 
		cout << cur[i] << ' ' << cur[i + k] << ' ' << u << endl;

	return 0;
}