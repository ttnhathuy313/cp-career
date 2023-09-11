#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, K, p[N], s[N];
vector <int> adj[N];
map <ii, long long> dp;

long long calc(int u, int k) {
	if (k == 0) {
		return 0;
	}
	if (dp.find({u, k}) != dp.end()) {
		return dp[{u, k}];
	}
	int nChild = adj[u].size();
	if (nChild == 0) {
		return dp[{u, k}] = 1LL * s[u] * k;
	}
	int du = k % nChild, lw = k / nChild;
	if (nChild == 1) {
		return dp[{u, k}] = calc(adj[u][0], k) + 1LL * s[u] * k;
	}
	vector <pair <long long, int>> temp;
	temp.clear();

	for (int v : adj[u]) {
		temp.push_back({calc(v, lw + 1) - calc(v, lw), v});
	}

	long long cur = 0;
	sort(temp.begin(), temp.end(), greater <pair <long long, int>>());
	for (int i = 0; i < du; ++i) {
		cur += temp[i].first;
	}
	for (int i = 0; i < temp.size(); ++i) {
		cur += calc(temp[i].second, lw);
	}
	cur += 1LL * s[u] * k;
	return dp[{u, k}] = cur;
}

void solve() {
	dp.clear();
	cin >> n >> K;
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
	}
	for (int i = 2; i <= n; ++i) {
		cin >> p[i];
		adj[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	cout << calc(1, K) << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}