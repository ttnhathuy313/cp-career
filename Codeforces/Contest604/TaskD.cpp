#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;

struct dsu {
	vector <int> lab, Rank;
	int size = 0, n;
	dsu() {}
	dsu(int _n) {
		this -> n = _n;
		size = n;
		lab.assign(n + 5, -1);
		Rank.assign(n + 5, 1);
	} 
	int root(int x) {
		return (lab[x] == -1 ? x : lab[x] = root(lab[x]));
	}
	void merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return;
		size--;
		if (Rank[x] < Rank[y]) swap(x, y);
		lab[y] = x;
		Rank[x] += Rank[y];
	}
};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int p, k;
	cin >> p >> k;
	dsu S(p);
	for (int i = 0; i < p; ++i) {
		S.merge(i + 1, (i * k) % p + 1);
		// cerr << i + 1 << ' ' << (i * k) % p + 1 << endl;
	}
	int sz = S.size;
	for (int i = 1; i <= p; ++i) if (S.lab[i] == -1 && S.Rank[i] == 1) sz--;
	if (k == 0) sz = p - 1;
	if (k == 1) sz = p;
	int res = 1;
	for (int i = 1; i <= sz; ++i) {
		res = (1LL * res * p) % MOD;
	}
	cout << res << endl;

	return 0;
}