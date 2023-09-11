struct Matching {
	int n, m;
	vector <int> lhs, rhs, mark;
	vector <vector <int>> adj;
	vector <ii> res;
 
	Matching() {}
	Matching(int _n, int _m) {
		this -> n = _n, this -> m = _m;
		lhs.assign(n + 5, -1);
		rhs.assign(m + 5, -1);
		adj.assign(n + 5, vector <int>(0, 0));
		mark.assign(n + 5, false);
	}
 
	void addEdge(int u, int v) {
		adj[u].push_back(v);
	}
 
	bool dfs(int u) {
		if (mark[u]) return false;
		mark[u] = true;
		for (int v : adj[u]) {
			if (rhs[v] == -1 || dfs(rhs[v])) {
				rhs[v] = u;
				lhs[u] = v;
				return true;
			}
		}
		return false;
	}
 
	void solve() {
		for (int i = 1; i <= n; ++i) {
			for (int j : adj[i]) if (rhs[j] == -1) {
				rhs[j] = i;
				lhs[i] = j;
				break;
			}
		}
		int Found = 1;
		while (Found--) {
			mark.assign(n + 5, false);
			for (int u = 1; u <= n; ++u) if (lhs[u] == -1)
				Found |= dfs(u);
		}
		for (int i = 1; i <= n; ++i) if (lhs[i] != -1) {
			res.push_back(ii(i, lhs[i]));
		}
	}
};