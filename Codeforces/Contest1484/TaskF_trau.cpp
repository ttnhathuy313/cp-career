#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 605, oo = 1e18;
int n, dist[N][N], dag[N][N], g[N][N], L[N][N], mark[N], dp[N], useful[N][N];
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
	freopen("TaskF.ANS", "w", stdout);

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

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) if (g[i][j]) {
			for (int u = 1; u <= n; ++u) {
				for (int v = 1; v <= n; ++v) if (L[u][v]) {
					if (dist[u][i] + g[i][j] + dist[j][v] <= L[u][v]) {
						useful[i][j] = useful[j][i] = 1;
					}
				}
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