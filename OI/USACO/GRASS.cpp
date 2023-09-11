#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

struct dsu_t {
	int n;
	vector <int> lab, Rank;
	dsu_t() {}
	dsu_t(int _n) {
		this -> n = _n;
		lab.assign(n + 5, -1);
		Rank.assign(n + 5, 1);
	}
	int root(int x) {
		return lab[x] == -1 ? x : lab[x] = root(lab[x]);
	}
	bool merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return false;
		if (Rank[x] < Rank[y]) swap(x, y);
		lab[y] = x;
		Rank[x] += Rank[y];
		return true;
	}
};

const int N = 2e5 + 5;
int n, m, k, q, p[N], ep[N], type[N], isLeaf[N], ans[N];
vector <ii> adj[N];
vector <iii> Edges;
map <int, multiset <int>> colors[N];
multiset <ii> best[N];
multiset <int> global;

void del(multiset <int> &D, int u) {
	D.erase(D.find(u));
}

void del2(multiset <ii> &D, ii u) {
	D.erase(D.find(u));
}

void prepare(int u, int pre) {
	int cnt = 0;
	for (ii v : adj[u]) {
		if (v.first == pre) continue;
		cnt++;
		p[v.first] = u;
		ep[v.first] = v.second;
		colors[u][type[v.first]].insert(v.second);
		prepare(v.first, u);
	}
	if (cnt == 0) {
		isLeaf[u] = true;
		return;
	}
	for (pair <int, multiset<int>> d : colors[u]) {
		best[u].insert({*(d.second.begin()), d.first});
	}
	multiset <ii>::iterator it = best[u].begin();
	if (it->second == type[u]) it++;
	if (it == best[u].end()) return;
	ans[u] = it->first;
	global.insert(it->first);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("grass.in", "r", stdin);
	freopen("grass.out", "w", stdout);

	cin >> n >> m >> k >> q;
	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		cin >> u >> v >>c;
		Edges.push_back({c, {u, v}});
	}
	sort(Edges.begin(), Edges.end());
	dsu_t dsu = dsu_t(n);
	for (iii e : Edges) {
		int w = e.first, u = e.second.first, v = e.second.second;
		if (dsu.merge(u, v)) {
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
	}
	memset(ans, -1, sizeof ans);
	for (int i = 1; i <= n; ++i)
		cin >> type[i];
	prepare(1, -1);
	while (q--) {
		int u, x;
		cin >> u >> x;
		if (p[u]) {
			multiset <int> &D = colors[p[u]][type[u]];
			del2(best[p[u]], {*(D.begin()), type[u]});
			del(D, ep[u]);
			if (D.size()) best[p[u]].insert({*(D.begin()), type[u]});
			multiset<int> &DD = colors[p[u]][x];
			if (DD.size()) del2(best[p[u]], {*(DD.begin()), x});
			DD.insert(ep[u]);
			best[p[u]].insert({*(DD.begin()), x});
			if (~ans[p[u]]) del(global, ans[p[u]]);
			multiset <ii>::iterator it = best[p[u]].begin();
			if (it->second == type[p[u]]) it++;
			if (it != best[p[u]].end()) {
				global.insert(it->first);
				ans[p[u]] = it->first;
			} else ans[p[u]] = -1;
		}
		type[u] = x;
		if (!isLeaf[u]) {
			if (~ans[u]) del(global, ans[u]);
			multiset <ii>::iterator it = best[u].begin();
			if (it->second == type[u]) it++;
			if (it != best[u].end()) {
				global.insert(it->first);
				ans[u] = it->first;
			} else ans[u] = -1;
		}
		cout << *(global.begin()) << endl;
	}

	return 0;
}