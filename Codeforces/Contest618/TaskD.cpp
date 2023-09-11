#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2e5 + 5, oo = 2e18;
int dp[N][2], n, x, y, ans[N];
vector <int> adj[N];

void dfs(int u, int pre) {
	vector <ii> w;
	w.clear();
	int s = 0, c = 0;
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
		c++;
		w.push_back(ii(dp[v][0], v));
		s += ans[v];
	}
	sort(w.begin(), w.end(), [](ii a, ii b) {
		return a.first - ans[a.second] > b.first - ans[b.second];
	});
	if (c == 0) return;
	
	dp[u][0] = w[0].first + s - ans[w[0].second] + 1;
	if (c > 1) {
		dp[u][1] = w[0].first + w[1].first + s - ans[w[0].second] - ans[w[1].second] + 2;
	} else dp[u][1] = 0;

	ans[u] = max(dp[u][0], dp[u][1]);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> x >> y;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (x > y) {
		bool star = false;
		for (int i = 1; i <= n; ++i) {
			bool t = true;
			for (int j : adj[i]) {
				if (adj[j].size() > 1) t = false;
			}
			star |= t;
		}
		if (star) {
			cout << x + (n - 2) * y << endl;
		} else cout << (n - 1) * y << endl;
		return 0;
	}
	dfs(1, -1);
	cout << ans[1] * x + (n - ans[1] - 1) * y << endl;

	return 0;
}