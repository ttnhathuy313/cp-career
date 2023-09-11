#include <bits/stdc++.h>

using namespace std;
#define int long long

struct SegmentTree {
	int n;
	vector <int> lazy;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		lazy.assign(4 * n + 5, -1);
	}

	int Left(int x) {
		return (x << 1);
	}
	int Right(int x) {
		return (x << 1) + 1;
	}

	void push(int id) {
		if (~lazy[id]) {
			lazy[Left(id)] = lazy[id];
			lazy[Right(id)] = lazy[id];
			lazy[id] = -1;
		}
	}

	void update(int id, int L, int R, int i, int j, int val) {
		if (L > j || R < i) {
			return;
		}
		if (L >= i && R <= j) {
			lazy[id] = val;
			return;
		}
		push(id);
		int mid = (L + R) >> 1;
		update(Left(id), L, mid, i, j, val);
		update(Right(id), mid + 1, R, i, j, val);
	}

	int get(int id, int L, int R, int i) {
		if (L == R) {
			return lazy[id];
		}
		push(id);
		int mid = (L + R) >> 1;
		if (i <= mid) return get(Left(id), L, mid, i);
		else return get(Right(id), mid + 1, R, i);
	}

	int upd(int i, int j, int val) {
		update(1, 1, n, i + 1, j + 1, val);
	}

	int get(int i) {
		return get(1, 1, n, i + 1);
	}
} Solver;

const int N = 3e5 + 5, MOD = 998244353;
int n, l[N], r[N], lst[N], pow3[N], pow2[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskH.INP", "r", stdin);
	freopen("TaskH.OUT", "w", stdout);

	Solver = SegmentTree(N - 3);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
		Solver.upd(l[i], r[i], i);
	}
	pow3[0] = pow2[0] = 1;
	for (int i = 1; i < N; ++i) {
		pow3[i] = pow3[i - 1] * 3 % MOD;
		pow2[i] = pow2[i - 1] * 2 % MOD;
	}
	int res = 0;
	for (int i = 0; i <= N - 5; ++i) {
		int lst = Solver.get(i);
		if (lst == -1) {
			continue;
		}
		if (lst != 1) {
			res += pow3[lst - 2] * pow2[n - lst + 1] % MOD;
			res %= MOD;
		} else {
			res += pow2[n - 1] % MOD;
			res %= MOD;
		}
	}
	cout << res << endl;


	return 0;
}