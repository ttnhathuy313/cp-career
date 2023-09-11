#include <bits/stdc++.h>

using namespace std;
#define int long long

struct dsunormal {
	int n;
	vector <int> lab, sz;
	dsunormal() {}
	dsunormal(int _n) {
		this -> n = _n;
		lab.assign(n + 5, -1);
		sz.assign(n + 5, 1);
	}
	int root(int x) {
		return (lab[x] == -1 ? x : lab[x] = root(lab[x]));
	}
	void merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return;
		if (sz[x] > sz[y]) swap(x, y);
		lab[x] = y;
		sz[y] += sz[x];
	}
} dsu1;

struct dsu_t { // add an edge to a new graph, the bipartiteness is stored in isBipartite
	int n, isBipartite, nVersion;
	stack <pair <int, int>> roll_back;
	vector <int> lab, sz, parity;
	dsu_t() {}
	dsu_t(int _n) {
		this -> n = _n;
		isBipartite = true;
		nVersion = 0;
		lab.assign(n + 5, -1);
		sz.assign(n + 5, 0);
		parity.assign(n + 5, 0);
		while (!roll_back.empty())
			roll_back.pop();
	}
	pair<int, int> root(int x) {
		if(lab[x] == -1)
			return {x, parity[x]};
		pair<int, int> p = root(lab[x]);
		p.second ^= parity[x];
		return p;
	}
	void merge(int u, int v) {
		pair <int, int> px = root(u), py = root(v);
		int rx = px.first, vx = px.second, ry = py.first, vy = py.second;
		if (rx == ry) {
			if (vx == vy) {
				isBipartite = false;
			}
			return;
		}
		if (sz[rx] > sz[ry]) {
			swap(rx, ry);
			swap(vx, vy);
		}
		lab[rx] = ry;
		parity[rx] = vx ^ vy ^ 1;
		sz[ry] += (sz[rx] == sz[ry]);
	}
} dsu2;

typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, m, res[N][2];
vector <ii> E1, E2;

void solve() {
	cin >> n >> m;
	dsu1 = dsunormal(n);
	dsu2 = dsu_t(n);
	E1.clear(); E2.clear();
	for (int i = 1; i <= n; ++i)
		res[i][0] = res[i][1] = 0;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		string c;
		cin >> u >> v >> c;
		if (c == "imposter") {
			E2.push_back({u, v});
		} else E1.push_back({u, v});
	}
	for (ii e : E1) {
		dsu1.merge(e.first, e.second);
	}
	for (ii e : E2) {
		int u = e.first, v = e.second;
		int x = dsu1.root(u), y = dsu1.root(v);
		if (x == y) {
			cout << -1 << endl;
			return;
		}
		dsu2.merge(x, y);
		if (dsu2.isBipartite == false) {
			cout << -1 << endl;
			return;
		}
	}
	for (int i = 1; i <= n; ++i) if (dsu1.root(i) == i) {
		int j = dsu2.root(i).first;
		res[j][dsu2.root(i).second] += dsu1.sz[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) if (dsu1.root(i) == i && dsu2.root(i).first == i) {
		ans += max(res[i][0], res[i][1]);
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}