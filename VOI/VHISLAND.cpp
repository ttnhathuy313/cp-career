#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
#define sqr(a) (a) * (a)

const int N = 2e3 + 5;
int n, x[N], y[N], ans[N], q;
vector <iii> Edges;

struct dsu_t {
	int n;
	vector <int> lab, Rank;
	dsu_t() {}
	dsu_t(int _n) {
		this -> n = _n;
		lab.assign(n + 5, -1);
		Rank.assign(n + 5, 0);
	}
	int root(int x) {
		return lab[x] == -1 ? x : lab[x] = root(lab[x]);
	}
	bool merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return false;
		if (Rank[x] < Rank[y]) swap(x, y);
		lab[y] = x;
		Rank[x] += (Rank[x] == Rank[y]);
		return true;
	}
};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("VHISLAND.INP", "r", stdin);
	freopen("VHISLAND.OUT", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) if (i != j) {
			int dist = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
			Edges.push_back({dist, {i, j}});
		}
	}
	sort(Edges.begin(), Edges.end());
	dsu_t dsu = dsu_t(n + 5);
	priority_queue <int> pq;
	for (iii e : Edges) {
		int u = e.second.first, v = e.second.second, w = e.first;
		if (dsu.merge(u, v)) {
			pq.push(w);
		}
	}
	ans[0] = pq.top();
	for (int i = 1; i <= n - 2; ++i) {
		pq.pop();
		ans[i] = pq.top();
	}
	ans[n - 1] = 0;
	while (q--) {
		int X, Y;
		cin >> X >> Y;
		double res = 1e18;
		for (int i = 0; i < n; ++i) {
			res = min(res, sqrt(ans[i]) * (double)X + i * Y);
		}
		cout << fixed << setprecision(9) << res << endl;
	}

	return 0;
}