#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
#define endl '\n'

struct Matching {
	int n, m, maxMatchVal;
	vector <int> lhs, rhs;
	vector <vector <int>> adj;
	vector <bool> mark;
	vector <ii> res;
	Matching() {}
	Matching(int _n, int _m) {
		this -> n = _n; this -> m = _m;
		lhs.assign(n + 5, -1);
		rhs.assign(m + 5, -1);
		adj.assign(n + 5, vector <int>(0, 0));
		maxMatchVal = 0;
		res.clear();
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
				lhs[i] = j;
				rhs[j] = i;
				break;
			}
		}
		int Found = 1;
		while (Found--) {
			mark.assign(n + 5, 0);
			for (int i = 1; i <= n; ++i) if (lhs[i] == -1) Found |= dfs(i);
		}
		for (int i = 1; i <= n; ++i) {
			if (lhs[i] != -1) res.push_back(ii(i, lhs[i]));
			maxMatchVal += (lhs[i] != -1);
		}
	}
};	

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("MATCH1.INP", "r", stdin);
	freopen("MATCH1.OUT", "w", stdout);

	int n, m;
	cin >> n >> m;
	Matching Solver(n, m);
	int u, v;
	while (cin >> u >> v) {
		Solver.addEdge(u, v);
	}
	Solver.solve();
	cout << Solver.maxMatchVal << endl;
	for (ii d : Solver.res) cout << d.first << ' ' << d.second << endl;

	return 0;
}