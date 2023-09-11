#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, m, tin[N], low[N], dfsTime, biCount, biComp[N], isCut[N], sz[N], res, cutsum[N], subSize[N];
vector <int> adj[N], include[N], near[N];
stack <int> S;

void dfs(int u, int pre) {
	tin[u] = low[u] = ++dfsTime;
	S.push(u);
	int nchild = 0;
	for (int v : adj[u]) {
		if (v == pre) continue;
		nchild++;
		if (!tin[v]) {
			dfs(v, u);
			if (low[v] >= tin[u]) {
				isCut[u] = 1;
				biCount++;
				cerr << "Bi-connected components no" << biCount << " include : ";
				while (S.top() != u) {
					int v = S.top();
					cerr << v << ' ';
					S.pop();
					include[biCount].push_back(v);
					biComp[v] = biCount;
				}
				include[biCount].push_back(u);
				cerr << u << endl;
			}
			low[u] = min(low[u], low[v]);
		} else low[u] = min(low[u], tin[v]);
	}
	if (pre == -1) {
		isCut[u] = (nchild > 1);
	}
}

void dfs2(int u, int pre) {
	subSize[u] = sz[u];
	for (int v : near[u]) {
		if (v == pre) continue;
		dfs2(v, u);
		subSize[u] += subSize[v];
	}
	if (u > n) {
		int bf = 0, tmp = 0;
		if (~pre) bf = n - subSize[u];
		// cerr << bf << endl;
		for (int v : near[u]) {
			if (v == pre) continue;
			int cur = sz[v] - 1;
			// cerr << "	" << cur << ' ' << cur * bf << endl;
			tmp += cur * bf;
			bf += cur;
		}
		res -= tmp * 2;
		return;
	}
	if (u > n || cutsum[u] < 2) return;
	int bf = 0, tmp = 0;
	if (~pre) bf = n - subSize[u];
	for (int v : near[u]) {
		if (v == pre) continue;
		int cur = subSize[v] - 1;
		tmp += cur * bf * (sz[u] + cutsum[u] - 2);
		bf += cur;
	}
	res = res + (tmp * 2);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("APIO18_duathlon.INP", "r", stdin);
	freopen("APIO18_duathlon.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	for (int i = 1; i <= biCount; ++i) {
		sz[i] = include[i].size();
		res += sz[i] * (sz[i] - 1) * (sz[i] - 2);
		res += (n - sz[i]) * (sz[i] - 1) * (sz[i] - 1) * 2;
		for (int u : include[i]) if (isCut[u]) {
			cutsum[i]++;
			near[n + u].push_back(i);
			near[i].push_back(n + u);
		}
	}
	dfs2(1, -1);
	cout << res << endl;

	return 0;
}