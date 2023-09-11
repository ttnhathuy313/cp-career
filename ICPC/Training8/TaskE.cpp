#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

struct fenwick_t {
	int n;
	vector <int> tree;
	fenwick_t() {}
	fenwick_t(int _n) {
		this -> n = _n;
		tree.assign(n + 5, 0);
	}
	void add(int i, int x) {
		while (i <= n) {
			tree[i] += x;
			i += i & -i;
		}
	}
	int get(int i) {
		int ret = 0;
		while (i > 0) {
			ret += tree[i];
			i -= i & -i;
		}
		return ret;
	}
};

const int N = 1e5 + 5;
int n, p[N];
vector <int> V[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
		
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		int a = i, b = p[i];
		if (a > b) {
			swap(a, b);
		}
		V[a].push_back(b);
	}
	fenwick_t fw(n);
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j : V[i]) {
			res += fw.get(j - 1) - fw.get(i);
		}
		for (int j : V[i]) {
			fw.add(j, 1);
		}
	}
	cout << res << endl;

	return 0;
}