#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, value[N];
ii a[N];

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

bool cmp(ii x, ii y) {
	if (x.second < y.second) return true;
	else return false;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first >> a[i].second;
		value[i] = -1;
	}
	dsu_t dsu(n);
	map <int, int> mp;
	mp.clear();
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; ++i) {
		int l = a[i].first, r = a[i].second;
		// cerr << a[i/].first << ' ' << a[i].second << endl;
		int id = mp[l];
		if (id == 0) {
			mp[l] = i;
			value[i] = l;
			int vv = mp[l - 1];
			if (vv != 0) {
				dsu.merge(vv, i);
			}
			int dd = mp[l + 1];
			if (dd != 0) {
				dsu.merge(i, dd);
			}
		} else {
			id = dsu.root(id);
			if (value[id] + 1 > r) {
				cout << "No" << endl;
				return;
			}
			value[i] = value[id] + 1;
			mp[value[i]] = i;
			dsu.merge(id, i);
			int z = mp[value[i] + 1];
			if (z != 0) {
				dsu.merge(i, z);
			}
		}
	}
	
	cout << "Yes" << endl;
	return;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}