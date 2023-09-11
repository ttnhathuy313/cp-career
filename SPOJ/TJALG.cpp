#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
int n, m, tin[N], dfsTime, low[N], mark[N], res;
vector <int> adj[N];
stack <int> st;

void dfs(int u) {
	tin[u] = low[u] = ++dfsTime;
	mark[u] = 1;
	st.push(u);
	for (int v : adj[u]) {
		if (!mark[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (mark[v] == 1) {
			low[u] = min(low[u], tin[v]);
		}
	}
	if (low[u] == tin[u]) {
		res++;
		while (st.top() != u) {
			int v = st.top(); st.pop();
			mark[v] = 2;
		}
		st.pop(); mark[u] = 2;
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TJALG.INP", "r", stdin);
	freopen("TJALG.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i) if (!mark[i]) {
		dfs(i);
	}
	cout << res << endl;

	return 0;
}