#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 605, oo = 1e18;
int n, dist[N][N], dag[N][N], g[N][N], L[N][N], mark[N], dp[N], useful[N][N], destination[N];
vector <ii> path[N];
vector <int> topo;

void get_topo(int u) {
	mark[u] = 1;
	for (int v = 1; v <= n; ++v) if (dag[u][v] && !mark[v])
		get_topo(v);
	topo.push_back(u);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dist[i][j] = (i == j ? 0 : oo);
		}
	}
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = w;
		g[u][v] = g[v][u] = w;
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	} // Done Floyd Algorithm

	int q;
	cin >> q;
	while (q--) {
		int u, v, l;
		cin >> u >> v >> l;
		L[u][v] = l;
	}

	for (int u = 1; u <= n; ++u) {
		//First, create the shortest path dag
		memset(dag, 0, sizeof dag);
		memset(mark, 0, sizeof mark);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) if (g[i][j]) {
				if (dist[u][i] + g[i][j] == dist[u][j]) {
					dag[i][j] = 1;
				}
			}
		}
		// Dp on dag, from each node, find the minimum (length - L) path from it to some of the destination
		topo.clear();
		get_topo(u);
		for (int i = 1; i <= n; ++i) dp[i] = oo;
		for (int i : topo) {
			if (L[u][i]) dp[i] = min(dp[i], -L[u][i]);
			for (int j = 1; j <= n; ++j) if (dag[j][i]) {
				dp[j] = min(dp[j], dp[i] + g[j][i]);
			}
		}
		for (int i = 1; i <= n; ++i) {
			destination[i] = oo;
			for (int j = 1; j <= n; ++j) {
				destination[i] = min(destination[i], dist[i][j] + dp[j]);
			}
		}

		// Check for each edge
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) if (g[i][j]) {
			if (dist[u][i] + g[i][j] + destination[j] <= 0) {
				useful[i][j] = useful[j][i] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) if (useful[i][j] && i < j) {
			cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}