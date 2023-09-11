#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 3e5 + 5;
int n, b[N], dp[N][2];
vector <int> adj[N];

/*
	dp[u][0] : no edge going up from u
	dp[u][1] : an edge going up from u
*/

void dfs(int u, int pre) {
	vector <ii> W;
	W.clear();
	int tot = 0;
	for (int v : adj[u]) {
		if (v == pre) {
			continue;
		}
		dfs(v, u);
		W.push_back({dp[v][0] - dp[v][1], v});
		tot += dp[v][1];
	}
	sort(W.begin(), W.end(), greater <ii>());

	dp[u][0] = b[0] + tot;
	dp[u][1] = b[1] + tot;

	int out_going = 0;

	for (ii d : W) {
		int v = d.second, delta = d.first;
		tot += delta;
		out_going++;
		dp[u][0] = max(dp[u][0], tot + b[out_going]);
		dp[u][1] = max(dp[u][1], tot + b[out_going + 1]);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskJ.INP", "r", stdin);
	freopen("TaskJ.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i - 1];
	}

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, -1);
	cout << dp[1][0] << endl;

	return 0;
}