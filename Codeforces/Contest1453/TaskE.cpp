#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, dp[N];
vector <int> adj[N];

void dfs(int u, int pre, int depth, int mid) {
	int numChild = 0;
	for (int v : adj[u]) {
		if (v == pre) continue;
		numChild++;
		dfs(v, u, depth + 1, mid);
	}
	if (numChild == 0) {
		dp[u] = depth;
		return;
	}
	int cntk = 0, mx = 0, mi = n;
	for (int v : adj[u]) if (v != pre) {
		if (dp[v] == -1) {
			dp[u] = -1;
			return;
		}
		if (dp[v] - depth + 1 > mid) cntk++;
		if (cntk == 2) {
			dp[u] = -1;
			return;
		}
		mx = max(mx, dp[v]);
		mi = min(mi, dp[v]);
	}
	if (cntk == 0) dp[u] = mi;
	else dp[u] = mx;
}

bool check(int mid) {
	dfs(1, -1, 0, mid);
	if (~dp[1]) {
		return (dp[1] <= mid);
	} else return false;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		adj[i].clear();
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int l = 1, r = n, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}