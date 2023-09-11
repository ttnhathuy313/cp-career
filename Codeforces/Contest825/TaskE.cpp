#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int deg[N], ans[N], n, m;
vector <int> adj[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
		deg[u]++;
	}
	priority_queue <int> pq;
	while (!pq.empty()) pq.pop();
	for (int i = 1; i <= n; ++i) if (deg[i] == 0) {
		pq.push(i);
	}
	int turn = n;
	while (!pq.empty()) {
		int u = pq.top();
		pq.pop();
		ans[u] = turn--;
		for (int v : adj[u]) {
			deg[v]--;
			if (deg[v] == 0) pq.push(v);
		}
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';

	return 0;
}