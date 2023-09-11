#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
int n, m, p, lhs[N], rhs[N];
bool mark[N];
vector <int> adj[N];

bool dfs(int u) {
	if (mark[u]) return false;
	mark[u] = 1;
	for (int v : adj[u]) {
		if (rhs[v] == -1 || dfs(rhs[v])) {
			rhs[v] = u;
			lhs[u] = v;
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("FMATCH.INP", "r", stdin);
	freopen("FMATCH.OUT", "w", stdout);

	cin >> n >> m >> p;
	memset(lhs, -1, sizeof lhs);
	memset(rhs, -1, sizeof rhs);
	for (int i = 1; i <= p; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j : adj[i]) if (rhs[j] == -1) {
			rhs[j] = i;
			lhs[i] = j;
			break;
		}
	}
	int found = 1;
	while (found--) {
		memset(mark, 0, sizeof mark);
		for (int i = 1; i <= n; ++i) if (lhs[i] == -1) {
			found |= dfs(i);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) if (~lhs[i])
		res++;
	cout << res << endl;

	return 0;
}