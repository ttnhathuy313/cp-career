#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1005, MOD = 1e9 + 7, V = 1e6 + 5;
int n, m, g[N][N], inGraph[V], dp[V], mark[V];
vector <int> adj[V];

int num(int i, int j) {
	return (i - 1) * m + j;
}

struct dsu_t {
	int n;
	vector <int> lab;
	dsu_t() {}
	dsu_t(int _n) {
		this -> n = _n;
		lab.assign(n + 5, -1);
	}
	int root(int x) {
		return (lab[x] == -1 ? x : lab[x] = root(lab[x]));
	}
	void merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return;
		lab[y] = x;
	}
} d;

void dfs(int u) {
	mark[u] = 1;
	dp[u] = 1;
	for (int v : adj[u]) if (!mark[v]) {
		dp[u] = (dp[u] * dp[v]) % MOD;
	}
	dp[u]++; dp[u] %= MOD;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cave.IN", "r", stdin);
	freopen("cave.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			if (s[j - 1] == '#') g[i][j] = 0;
			else g[i][j] = 1;
		}
	}
	d = dsu_t(num(n, m));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) if (g[i][j]) {
			if (g[i][j - 1]) {
				d.merge(num(i, j - 1), num(i, j));
			} else inGraph[num(i, j)] = 1;
			if (g[i - 1][j]) {
				cerr << d.root(num(i, j)) << ' ' << d.root(num(i - 1, j)) << endl;
				adj[d.root(num(i, j))].push_back(d.root(num(i - 1, j)));
				adj[d.root(num(i - 1, j))].push_back(d.root(num(i, j)));
			}
		}
	}
	int nn = num(n, m), res = 0;
	for (int i = 1; i <= nn; ++i) if (!mark[i] && inGraph[i]) {
		dfs(i);
		res += dp[i];
		res %= MOD;
	}
	cout << res << endl;

	return 0;
}