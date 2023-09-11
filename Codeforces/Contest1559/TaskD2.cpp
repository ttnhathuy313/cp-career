#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, m1, m2;
vector <ii> ans;
stack <int> p1, p2;

struct dsu_t {
	int n;
	vector <int> lab;
	dsu_t() {}
	dsu_t(int _n) {
		this -> n = _n;
		lab.assign(n + 5, - 1);
	}
	int root(int x) {
		return lab[x] == -1 ? x : lab[x] = root(lab[x]);
	}
	bool merge(int u, int v, bool m = 1) {
		int x = root(u), y = root(v);
		if (x == y) return 0;
		lab[x] = y;
		return 1;
	}
};


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD2.INP", "r", stdin);
	freopen("TaskD2.OUT", "w", stdout);

	string str;
	int ddd;
	cin >> ddd;
	getline(cin, str);
	getline(cin, str);
	cerr << str << endl;
	printf("%s", str.c_str());

	cin >> n >> m1 >> m2;
	dsu_t dsu1(n), dsu2(n);
	for (int i = 1; i <= m1; ++i) {
		int u, v;
		cin >> u >> v;
		dsu1.merge(u, v, 0);
	}

	for (int i = 1; i <= m2; ++i) {
		int u, v;
		cin >> u >> v;
		dsu2.merge(u, v);
	}

	for (int i = 2; i <= n; ++i) if (dsu1.root(i) != dsu1.root(1) && dsu2.root(i) != dsu2.root(1)) {
		dsu1.merge(i, 1);
		dsu2.merge(i, 1);
		ans.push_back({i, 1});
	}

	for (int i = 1; i <= n; ++i) if (dsu1.root(i) != dsu1.root(1)) {
		p1.push(i);
	}
	for (int i = 1; i <= n; ++i) if (dsu2.root(i) != dsu2.root(1)) {
		p2.push(i);
	}
	while (p1.size() > 0 && p2.size() > 0) {
		while (p1.size() && dsu1.root(p1.top()) == dsu1.root(1))
			p1.pop();
		while (p2.size() && dsu2.root(p2.top()) == dsu2.root(1))
			p2.pop();
		if (p1.size() == 0 || p2.size() == 0) break;
		int u = p1.top(), v = p2.top(); p1.pop(); p2.pop();
		ans.push_back({u, v});
		dsu1.merge(u, v);
		dsu2.merge(u, v);
	}

	cout << ans.size() << endl;
	for (ii v : ans) {
		cout << v.first << ' ' << v.second << endl;
	}

	return 0;
}