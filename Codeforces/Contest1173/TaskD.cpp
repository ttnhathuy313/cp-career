#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, MOD = 998244353;
int n, fac[N], dp[N], subSize[N];
vector <int> adj[N];

int modPow(int x, int y) {
	x %= MOD;
	int res = 1;
	while (y) {
		if (y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

int inv(int x) {
	return modPow(x, MOD - 2);
}

void dfs(int u, int pre) {
	subSize[u] = 1;
	dp[u] = 1;
	int mauso = 1;
	int c = 0;
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
		subSize[u] += subSize[v];
		c++;
		dp[u] = dp[u] * dp[v] % MOD;
	}
	dp[u] = dp[u] * fac[c + (pre != -1)] % MOD;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % MOD;
	dfs(1, -1);

	cout << (dp[1] * n) % MOD << endl;

	return 0;
}