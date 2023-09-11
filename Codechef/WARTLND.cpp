#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
#define int long long

struct DisjointSet {
	int n;
	vector <int> lab, Rank;
	stack <iii> changes;
	DisjointSet() {}
	DisjointSet(int n) {
		this -> n = n;
		lab.assign(n + 5, -1);
		Rank.assign(n + 5, 1);
	}

	int root(int x) {
		return (lab[x] == -1 ? x : root(lab[x]));
	}
	void merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return;
		if (Rank[x] < Rank[y]) swap(x, y);
		lab[y] = x;
		Rank[x] += Rank[y];
		changes.push(iii(Rank[y], ii(x, y)));
	}
	int size(int u) {
		return Rank[root(u)];
	}
	void clear() {
		while (!changes.empty()) {
			iii d = changes.top(); changes.pop();
			Rank[d.second.first] -= d.first;
			lab[d.second.second] = -1;
		}
	}
} DSU;

const int N = 1e5 + 5;
int n, g[N], f[N];
vector <ii> adj[N], Edge[N], W[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		Edge[i].clear();
		W[i].clear();
		adj[i].clear();
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(ii(v, w));
		adj[v].push_back(ii(u, w));
		W[w].push_back(ii(u, v));
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j * i <= n; j++) {
			for (int k = 0; k < W[j * i].size(); ++k) {
				Edge[i].push_back(W[j * i][k]);
			}
		}
	}
	DSU = DisjointSet(n);
	for (int i = 1; i <= n; ++i) {
		int res = 0;
		DSU.clear();
		for (int k = 0; k < Edge[i].size(); ++k) {
			ii d = Edge[i][k];
			int u = d.first, v = d.second;
			if (DSU.root(u) == DSU.root(v)) continue;
			int su = DSU.size(u), sv = DSU.size(v);
			res -= su * (su - 1) / 2; res -= sv * (sv - 1) / 2;
			res += (su + sv) * (su + sv - 1) / 2;
			DSU.merge(u, v);
		}
		g[i] = res;
	}
	for (int i = n; i >= 1; --i) {
		f[i] = g[i];
		for (int j = 2; j * i <= n; j++) {
			f[i] -= f[j * i];
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) res += i * f[i];
	cout << res << endl;
}


main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("WARTLND.INP", "r", stdin);
	freopen("WARTLND.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}