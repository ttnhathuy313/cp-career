#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int N = 1e5 + 5;
int n, res;
vector <iii> Edges;

struct dsu_t {
	int n;
	vector <int> lab, sz;
	dsu_t() {}
	dsu_t(int _n) {
		this -> n = _n;
		lab.assign(n + 5, -1);
		sz.assign(n + 5, 1);
	}
	int root(int x) {
		return lab[x] == -1 ? x : lab[x] = root(lab[x]);
	}
	int getSize(int x) {
		return sz[root(x)];
	}
	void merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return;
		lab[x] = y;
		sz[y] += sz[x];
	}
};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v, w; 
		cin >> u >> v >> w;
		Edges.push_back({w, {u, v}});
	}
	sort(Edges.begin(), Edges.end());
	dsu_t dsu(n);
	for (auto D : Edges) {
		int u = D.second.first, v = D.second.second, w = D.first;
		res += dsu.getSize(u) * dsu.getSize(v) * w;
	}
	cout << res << endl;

	return 0;
}