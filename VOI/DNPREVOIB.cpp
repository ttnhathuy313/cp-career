#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 3e5 + 5;
int n, k, type[N], u[N], v[N], real_val[N];

struct SegmentTree {
	int n;
	vector <int> st, cnt;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, 0);
		cnt.assign(4 * n + 5, 0);
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}
	void update(int id, int L, int R, int i, int val) {
		if (L > i || R < i) return;
		if (L == R) {
			st[id] = val;
			if (val == 0) cnt[id] = 0;
			else cnt[id] = 1;
			return;
		}
		int mid = (L + R) >> 1;
		update(Left(id), L, mid, i, val);
		update(Right(id), mid + 1, R, i, val);
		st[id] = st[Left(id)] + st[Right(id)];
		cnt[id] = cnt[Left(id)] + cnt[Right(id)];
	}
	int get(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return 0;
		if (L >= i && R <= j) return st[id];
		int mid = (L + R) >> 1;
		return get(Left(id), L, mid, i, j) + get(Right(id), mid + 1, R, i, j);
	}
	int bound(int id, int L, int R, int k) {
		if (cnt[id] <= k) return R;
		int mid = (L + R) >> 1;
		if (cnt[Left(id)] >= k) return bound(Left(id), L, mid, k);
		else return bound(Right(id), mid + 1, R, k - cnt[Left(id)]);
	}
	void update(int i, int val) {
		update(1, 1, n, i, val);
	}
	int get(int i, int j) {
		return get(1, 1, n, i, j);
	}
	int query(int k) {
		return get(1, bound(1, 1, n, k));
	}
};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("DNPREVOIB.INP", "r", stdin);
	freopen("DNPREVOIB.OUT", "w", stdout);

	int zxrstcdyfvtuygbhuji;
	cin >> zxrstcdyfvtuygbhuji;
	cin >> n >> k;
	vector <ii> val; val.clear();
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		if (s == "show") {
			type[i] = 1;
			cin >> u[i] >> v[i];
			val.push_back({u[i], i});
		} else type[i] = 2;
	}
	sort(val.begin(), val.end(), greater <ii>());
	int cnt = 0;
	for (ii d : val) {
		cnt++;
		real_val[d.second] = u[d.second];
		u[d.second] = cnt;
	}
	set <ii> current; current.clear();
	SegmentTree Solver = SegmentTree(n);
	for (int i = 1; i <= n; ++i) {
		if (type[i] == 1) {
			Solver.update(u[i], real_val[i]);
			current.insert({v[i], i});
		} else {
			auto dd = current.rbegin();
			Solver.update(u[dd->second], 0);
			current.erase(current.find(*dd));
		}
		cout << Solver.query(k) << ' ';
	}

	return 0;
}