#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 2e3 + 5;
int n, dp[N][N][2][2], par[N], tin[N], tout[N], dfsTime, pushed[N][N], res;
vector <int> adj[N];
queue <ii> q[N];
string s;

void upd(int &a, int b) {
	a = max(a, b);
}

void dfs1(int u, int pre) {
	par[u] = pre;
	tin[u] = ++dfsTime;
	q[1].push({u, u});
	pushed[u][u] = 1;
	dp[u][u][0][0] = 1;

	for (int v : adj[u]) {
		if (v == pre) {
			continue;
		}
		if (s[u] == s[v]) {
			dp[u][v][0][0] = 2;
		} else dp[u][v][1][1] = 0;
		pushed[u][v] = 1;
		q[2].push({u, v});
		dfs1(v, u);
	}
	tout[u] = ++dfsTime;
}

void init() {
	dfsTime == 0;
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
		for (int j = 1; j <= n; ++j) {
			pushed[i][j] = false;
			memset(dp[i][j], 0, sizeof dp[i][j]);
		}
		while (!q[i].empty()) {
			q[i].pop();
		}
	}
}

void solve() {
	cin >> n >> s;
	init();
	s = ' ' + s;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	res = 1;
	dfs1(1, -1);


	for (int len = 1; len < n; ++len) {
		while (!q[len].empty()) {
			auto d = q[len].front();
			q[len].pop();
			int u = d.first, v = d.second;
			// cerr << "dp[" << u << "][" << v << "][0][0] = " << dp[u][v][0][0] << endl; 
			// cerr << "dp[" << u << "][" << v << "][0][1] = " << dp[u][v][0][1] << endl; 
			// cerr << "dp[" << u << "][" << v << "][1][0] = " << dp[u][v][1][0] << endl; 
			// cerr << "dp[" << u << "][" << v << "][1][1] = " << dp[u][v][1][1] << endl; 
			bool print = (u == 4 && v == 4);
			bool anc = (tin[u] <= tin[v] && tout[u] >= tout[v]);
			for (int vv : adj[v]) {
				if (anc && vv == par[v]) {
					continue;
				}

				if (!anc && vv == par[v]) {
					continue;
				}
				for (int avail_u = 0; avail_u < 2; ++avail_u) {
					for (int avail_v = 0; avail_v < 2; ++avail_v) if (~dp[u][v][avail_u][avail_v]) {
						int cur = dp[u][v][avail_u][avail_v];
						upd(dp[u][vv][avail_u][1], cur);
						if (avail_u == 1 && s[vv] == s[u]) {
							upd(dp[u][vv][0][0], cur + 2);
						}

						if (!pushed[u][vv]) {
							q[len + 1].push({u, vv});
							pushed[u][vv] = 1;
						}
					}
				}
			}
			for (int uu : adj[u]) {
				if (anc && uu != par[u] && tin[uu] <= tin[v] && tout[uu] >= tout[v]) {
					continue;
				}
				if (!anc && uu == par[u]) {
					continue;
				}
				if (u == v && uu != par[u]) {
					continue;
				}

				for (int avail_u = 0; avail_u < 2; ++avail_u) {
					for (int avail_v = 0; avail_v < 2; ++avail_v) {
						int cur = dp[u][v][avail_u][avail_v];
						upd(dp[uu][v][1][avail_v], cur);
						if (avail_v == 1 && s[v] == s[uu]) {
							upd(dp[uu][v][0][0], cur + 2);
						}

						if (!pushed[uu][v]) {
							q[len + 1].push({uu, v});
							pushed[uu][v] = 1;
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int a1 = 0; a1 < 2; ++a1) {
				for (int a2 = 0; a2 < 2; ++a2) {
					upd(res, dp[i][j][a1][a2]);
				}
			}
		}
	}

	cout << res << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}