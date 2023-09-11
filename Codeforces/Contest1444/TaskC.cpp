#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

struct dsu_t { // add an edge to a new graph, the bipartiteness is stored in isBipartite
	int n, isBipartite, nVersion;
	stack <pair <int, int>> roll_back;
	vector <int> lab, Rank, parity;
	dsu_t() {}
	dsu_t(int _n) {
		this -> n = _n;
		isBipartite = true;
		nVersion = 0;
		lab.assign(n + 5, -1);
		Rank.assign(n + 5, 0);
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
				roll_back.push(pair <int, int>(0, isBipartite));
				nVersion++;
				isBipartite = false;
			}
			return;
		}
		if (Rank[rx] > Rank[ry]) {
			swap(rx, ry);
			swap(vx, vy);
		}
		lab[rx] = ry;
		roll_back.push(pair <int, int>(3, rx + (parity[rx]) * n));
		roll_back.push(pair <int, int>(1, rx));
		nVersion += 2;
		parity[rx] = vx ^ vy ^ 1;
		if (Rank[rx] == Rank[ry]) roll_back.push(pair <int, int>(2, ry));
		nVersion += Rank[rx] == Rank[ry];
		Rank[ry] += (Rank[rx] == Rank[ry]);
	}
	void roll_to(int version) {
		while (nVersion != version) {
			pair <int, int> item = roll_back.top();
			roll_back.pop(); nVersion--;
			if (item.first == 0) {
				isBipartite = item.second;
			} else if (item.first == 1) {
				lab[item.second] = -1;
			} else if (item.first == 2) {
				Rank[item.second]--;
			} else if (item.first == 3) {
				if (item.second > n) {
					parity[item.second - n] = 1;
				} else parity[item.second] = 0;
			}
		}
	}
};

struct Edge_t {
	int p1, p2, u, v;
	Edge_t() {}
	Edge_t(int _p1, int _p2, int _u, int _v) : p1(_p1), p2(_p2), u(_u), v(_v) {}
	bool operator < (const Edge_t other) const {
		return (p1 < other.p1 || (p1 == other.p1 && p2 < other.p2));
	}
};

const int N = 5e5 + 5;
int n, m, k, c[N], sz[N], x[N], y[N], ok[N];
vector <ii> inner[N];
vector <Edge_t> Elist;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		sz[c[i]]++;
	}
	set <ii> S; S.clear();
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		x[i] = u, y[i] = v;
		if (c[u] == c[v]) {
			inner[c[u]].push_back({u, v});
			continue;
		}
	}
	dsu_t dsu = dsu_t(n);
	int cnt = 0;
	for (int i = 1; i <= k; ++i) {
		dsu.roll_to(0);
		for (ii d : inner[i])
			dsu.merge(d.first, d.second);
		ok[i] = dsu.isBipartite;
		cnt += dsu.isBipartite;
	}
	dsu.roll_to(0);
	for (int i = 1; i <= k; ++i) if (ok[i]) {
		for (ii d : inner[i])
			dsu.merge(d.first, d.second);
	}

	for (int i = 1; i <= m; ++i) {
		int u = x[i], v = y[i];
		if (c[u] == c[v]) continue;
		if (!ok[c[u]] || !ok[c[v]]) continue;
		if (c[u] < c[v]) swap(u, v);
		S.insert({c[u], c[v]});
		Edge_t e = Edge_t(c[u], c[v], u, v);
		Elist.push_back(e);
	}
	sort(Elist.begin(), Elist.end());
	int res = cnt * (cnt - 1) / 2 - (int)S.size(), pre_u = 0, pre_v = -1, trace = dsu.nVersion;
	for (Edge_t ed : Elist) {
		if (ed.p1 != pre_u || ed.p2 != pre_v) {
			if (pre_u != 0) {
				// cerr << "		" << dsu.isBipartite << endl;
				res += dsu.isBipartite;
			}
			dsu.roll_to(trace);
		}
		// cerr << ed.p1 << ' ' << ed.p2 << "   :   " << ed.u << ' ' << ed.v << endl;
		dsu.merge(ed.u, ed.v);
		pre_u = ed.p1; pre_v = ed.p2;
	}
	if (pre_u != 0) {
		res += dsu.isBipartite;
	}

	cout << res << endl;

	return 0;
}