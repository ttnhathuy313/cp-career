#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
#define int long long

struct DSU {
	vector <int> lab, Rank;
	int n;
	DSU() {}
	DSU(int _n) {
		this -> n = _n;
		lab.assign(n + 5, -1);
		Rank.assign(n + 5, 1);
	}
	int root(int x) {
		return lab[x] == -1 ? x : lab[x] = root(lab[x]);
	}
	void merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return;
		if (Rank[x] < Rank[y]) swap(x, y);
		lab[y] = x;
		Rank[x] += Rank[y];
	}
	int size(int x) {
		return Rank[root(x)];
	}
};

const int N = 1e6 + 5;
int n, a[N], parent[N];
vector <int> adj[N];
bool processed[N];

void dfs(int u, int pre) {
	parent[u] = pre;
	for (int v : adj[u]) if (v != pre)
		dfs(v, u);
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.inp", "r", stdin);
	freopen("TaskF.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	vector <ii> t;
	for (int i = 1; i <= n; ++i)
		t.push_back(ii(a[i], i));
	DSU Solver = DSU(n);
	sort(t.begin(), t.end());
	int res = 0;
	for (ii d : t) {
		int u = d.second, ai = d.first;
		int ps = 0, tmp = 1;
		processed[u] = 1;
		for (int v : adj[u]) {
			if (!processed[v]) continue;
			tmp += Solver.size(v);
			tmp += Solver.size(v) * ps;
			ps += Solver.size(v);
			Solver.merge(u, v);
		}
		res += tmp * ai;
	}
	memset(processed, false, sizeof processed);
	Solver = DSU(n);
	sort(t.begin(), t.end(), greater <ii> ());
	for (ii d : t) {
		int u = d.second, ai = d.first;
		int ps = 0, tmp = 1;
		processed[u] = 1;
		for (int v : adj[u]) {
			if (!processed[v]) continue;
			tmp += Solver.size(v);
			tmp += Solver.size(v) * ps;
			ps += Solver.size(v);
			Solver.merge(u, v);
		}
		res -= tmp * ai;
	}
	cout << res << endl;

	return 0;
}