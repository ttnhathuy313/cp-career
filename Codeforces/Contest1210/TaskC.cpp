#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5, MOD = 1e9 + 7;
int n, x[N], res;
vector <int> adj[N];
map <int, vector <ii>> g;

void dfs(int u, int pre) {
	if (pre == -1) {
		g[u].push_back({x[u], 1});
		res += x[u];
	} else {
		map <int, int> mp; mp.clear();
		mp[x[u]]++;
		for (ii val : g[pre]) mp[__gcd(x[u], val.first)] += val.second;
		vector <ii> tmp; tmp.clear();
		int cur = 0;
		for (auto c : mp) {
			cur += c.first * c.second;
			res += c.first * c.second % MOD;
			res %= MOD;
			tmp.push_back({c.first, c.second});
		}
		// cerr << "ans at " << u << " is " << cur << endl;
		g[u] = tmp;
	}
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	cout << res << endl;

	return 0;
}