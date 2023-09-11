#include <bits/stdc++.h>

using namespace std;
#define int long long

struct dsu_t {
	int n;
	vector <int> lab;
	dsu_t() {}
	dsu_t(int _n) {
		this -> n = _n;
		lab.assign(n + 5, -1);
	}
	int root(int x) {
		return lab[x] == -1 ? x : lab[x] = root(lab[x]);
	}
	bool merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return false;
		lab[x] = y;
		return true;
	}
};

const int N = 1e5 + 5;
int n, m, k, r[N], sum[N], p[33], h[33], w[33];
array <int, 3> e[N * 3];
array <int, 2> d[N];
vector <int> b, adj[33];

void dfs1(int u, int pre = -1) {
	if (~pre) p[u] = pre, h[u] = h[pre] + 1;
	else h[u] = 0, p[u] = -1;
	for (int v : adj[u]) if (v != pre)
		dfs1(v, u);
}

int dfs2(int u, int dd = 0) {
	int r = dd * sum[u];
	for (int v : adj[u]) if (v != p[u]) {
		r += dfs2(v, dd + w[v]);
	}
	return r;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("APIO13_toll.INP", "r", stdin);
	freopen("APIO13_toll.OUT", "w", stdout);

	cin >> n >> m >> k;
	dsu_t d1(n), d2(n), d3(n);
	for (int i = 1; i <= m; ++i) {
		cin >> e[i][1] >> e[i][2] >> e[i][0];
	}
	sort(e + 1, e + 1 + m);
	for (int i = 1; i <= k; ++i) {
		cin >> d[i][0] >> d[i][1];
		d1.merge(d[i][0], d[i][1]);
	}
	for (int i = 1; i <= m; ++i) {
		if (!d2.merge(e[i][1], e[i][2]))
			continue;
		if (d1.merge(e[i][1], e[i][2])) d3.merge(e[i][1], e[i][2]);
		else {
			b.push_back(i);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (d3.root(i) == i) r[i] = ++cnt;
	}
	for (int i = 1; i <= n; ++i) {
		int si;
		cin >> si;
		sum[r[d3.root(i)]] += si;
	}
	for (int bi : b) {
		e[bi][1] = r[d3.root(e[bi][1])];
		e[bi][2] = r[d3.root(e[bi][2])];
	}
	for (int i = 1; i <= k; ++i) {
		d[i][0] = r[d3.root(d[i][0])];
		d[i][1] = r[d3.root(d[i][1])];
	}
 	int ans = 0;
	for (int mask = 0; mask < (1 << k); ++mask) {
		for (int i = 1; i <= cnt; ++i)
			adj[i].clear();
		dsu_t d4(cnt), d5(cnt);
		for (int i = 1; i <= k; ++i) if (mask & (1 << (i - 1))) if (d4.merge(d[i][0], d[i][1])) {
			adj[d[i][0]].push_back(d[i][1]);
			adj[d[i][1]].push_back(d[i][0]);
		}
		deque <array <int, 3>> dq; dq.clear();
		for (int bi : b) {
			if (d4.merge(e[bi][1], e[bi][2])) {
				adj[e[bi][1]].push_back(e[bi][2]);
				adj[e[bi][2]].push_back(e[bi][1]);
				dq.push_front({0, e[bi][1], e[bi][2]});
			} else dq.push_back(e[bi]);
		}
		dfs1(r[d3.root(1)]);
		for (array <int, 3> ci : dq) {
			int u = d5.root(ci[1]), v = d5.root(ci[2]);
			while (u != v) {	
				if (h[u] < h[v]) swap(u, v);
				w[u] = ci[0];
				d5.merge(u, p[u]);
				u = d5.root(u);
			}
		}
		ans = max(ans, dfs2(r[d3.root(1)]));
	}
	cout << ans << endl;

	return 0;
}