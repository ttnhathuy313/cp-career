#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, dp[N], k, route[N], m, d[N], f[N];
vector <int> adj[N], dag[N], topo;
set <ii> avail;
bool mark[N];

void dfs(int u) {
	mark[u] = 1;
	for (int v : dag[u]) if (!mark[v])
		dfs(v);
	topo.push_back(u);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
	}
	cin >> k;
	for (int i = 1; i <= k; ++i)
		cin >> route[i];
	int s = route[1], t = route[k];
	queue <int> q; while (!q.empty()) q.pop();
	q.push(t);
	for (int i = 1; i <= n; ++i) d[i] = N;
	mark[t] = 1; d[t] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (mark[v]) continue;
			d[v] = d[u] + 1;
			mark[v] = 1;
			q.push(v);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j : adj[i]) if (d[j] == d[i] + 1) {
			dag[i].push_back(j);
			// cerr << i << " " << j << endl;
			avail.insert({j, i});
			f[j]++;
		}
 	}
 	memset(mark, 0, sizeof mark);
 	dfs(t);
 	reverse(topo.begin(), topo.end());
 	// for (int v : topo) cerr << v << ' '; cerr << endl;
 	dp[t] = 1;
 	for (int u : topo) {
 		for (int v : dag[u]) {
 			dp[v] += dp[u];
 			if (dp[v] >= 2) dp[v] = 2;
 		}
 	}
 	int mi = 0, mx = 0;
 	for (int i = 1; i < k; ++i) {
 		if (avail.find({route[i], route[i + 1]}) == avail.end()) {
 			mi++; mx++;
 		} else {
 			if (f[route[i]] >= 2) mx++;
 		}
 	}
 	cout << mi << ' ' << mx << endl;

	return 0;
}