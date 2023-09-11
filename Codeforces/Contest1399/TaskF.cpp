#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 3005;
int n, l[N], r[N], val[(int)2e5 + 5];

struct fenwick {
	int n;
	vector <int> tree;
	fenwick() {}
	fenwick(int _n) {
		this -> n = _n;
		tree.assign(n + 5, 0);
	}
	void update(int id, int x) {
		while (id <= n) {
			tree[id] = max(tree[id], x);
			id += (id & -id);
		}
	}
	int get(int i) {
		if (i < 0) return 0;
		int ret = 0;
		while (i > 0) {
			ret = max(ret, tree[i]);
			i -= (i & -i);
		}
		return ret;
	}
} fw[N];

void solve() {
	cin >> n;
	n++;
	l[n] = 0, r[n] = (int)2e5 + 1;
	set <int> V; V.clear();
	V.insert(0); V.insert(r[n]);
	for (int i = 1; i <= n - 1; ++i) {
		cin >> l[i] >> r[i];
		V.insert(l[i]); V.insert(r[i]);
	}
	int id = 0;
	for (int v : V) {
		val[v] = ++id;
	}
	vector <int> idx;
	idx.clear();
	for (int i = 1; i <= n; ++i) {
		l[i] = val[l[i]];
		r[i] = val[r[i]];
		idx.push_back(i);
	}
	sort(idx.begin(), idx.end(), [](int i, int j) {
		if (r[i] == r[j]) return l[i] > l[j];
		return r[i] < r[j];
	});
	for (int i = 1; i <= n; ++i) {
		fw[i] = fenwick(id);
	}
	for (int i : idx) {
		int cur = fw[i].get(id) + 1;
		for (int j = 1; j <= n; ++j) if (l[j] <= l[i] && r[j] >= r[i] && i != j) {
			fw[j].update(r[i], cur + fw[j].get(l[i] - 1));
		}
	}
	cout << fw[n].get(id) << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}