#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, a[N], b[N], k, dp[N][12];
vector <ii> pts[N];

struct Fenwick1D {
	int n;
	vector <int> fw;
	Fenwick1D() {}
	Fenwick1D(int _n) {
		this -> n = _n;
		fw.assign(n + 5, 0);
	}

	void add(int id, int x) {
		while (id <= n) {
			fw[id] += x;
			id += (id & -id);
		}
	}

	int get(int id) {
		int ret = 0;
		while (id) {
			ret += fw[id];
			id -= (id & -id);
		}
		return ret;
	}

};

struct Fenwick2D {
	int n;
	vector <Fenwick1D> fw;
	Fenwick2D() {}
	Fenwick2D(int _n, int _m) {
		this -> n = _n;
		fw.assign(n + 5, Fenwick1D(_m));
	}

	void add(int x, int y, int value) {
		while (x <= n) {
			fw[x].add(y, value);
			x += (x & -x);
		}
	}

	int get(int x, int y) {
		int ret = 0;
		while (x) {
			ret += fw[x].get(y);
			x -= (x & -x);
		}
		return ret;
	}

};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		dp[i][1] = 1;
		pts[a[i]].push_back({b[i], i});
	}

	int res = 0;
	for (int turn = 2; turn <= k; ++turn) {
		Fenwick1D solver(n);
		for (int i = 1; i <= n; ++i) {
			for (ii v : pts[i]) {
				int value = v.first, id = v.second;
				dp[id][turn] = solver.get(v.first - 1);
				if (turn == k) {
					res += dp[id][turn];
				}
			}
			for (ii v : pts[i]) {
				int value = v.first, id = v.second;
				solver.add(value, dp[id][turn - 1]);
			}
		}
	}
	cout << res << endl;

	return 0;
}