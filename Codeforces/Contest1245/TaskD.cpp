#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int N = 2005;
ii a[N];
int k[N], c[N];

struct DisjointSet {
	vector <int> lab, Rank;
	int n;
	DisjointSet() {}
	DisjointSet(int _n) {
		this->n = _n;
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

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);

	int n;
	cin >> n;
	vector <iii> Edges;
	Edges.clear();
	for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		Edges.push_back(iii(c[i], ii(n + 1, i)));
	}
	for (int i = 1; i <= n; ++i) 
		cin >> k[i];
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int C = (k[i] + k[j]) * (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second));
			Edges.push_back(iii(C, ii(i, j)));
		}
	}
	vector <int> station;
	vector <ii> E;
	E.clear(); station.clear();
	sort(Edges.begin(), Edges.end());
	DisjointSet DSU(n + 1);
	int Cost = 0;
	for (iii d : Edges) {
		int u = d.second.first, v = d.second.second;
		if (DSU.root(u) != DSU.root(v)) {
			DSU.merge(u, v);
			Cost += d.first;
			if (u == n + 1) station.push_back(v);
			else E.push_back(d.second);
		}
	}
	cout << Cost << endl;
	cout << station.size() << endl;
	for (int k : station) cout << k << ' ';
	cout << endl;
	cout << E.size() << endl;
	for (ii d : E) {
		cout << d.first << ' ' << d.second << endl;
	}

	return 0;
}