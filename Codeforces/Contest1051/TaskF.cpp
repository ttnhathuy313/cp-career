#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5, oo = 1e18, LOG = 22;
int n, m, bad[N], mark[N], id[N], cnt, tin[N], tout[N], h[N], dfsTime, above[N], P[N][LOG], depth[N];
vector <ii> adj[N], fake[N];
vector <int> d[50][N]

void dfs(int u) {
	mark[u] = 1;
	for (ii d : fake[u]) {
		int v = d.first, &w = d.second;
		if (mark[v]) {
			bad[u] = 1; bad[v] = 1;
			continue;
		}
		adj[u].push_back(d);
	}	
}

void dfs2(int u, int pre, int t = -1) {
	if (bad[u]) t = u;
	above[u] = t;
	tin[u] = ++dfsTime;
	for (ii d : adj[u]) {
		int v = d.first, w = d.second;
		if (v == pre) continue;
		h[v] = h[u] + w;
		depth[v] = depth[u] + 1;
		P[v][0] = u;
		dfs2(v, u, t);
	}
	tout[u] = ++dfsTime;
}

int get(int u, int k) {
	for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= k) {
		u = P[u][i];
		k -= (1 << i);
	}
	return u;
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	u = get(u, depth[u] - depth[v]);
	for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= depth[u] && P[u][i] != P[v][i])
		u = P[u][i], v = P[v][i];
	return P[u][0];
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		fake[u].push_back({v, d});
		fake[v].push_back({u, d});
	}
	dfs(1);
	for (int i = 1; i <= n; ++i) if (bad[i]) {
		cnt++;
		id[i] = cnt;
		priority_queue <ii, vector <ii>, greater <ii>> pq;
		while (!pq.empty()) pq.pop();
		for (int j = 1; j <= n; ++j) {
			d[cnt][j] = oo;
		}
		d[cnt][i] = 0;
		pq.push(ii(0, i));
		while (!pq.empty()) {
			int dist = pq.top().first, u = pq.top().second;
			pq.pop();
			if (dist > d[cnt][u]) continue;
			for (ii d : fake[u]) {
				int v = d.first, w = d.second;
				if (d[cnt][v] > d[cnt][u] + w) {
					d[cnt][v] = d[cnt][u] + w;
					pq.push({v, d[cnt][v]});
				}
			}
		}
	}
	dfs2(1, -1);
	for (int j = 1; j < LOG; ++j) {
		for (int u = 1; u <= n; ++u) {
			P[u][i] = P[P[u][i - 1]][i - 1];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		int uv;
		if (above[u] == -1 || above[v] == -1) {
			uv = max(above[u], above[v]);
		} else if (depth[above[u]] > depth[above[v]]) {
			uv = above[v];
			swap(u, v);
		} else uv = above[u];
		if (above[v] == -1) {
			cout << h[u] + h[v] - 2 * h[lca(u, v)];
		} else {
			cout << h[u] - h[uv] + d[id[uv]][v];
		}
	}

	return 0;
}