#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, LOG = 22;
int n, tin[N], tout[N], dfsTime, P[N][LOG], d[N];
vector <int> adj[N];

void dfs(int u, int pre) {
	tin[u] = ++dfsTime;
	for (int v : adj[u]) {
		if (v == pre) continue;
		P[v][0] = u;
		d[v] = d[u] + 1;
		dfs(v, u);
	}
	tout[u] = ++dfsTime;
}

int lca(int u, int v) {
	if (d[u] < d[v]) swap(u, v);
	for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= d[u] - d[v]) {
		u = P[u][i];
	}
	if (u == v) return u;
	for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= d[u] && P[u][i] != P[v][i]) {
		u = P[u][i];
		v = P[v][i];
	}
	return P[u][0];
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(P, -1, sizeof P);
	dfs(1, -1);
	for (int i = 1; i < LOG; ++i) {
		for (int u = 1; u <= n; ++u) if ((1 << i) <= d[u]) {
			P[u][i] = P[P[u][i - 1]][i - 1];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int r, b;
		cin >> r >> b;
		int mxR = -1, mxB = -1;
		vector <int> lr, lb;
		lr.clear(); lb.clear();
		for (int i = 1; i <= r; ++i) {
			int v;
			cin >> v;
			lr.push_back(v);
			if (mxR == -1) mxR = v;
			else {
				mxR = lca(mxR, v);
			}
		}
		for (int i = 1; i <= b; ++i) {
			int v;
			cin >> v;
			lb.push_back(v);
			if (mxB == -1) mxB = v;
			else {
				mxB = lca(mxB, v);
			}
		}
		bool ok = false;
		bool tmp = true;
		for (int v : lr) {
			if (tin[v] >= tin[mxB] && tout[v] <= tout[mxB])
				tmp = false;
		}
		ok |= tmp;
		tmp = true;
		for (int v : lb) {
			if (tin[v] >= tin[mxR] && tout[v] <= tout[mxR])
				tmp = false;
		}
		ok |= tmp;
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}