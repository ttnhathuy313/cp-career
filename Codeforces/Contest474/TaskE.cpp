#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int oo = 1e9 + 7;

struct SegmentTree {
	int n;
	vector <ii> st;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, {-oo, 0});
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}

	void update(int id, int L, int R, int i, int val) {
		if (L > i || R < i) return;
		if (L == R) {
			st[id] = {val, i};
			return;
		}
		int mid = (L + R) >> 1;
		update(Left(id), L, mid, i, val);
		update(Right(id), mid + 1, R, i, val);
		st[id] = max(st[Left(id)], st[Right(id)]);
	}

	ii get(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return {0, 0};
		if (L >= i && R <= j)
			return st[id];
		int mid = (L + R) >> 1;
		return max(get(Left(id), L, mid, i, j), get(Right(id), mid + 1, R, i, j));
	}
	void update(int i, int val) {
		update(1, 1, n, i, val);
	}
	ii get(int l, int r) {
		if (l > r) return {0, 0};
		return get(1, 1, n, l, r);
	}
};

const int N = 1e5 + 5;
int n, a[N], l[N], r[N], d, trace[N], pos[N], dp[N];
vector <ii> A;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		A.push_back({a[i], i});
	}
	A.push_back({-1, -1});
	sort(A.begin(), A.end());
	SegmentTree IT = SegmentTree(n);
	int j = 1;
	for (int i = 1; i <= n; ++i) {
		pos[A[i].second] = i;
		while (A[i].first - A[j].first >= d && j < i) {
			r[A[j].second] = i - 1;
			j++;
		}
		l[A[i].second] = j;
	}
	for (int i = 1; i <= n; ++i) {
		if (r[i] == 0) r[i] = n + 1;
		ii V = max(IT.get(1, l[i] - 1), IT.get(r[i] + 1, n));
		V = max(V, {0, 0});
		if (V.first == 0) {
			trace[i] = 0;
			dp[i] = 1;
			IT.update(pos[i], 1);
			continue;
		}
		trace[i] = A[V.second].second;
		dp[i] = V.first + 1;
		IT.update(pos[i], V.first + 1);
	}
	int res = 0, id = -1;
	for (int i = 1; i <= n; ++i) if (dp[i] > res) {
		res = dp[i];
		id = i;
	}
	cout << res << endl;
	vector <int> O; O.clear();
	while (id) {
		O.push_back(id);
		id = trace[id];
	}
	reverse(O.begin(), O.end());
	for (int v : O) cout << v << ' ';

	return 0;
}