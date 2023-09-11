#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, a[N], xs[N], cur, cst, xor_sum, dp[N], xs2[N];
vector <int> adj[N];

void dfs(int u, int pre) {
	xs[u] = a[u];
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
		if (xs[v] != xor_sum) xs[u] ^= xs[v];
	}
}

void dfs2(int u, int pre) {
	xs2[u] = a[u];
	for (int v : adj[u]) {
		if (v == pre) continue;
		if (xs[v] == xor_sum) {
			dp[u]++;
			continue;
		}
		dfs2(v, u);
		dp[u] += dp[v];
		xs2[u] ^= xs2[v];
	}
}

void dfs3(int u, int pre) {
	cur ^= a[u];
	for (int v : adj[u]) {
		if (v == pre) continue;
		if (xs[v] == xor_sum) {
			cst++;
			continue;
		}
		if (xs2[v] == 0) {
			cst++;
			continue;
		}
		dfs(v, u);
	}
}


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		xor_sum = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			xor_sum ^= a[i];
			xs[i] = -1;
			xs2[i] = -1;
			adj[i].clear();
			dp[i] = 0;
		}
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if (xor_sum == 0) {
			cout << "YES" << endl;
			continue;
		}
		cur = 0; cst = 0;
		dfs(1, -1);
		dfs2(1, -1);
		dfs3(1, -1);
		if ((cur == xor_sum || cur == 0) && cst > (cur == 0) && cst <= k - 1) {
			cout << "YES" << endl;
			continue;
		} 
		cout << "NO" << endl;
	}

	return 0;
}