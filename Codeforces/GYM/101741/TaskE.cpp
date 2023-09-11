#include <bits/stdc++.h>

using namespace std;

struct maximumBipariteMatching {
	vector <int> mark, rhs, lhs;
	vector <vector <int>> adj;
	int n, m, maxMatchVal = 0;
	set <int> unMatched;

	maximumBipariteMatching() {}
	maximumBipariteMatching(int _n, int _m) {
		this -> n = _n;
		this -> m = _m;
		init();
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
	}

	void clearAllEdge() {
		for (int i = 1; i <= n; ++i) adj[i].clear();
	}

	void init() {
		maxMatchVal = 0;
		mark.assign(n + 5, 0);
		rhs.assign(m + 5, -1);
		lhs.assign(n + 5, -1);
		adj.assign(n + 5, vector <int> (0, 0));
	}
 
	bool dfs(int u) {
		if (mark[u]) return 0;
		mark[u] = 1;
		for (int v : adj[u]) {
			if (rhs[v] == -1 || dfs(rhs[v])) {
				lhs[u] = v;
				rhs[v] = u;
				return true;
			}
		}
		return false;
	}

	void solve() {
		unMatched.clear();
		for (int i = 1; i <= n; ++i) {
			bool flag = false;
			for (int j : adj[i]) if (rhs[j] == -1) {
				rhs[j] = i;
				lhs[i] = j;
				flag = true;
				break;
			}
		}

		int Found = 1;
		while (Found--) {
			mark.assign(n + 5, 0);
			for (int i = 1; i <= n; i++) if (lhs[i] == -1) Found |= dfs(i);
		}
		for (int i = 1; i <= n; i++) {
			maxMatchVal += (lhs[i] != -1);
		}
		clearAllEdge();
	}
};

const int N = 5e5 + 5;
int n;
vector <int> adj[N];

void solve() {
	int m, a, b;
	cin >> m >> a >> b;
	maximumBipariteMatching Solver = maximumBipariteMatching(2 * n, m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		if (v != a) Solver.addEdge(v, i);
		if (u != b) Solver.addEdge(u + n, i);
	}
	Solver.solve();
	if (Solver.maxMatchVal != 2 * (n - 1)) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; ++i) if (i != a)
		cout << Solver.lhs[i] << ' ';
	cout << endl;
	for (int i = 1; i <= n; ++i) if (i != b)
		cout << Solver.lhs[i + n] << ' ';
	cout << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);

	while (cin >> n) {
		solve();
	}

	return 0;
}