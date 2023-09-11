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
	void merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return;
		lab[x] = y;
	}
};

const int N = 2e5 + 5;
int n, m;
vector <int> adj[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n >> m;
	dsu_t dsu(n);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		dsu.merge(u, v);
	}
	bool ok = true;
	for (int i = 1; i <= n; ++i) {
		if (dsu.root(i) != dsu.root(1)) {
			cout << i << endl;
			ok = false;
		}
	}
	if (ok) cout << "Connected" << endl;

	return 0;
}