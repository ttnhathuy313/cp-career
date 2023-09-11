#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, m, tin[N], low[N], dfsTime, mark[N], scc, okay[N], tot, root = N, cur = 0, ver[N], op[N], cl[N], beg[N], cross;
bool exclude[N];
vector <int> adj[N];
stack <int> S;

void dfs(int u) {
	tin[u] = low[u] = ++dfsTime;
	mark[u]= 1;
	ver[dfsTime] = u;
	S.push(u);
	for (int v : adj[u]) {
		if (!mark[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (mark[v] == 1)
			low[u] = min(low[u], tin[v]);
	}
	if (tin[u] == low[u]) {
		int sz = 1;
		while (S.top() != u) {
			int v = S.top();
			okay[v] = 1;
			mark[v] = 2;
			S.pop();
			root = min(root, v);
			sz++;
		}
		if (sz > 1) {
			scc++;
			okay[u] = 1;
		}
		S.pop();
		mark[u] = 2;
	}
}

void prepare(int u) {
	cerr << u << endl;
	mark[u] = 1;
	tin[u] = ++dfsTime;
	ver[dfsTime] = u;
	for (int v : adj[u]) if (okay[v] && !mark[v]) {
		prepare(v);
	}
}

void dfs2(int u) {
	cur += beg[u];
	bool check = true;
	cross -= cl[u];
	if (cur != tot) check = false;
	if (cross != 0) check = false;
	cross += op[u];
	mark[u] = 1;
	if (check) {
		cout << u << endl;
		exit(0);
	}
	if (exclude[u]) {
		cout << -1 << endl;
		exit(0);
	}
	if (!mark[ver[tin[u] + 1]]) dfs2(ver[tin[u] + 1]);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.inp", "r", stdin);
	freopen("TaskF.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i) if (!mark[i])
		dfs(i);
	if (scc > 1) {
		cout << -1 << endl;
		return 0;
	}
	dfsTime = 0;
	memset(mark, 0, sizeof mark);
	prepare(root);
	for (int i = 1; i <= n; ++i) if (okay[i]) {
		for (int j : adj[i]) if (okay[j] && tin[i] > tin[j]) {
			beg[j]++;
			tot++;
			exclude[i] = true;
		}
		for (int j : adj[i]) if (okay[j] && tin[i] < tin[j]) {
			op[i]++;
			cl[j]++;
		}
	}
	memset(mark, 0, sizeof mark);
	mark[0] = 1;
	dfs2(root);
	cout << -1 << endl;

	return 0;
}