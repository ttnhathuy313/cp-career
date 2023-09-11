#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 20;
int n, m, g[N][N], f[N][(1 << N) + 5], adj[N], lg[1 << N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u][v] = g[v][u] = 1;
		adj[u] |= (1 << v);
		adj[v] |= (1 << u);
	}
	for (int i = 0; i < n; ++i) {
		f[i][(1 << i)] = 1;
	}
	for (int i = 0; i < n; ++i) {
		lg[1 << i] = i;
	}
	for (int mask = 0; mask < (1 << n); ++mask) {
		if (mask == (1 << n) - 1) continue;
		for (int i = 0; i < n; ++i) if (f[i][mask]) {
			int lst = lg[(mask & -mask)];
 			for (int j = 0; j < n; ++j) if (j > lst && (mask & (1 << j)) == 0 && g[i][j]) {
				f[j][mask | (1 << j)] += f[i][mask];
			}
		}
	}
	int res = 0;
	for (int mask = 0; mask < (1 << n); ++mask) {
		if (__builtin_popcount(mask) <= 2) continue;
		for (int i = 0; i < n; ++i) {
			int lst = lg[mask & -mask];
			if (g[i][lst] && f[i][mask]) {
				cerr << "	" << lst << ' ' << i << endl;
				res += f[i][mask];
			}
		}
	}
	cout << res / 2 << endl;

	return 0;
}