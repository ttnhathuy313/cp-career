#include <bits/stdc++.h>

using namespace std;
#define int long long

const int oo = 5e5 + 5;

struct FenwickTree {
	int n;
	vector <int> fw;
	FenwickTree() {}
	FenwickTree(int _n) {
		this -> n = _n;
		fw.assign(n + 5, -oo);
	}

	void upd(int id, int x) {
		if (id == -1) return;
		while (id <= n) {
			fw[id] = max(fw[id], x);
			id += (id & -id);
		}
	}

	int get(int id) {
		int ret = -oo;
		while (id) {
			ret = max(ret, fw[id]);
			id -= (id & -id);
		}
		return ret;
	}

} solver;

const int N = 5e5 + 5;
int n, a[N], pref[N], plain_dp[N];

int get_idx(int value, vector <int> &V) {
	return (upper_bound(V.begin(), V.end(), value) - V.begin());
}

void solve() {
	cin >> n;
	set <int> val;
	val.clear();
	val.insert(0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
		val.insert(pref[i]);
	}
	vector <int> V;
	V.clear();
	for (int v : val) {
		V.push_back(v);
	}

	for (int i = 0; i <= n + 3; ++i) {
		plain_dp[i] = -oo;
	}
	plain_dp[get_idx(0, V)] = 0;

	solver = FenwickTree(n);
	solver.upd(get_idx(0, V), 0);
	//x >= -pref[i]
	int pre = 0;
	for (int i = 1; i <= n; ++i) {
		int curDp = -oo;
		int prevId = get_idx(pref[i], V);
		int curId = get_idx(pref[i], V);
		if (binary_search(V.begin(), V.end(), pref[i])) {
			curDp = max(curDp, plain_dp[prevId]);
		}
		prevId = get_idx(pref[i] - 1, V);
		curDp = max(curDp, solver.get(prevId) + i);
		curDp = max(curDp, pre - 1);
		pre = curDp;
		solver.upd(curId, curDp - i);
		// cerr << "dp[" << i << "]: " << curDp << endl;

		plain_dp[curId] = max(plain_dp[curId], curDp);
		if (i == n) {
			cout << plain_dp[curId] << endl;
		}
	}

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskI.INP", "r", stdin);
	freopen("TaskI.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}