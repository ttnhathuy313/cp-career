#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, p, a[N];
bool mark[N];
map <int, set <int>> adj;
map <int, int> cnt, root;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("BOIP.INP", "r", stdin);
	freopen("BOIP.OUT", "w", stdout);

	cin >> n >> p; // case p = 1
	if (p == 1) {
		set <int> s;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			s.insert(x);
		}
		cout << s.size() << endl;
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
		root[a[i]] = a[i];
		adj[a[i]].insert(a[i]);
	}
	sort(a + 1, a + 1 + n);	
	for (int i = 1; i <= n; ++i) {
		int cur = root[a[i]];
		if (cnt[a[i] * p]) {
			root[a[i] * p] = cur;
			adj[cur].insert(a[i] * p);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) if (root[a[i]] == a[i]) {
		set <int> s = adj[a[i]];
		// cerr << "	";
		// for (int v : s) cerr << v << ' ';
		// cerr << endl;
		int u = cnt[*(s.begin())], vv = 0;
		for (int v : s) {
			if (v == *(s.begin())) continue;
			int tu = u, tv = vv;
			u = cnt[v] + tv;
			vv = max(tu, tv);
		}
		res += max(u, vv);
		// cerr << "	--> " << max(u, vv) << endl;
		root[a[i]] = -1;
	}
	cout << res << endl;

	return 0;
}