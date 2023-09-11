#include <bits/stdc++.h>

using namespace std;
#define int long long

struct Matching {
	int n, m, maxMatchVal;
	vector <int> lhs, rhs, mark, excluded;
	vector <vector <int>> adj;
	set <int> mvc;
	Matching() {}
	Matching(int _n, int _m) {
		this -> n = _n; this -> m = _m;
		lhs.assign(n + 5, -1);
		rhs.assign(m + 5, -1);
		adj.assign(n + 5, vector <int>(0, 0));
		excluded.assign(n + 5, 0);
		maxMatchVal = 0;
	}
	void addEdge(int u, int v) {
		adj[u].push_back(v);
	}
	bool dfs(int u) {
		if (mark[u]) return false;
		mark[u] = 1;
		for (int v : adj[u]) if (rhs[v] == -1 || dfs(rhs[v])) {
			rhs[v] = u;
			lhs[u] = v;
			return true;
		}
		return false;
	}
	void go(int u) {
		excluded[u] = 1;
		mark[u] = 1;
		for (int v : adj[u]) if (v != lhs[u]) {
			mvc.insert(n + v);
			if (rhs[v] != -1 && !mark[rhs[v]]) go(rhs[v]);
		}
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
			for (int i = 1; i <= n; ++i) if (lhs[i] == -1)
				Found |= dfs(i);
		}
		for (int i = 1; i <= n; ++i) if (~lhs[i])
			maxMatchVal++;
		mark.assign(n + 5, 0);
		for (int i = 1; i <= n; ++i) if (lhs[i] == -1) {
			go(i);
		}
		for (int i = 1; i <= n; ++i) if (!excluded[i])
			mvc.insert(i);
	}
};

const int N = 205;
int a[N], n;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("DIVREL.INP", "r", stdin);
	freopen("DIVREL.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	vector <int> num; num.clear(); num.push_back(0);
	int pre = -1;
	for (int i = 1; i <= n; ++i) {
		if (a[i] != pre) {
			num.push_back(a[i]);
		}
		pre = a[i];
	}
	n = num.size() - 1;
	Matching Solver(n, n);
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) if (num[j] % num[i] == 0) {
			Solver.addEdge(j, i);
		}
	}
	Solver.solve();
	cout << n - Solver.maxMatchVal << endl;
	for (int i = 1; i <= n; ++i) {
		if (Solver.mvc.find(i) == Solver.mvc.end() && Solver.mvc.find(i + n) == Solver.mvc.end()) {
			cout << num[i] << ' ';
		}
	}

	return 0;
}