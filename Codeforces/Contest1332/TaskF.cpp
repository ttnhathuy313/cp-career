#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 3e5 + 5, MOD = 998244353;
int n, dp[N][5];
vector <int> adj[N];

void mult(int &a, int b) {
	b %= MOD;
	a = (a * b) % MOD;
}

void sub(int &a, int b) {
	a = (a - b + MOD) % MOD;
}

void dfs(int u, int pre) {
	dp[u][0] = dp[u][1] = dp[u][2] = 1;
	int prod = 1;
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
		mult(prod, (dp[v][0] + dp[v][1] + dp[v][2]));
		mult(dp[u][0], dp[v][1] + dp[v][2] + dp[v][0]);
		mult(dp[u][1], 3 * dp[v][0] + 2 * dp[v][1] + 2 * dp[v][2]);
		mult(dp[u][2], 2 * dp[v][0] + 2 * dp[v][1] + dp[v][2]);
	}
	sub(dp[u][1], prod);
	sub(dp[u][2], prod);
	// cerr << "dp[" << u << "][0] : " << dp[u][0] << endl;
	// cerr << "dp[" << u << "][1] : " << dp[u][1] << endl;
	// cerr << "dp[" << u << "][2] : " << dp[u][2] << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	cout << (dp[1][1] + dp[1][2] + dp[1][0] - 1) % MOD << endl;

	return 0;
}