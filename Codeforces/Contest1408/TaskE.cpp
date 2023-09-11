#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, m, a[N], b[N];
vector <array<int, 3>> Edges;

struct DisjointSet {
	int n;
	vector <int> lab;
	DisjointSet() {}
	DisjointSet(int _n) {
		this -> n = _n;
		lab.assign(n + 5, -1);
	}
	int root(int x) {
		return (lab[x] == -1 ? x : lab[x] = root(lab[x]));
	}
	bool merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return false;
		lab[y] = x;
		return true;
	}
} dsu;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	for (int i = 1; i <= m; ++i) {
		int sz;
		cin >> sz;
		while (sz--) {
			int j;
			cin >> j;
			// cerr << i << ' ' << j + m << ' ' << a[i] + b[j] << endl;
			Edges.push_back(array<int,3>{a[i] + b[j], i, j + m});
		}
	}
	sort(Edges.begin(), Edges.end(), greater <array <int, 3>>());
	dsu = DisjointSet(n + m);
	int sum = 0, mst = 0;
	for (auto e : Edges) {
		sum += e[0];
		if (dsu.merge(e[1], e[2])) {
			// cerr << e[0] << ' ' << e[1] << ' ' << e[2] << endl;
			mst += e[0];
		}
	}
	cout << sum - mst << endl;

	return 0;
}