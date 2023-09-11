#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 3005, oo = 1e18;
int dp[N][N], p[N], subSize[N], tot[N], n, c, avg;
vector <ii> adj[N];

void dfs(int u, int pre) {
	subSize[u] = 0; tot[u] = p[u];
	vector <vector <int>> tmp;
	tmp.assign(2, vector <int> (n + 5, oo));
	for (int i = 1; i <= n; ++i)
		tmp[0][i] = oo;
	int k = 0;
	tmp[0][0] = 0;
	for (ii vv : adj[u]) {
		int v = vv.first, w = vv.second;
		if (v == pre) continue;
		dfs(v, u);
		k++;
		tot[u] += tot[v];
		int cur = k & 1, prev = cur ^ 1;
		for (int i = 0; i <= n; ++i) {
			tmp[k & 1][i] = oo;
		}
		for (int i = 0; i <= subSize[u]; ++i) {
			for (int j = 0; j <= subSize[v]; ++j) {
				int more = abs(avg * subSize[v] + j - tot[v]);
				tmp[cur][i + j] = min(tmp[cur][i + j], tmp[prev][i] + dp[v][j] + w * ((more + c - 1) / c));
			}
		}
		subSize[u] += subSize[v];
	}
	subSize[u]++;
	dp[u][0] = tmp[k & 1][0];
	for (int i = 1; i <= n; ++i) {
		dp[u][i] = oo;
		dp[u][i] = min(tmp[k & 1][i], tmp[k & 1][i - 1]);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("EQUAKE.INP", "r", stdin);
	freopen("EQUAKE.OUT", "w", stdout);

	cin >> n >> c;
	int sum = 0, req = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		sum += p[i];
	}
	avg = sum / n;
	req = sum % n;
	// cerr << avg << ' ' << req << endl;
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dfs(1, -1);
	cout << dp[1][req] << endl;

	return 0;
}