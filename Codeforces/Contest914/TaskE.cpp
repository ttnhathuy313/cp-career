#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, h[N], c[N], subSize[N], ans[N], cnt[(1 << 20)], par[N], tmp[N];
vector <int> adj[N];
bool block[N];

void calcsum(int u, int pre) {
	subSize[u] = 1;
	par[u] = pre;
	for (int v : adj[u]) {
		if (v == pre || block[v]) continue;
		calcsum(v, u);
		subSize[u] += subSize[v];
	}
}

void solveTree(int centroid);
void go(int entryPoint) {
	calcsum(entryPoint, -1);
	int maxSz = subSize[entryPoint], centroid = entryPoint;
	queue <int> q; while (!q.empty()) q.pop();
	q.push(entryPoint);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		int sz = subSize[entryPoint] - subSize[u];
		for (int v : adj[u]) if (!block[v] && v != par[u]) {
			q.push(v);
			sz = max(sz, subSize[v]);
		}
		if (sz < maxSz) {
			maxSz = sz;
			centroid = u;
		}
	}
	solveTree(centroid);
	block[centroid] = 1;
	for (int v : adj[centroid]) if (!block[v])
		go(v);
}

void get(int u, int pre, vector <int> &w) {
	w.push_back(u);
	for (int v : adj[u]) if (v != pre && !block[v])
		get(v, u, w);
}

void dfs(int u, int pre) {
	if (pre == -1) h[u] = 0;
	else h[u] = h[pre];
	h[u] ^= (1 << c[u]);
	cnt[h[u]]++;
	for (int v : adj[u]) if (v != pre && !block[v])
		dfs(v, u);
}

void dfs2(int u, int pre) {
	for (int v : adj[u]) if (v != pre && !block[v]) {
		dfs2(v, u);
		tmp[u] += tmp[v];
		tmp[v] = 0;
	}
	ans[u] += tmp[u];
	if (pre == -1) tmp[u] = 0;
}

void solveTree(int u) {
	dfs(u, -1);
	int cross = 0;
	for (int v : adj[u]) if (!block[v]) {
		vector <int> w; w.clear();
		get(v, u, w);
		for (int t : w) {
			if (__builtin_popcount(h[t]) <= 1) {
				tmp[t]++;
			}
			cnt[h[t]]--;
		}
		cnt[h[u]]--;
		for (int t : w) {
			for (int j = 0; j < 20; ++j) if (cnt[h[t] ^ (1 << c[u]) ^ (1 << j)] != 0) {
				tmp[t] += cnt[h[t] ^ (1 << c[u]) ^ (1 << j)];
				cross += cnt[h[t] ^ (1 << c[u]) ^ (1 << j)];
			}
			tmp[t] += cnt[h[t] ^ (1 << c[u])];
			cross += cnt[h[t] ^ (1 << c[u])];
		}
		cnt[h[u]]++;
		for (int t : w) cnt[h[t]]++;
	}
	tmp[u] = 1 - cross / 2;
	dfs2(u, -1);
	vector <int> w; w.clear();
	get(u, -1, w);
	for (int v : w) {
		tmp[v] = 0;
		cnt[h[v]] = 0;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	string s;
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; ++i) {
		c[i] = s[i] - 'a';
	}
	go(1);
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';

	return 0;
}