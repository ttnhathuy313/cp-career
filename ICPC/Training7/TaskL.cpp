#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, m, a, b, uu[N], vv[N];
vector <int> adj[N];

void bfs(int s, vector <int> &d) {
	d.assign(n + 5, N);
	d[s] = 0;
	queue <int> q;
	while (!q.empty()) q.pop();
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) if (d[v] == N) {
			q.push(v);
			d[v] = d[u] + 1;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskL.INP", "r", stdin);
	freopen("TaskL.OUT", "w", stdout);

	cin >> n >> m >> a >> b;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		uu[i] = u; vv[i] = v;
		adj[u].push_back(v);
	}
	vector <int> d1, d2, d3;
	bfs(0, d1);
	for (int i = 0; i <= n; ++i)
		adj[i].clear();
	for (int i = 1; i <= m; ++i) {
		adj[vv[i]].push_back(uu[i]);
	}
	bfs(a, d2);
	bfs(b, d3);
	int res = (int)1e9 + 7;
	for (int i = 0; i <= n; ++i) {
		//cerr << i << ' ' << d1[i] + d2[i] + d3[i] << endl;
		res = min(res, d1[i] + d2[i] + d3[i]);
	}
	cout << res << endl;

	return 0;
}