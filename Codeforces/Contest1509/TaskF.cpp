#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int N = 2e5 + 5;
int n, m, cycle;
vector <ii> adj[N];

struct DisjointSet {
	int n, biton;
	vector <int> lab;

	DisjointSet() {}
	DisjointSet(int _n) {
		this -> n = _n;
		lab.assign(n + 5, -1);
		biton = 0;
	}
	int root(int x) {
		return (lab[x] == -1 ? x : lab[x] = root(lab[x]));
	}
	int merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return 0;
		biton++;
		lab[x] = y;
		return 1;
	}
} dsu, init, fake;

void dfs(int u, int pre) {
	dsu.merge(u, u + 1);
	set <int> V; V.clear();
	for (ii v : adj[u]) {
		V.insert(v.first);
	}
	int match = 0, met_pre = 1;
	for (int v : V) {
		if (dsu.root(v) != v) {
			match++; 
			if (v == pre) met_pre = 0;
		}
	}
	int tmp;
	if (pre != -1) tmp = dsu.biton - 1 - met_pre * (dsu.root(pre) != pre);
	else tmp = dsu.biton - 1;
	if (match != tmp) cycle = 1;
	int v = dsu.root(1);
	while (v <= n) {
		if (V.find(v) == V.end()) {
			dfs(v, u);
			init.merge(u, v);
		}
		v = dsu.root(v + 1);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.inp", "r", stdin);
	freopen("TaskF.out", "w", stdout);

	cin >> n >> m;
	int xor_sum = 0;
	vector <iii> Edges;
	Edges.clear();
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		Edges.push_back({w, {u, v}});
		xor_sum ^= w;
	}
	sort(Edges.begin(), Edges.end());
	dsu = DisjointSet(n + 1);
	init = DisjointSet(n);
	fake = DisjointSet(n);
	for (int i = 1; i <= n; ++i) if (dsu.root(i) == i) {
		dfs(i, -1);
	}
	int cost = 0;
	for (iii E : Edges) {
		int w = E.first, u = E.second.first, v = E.second.second;
		if (init.merge(u, v)) {
			cost += w;
			fake.merge(u, v);
		} else {
			if (fake.root(u) != fake.root(v)) xor_sum = min(xor_sum, w);
		}
	}
	cout << cost + xor_sum * (cycle ^ 1) << endl;

	return 0;
}