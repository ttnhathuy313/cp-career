#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

struct dsu {
	int n;
	vector <int> lab;
	vector <vector <int>> mem;
	dsu() {}
	dsu(int _n) {
		this -> n = _n;
		lab.assign(n + 5, -1);
		mem.assign(n + 5, vector <int>(0, 0));
		for (int i = 1; i <= n; ++i) {
			mem[i].push_back(i);
		}
	}
	int root(int x) {
		return (lab[x] == -1 ? x : lab[x] = root(lab[x]));
	}
	void merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return;
		if (mem[x].size() < mem[y].size()) {
			swap(x, y);
		}
		for (int vv : mem[y]) {
			mem[x].push_back(vv);
		}
		lab[y] = x;
	}
} solver;

int n, m, tin[N], low[N], mark[N], dfsTime, scc;
vector <int> adj[N];

void dfs(int u) {
	tin[u] = low[u] = ++dfsTime;
	mark[u] = 1;
	for (int v : adj[u]) {
		if (mark[v] == 0) {
			dfs(v);
			low[u] = min(low[u], low[v]);
			if (low[v] <= tin[u]) { // if not bridge
				solver.merge(u, v);
				// cerr << u << ' ' << v << endl;
			}
		} else if (mark[v] != 2) { // if back edge hoac la cross edge chua bi vo hieu hoa, mark = 2 la vo hieu hoa
			low[u] = min(low[u], tin[v]);
			solver.merge(u, v);
			// cerr << u << ' ' << v << endl;
		}
	}
	if (low[u] == tin[u]) {
		scc++;
		for (int v : solver.mem[solver.root(u)]) {
			mark[v] = 2;
		}
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
	solver = dsu(n);
	for (int i = 1; i <= n; ++i) if (!mark[i]) {
		dfs(i);
	}
	cout << scc << endl;

	return 0;
}