#include <bits/stdc++.h>

using namespace std;

const int N = 1005, M = 2e5 + 5;
int n, m, a[M], b[M];
vector <int> adj[N], rev[N];
bool ans[M], mark[N], tmp[M];

void dfs1(int u, int ban) {
	mark[u] = 1;
	for (int ind : adj[u]) {
		int v = b[ind];
		if (v == ban || mark[v]) continue;
		dfs1(v, ban);
	}
}

void solve(int u) {
	for (int k = 0; k < adj[u].size(); ++k) {
		int ind = adj[u][k];
		int v = b[ind];
		tmp[ind] |= mark[v];
		dfs1(v, u);
	}
	memset(mark, 0, sizeof mark);
	for (int k = adj[u].size() - 1; k >= 0; --k) {
		int ind = adj[u][k];
		int v = b[ind];
		tmp[ind] |= mark[v];
		dfs1(v, u);
	}
	for (int ind : adj[u]) {
		ans[ind] ^= tmp[ind];
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i] >> b[i];
		adj[a[i]].push_back(i);
		rev[b[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		memset(mark, 0, sizeof mark);
		dfs1(i, -1);
		for (int ind : rev[i]) {
			int u = a[ind];
			if (mark[u]) ans[ind] = 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		memset(mark, 0, sizeof mark);
		solve(i);
	}
	for (int i = 1; i <= m; ++i) if (ans[i] == 0) {
		cout << "same\n";
	} else cout << "diff\n";

	return 0;
}