#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

struct DSU {
	int n;
	vector <int> lab, Rank;
	DSU() {}
	DSU(int _n) {
		this -> n = _n;
		lab.assign(n + 5, -1);
		Rank.assign(n + 5, 0);
	}
	int root(int x) {
		return (lab[x] == -1 ? x : lab[x] = root(lab[x]));
	}
	void merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return;
		if (Rank[x] < Rank[y]) swap(x, y);
		lab[y] = x;
		Rank[x] += (Rank[x] == Rank[y]);
	}
};

const int N = 1e5 + 5;
vector <iii> EdgeList;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("COMNET.INP", "r", stdin);
	freopen("COMNET.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, q;
		cin >> n >> m >> q;
		EdgeList.clear();
		for (int i = 1; i <= m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			EdgeList.push_back(iii(w, ii(u, v)));
		}
		while (q--) {
			int id;
			cin >> id;
			int s;
			cin >> s;
			vector <ii> changes;
			changes.clear();
			for (int i = 1; i <= s; ++i) {
				int t, d;
				cin >> t >> d;
				changes.push_back(ii(t - 1, EdgeList[t - 1].first));
				EdgeList[t - 1].first = d;
			}
			DSU dsu(n);
			for (iii e : EdgeList) if (e.first < EdgeList[id - 1].first) {
				dsu.merge(e.second.first, e.second.second);
			}
			if (dsu.root(EdgeList[id - 1].second.first) != dsu.root(EdgeList[id - 1].second.second)) cout << "NO" << endl;
			else cout << "YES" << endl;
			for (ii d : changes) {
				EdgeList[d.first].first = d.second;
			}
		}
	}

	return 0;
}