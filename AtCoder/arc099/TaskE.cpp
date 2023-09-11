#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 705;
int n, m, mark[N];
bool mat[N][N], dp[N][N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j)
			mat[i][j] = mat[j][i] = 1;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		mat[u][v] = mat[v][u] = 0;
	}
	// for (int i = 1; i <= n; ++i) {
	// 	for (int j = i + 1; j <= n; ++j) if (mat[i][j])
	// 		cerr << i << ' ' << j << endl;
	// }
	vector <ii> comp; comp.clear();
	int cc = 0; comp.push_back({0, 0});
	for (int i = 1; i <= n; ++i) if (!mark[i]) {
		queue <int> q; ++cc;
		while (!q.empty()) q.pop();
		q.push(i);
		mark[i] = 1;
		vector <int> V; V.clear();
		while (!q.empty()) {
			int u = q.front(); q.pop();
			V.push_back(u);
			for (int v = 1; v <= n; ++v) if (mat[u][v]) {
				if (!mark[v]) {
					q.push(v);
					mark[v] = ((mark[u] - 1) ^ 1) + 1;
				} else {
					if (mark[v] != ((mark[u] - 1) ^ 1) + 1) {
						cerr << v << endl;
						cout << -1 << endl;
						return 0;
					}
				}
			}
		}
		int p1, p2; p1 = p2 = 0;
		for (int u : V) {
			if (mark[u] == 1) p1++;
			else if (mark[u] == 2) p2++;
		}
		comp.push_back({p1, p2});
	}
	dp[0][0] = 1;
	for (int i = 1; i <= cc; ++i) {
		for (int j = 0; j <= n; ++j) if (dp[i - 1][j]) {
			dp[i][j + comp[i].first] = dp[i][j + comp[i].second] = 1;
		}
	}
	int res = (int)1e9;
	for (int i = 1; i <= n; ++i) if (dp[cc][i]) {
		res = min(res, i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);
	}
	cout << res << endl;

	return 0;
}