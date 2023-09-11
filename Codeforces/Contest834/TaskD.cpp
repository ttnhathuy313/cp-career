#include <bits/stdc++.h>

using namespace std;

struct Node {
	int mx, lazy;
};

struct SegmentTree {
	int n;
	vector <Node> st;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, {0, 0});
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}

	void push(int id) {
		st[Left(id)].lazy += st[id].lazy;
		st[Left(id)].mx += st[id].lazy;
		st[Right(id)].lazy += st[id].lazy;
		st[Right(id)].mx += st[id].lazy;
		st[id].lazy = 0;
	}

	void update(int id, int L, int R, int l, int r, int val) {
		if (L > r || R < l) return;
		if (L >= l && R <= r) {
			st[id].lazy += val;
			st[id].mx += val;
			return;
		}
		int mid = (L + R) >> 1;
		push(id);
		update(Left(id), L, mid, l, r, val);
		update(Right(id), mid + 1, R, l, r, val);
		st[id].mx = max(st[Left(id)].mx, st[Right(id)].mx);
	}
	int query(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return -1;
		if (L >= i && R <= j) return st[id].mx;
		int mid = (L + R) >> 1;
		push(id);
		return max(query(Left(id), L, mid, i, j), query(Right(id), mid + 1, R, i, j));
	}
	void update(int i, int j, int val) {
		update(1, 1, n, i, j, val);
	}
	int query(int i, int j) {
		return (query(1, 1, n, i, j));
	}
};

const int N = 35005, K = 55;
int n, k, dp[N][K], lst[N], a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	set <int> S; S.clear();
	dp[0][1] = -N;
	for (int i = 1; i <= n; ++i) {
		S.insert(a[i]);
		dp[i][1] = (int)S.size();
	}
	for (int j = 2; j <= k; ++j) {
		SegmentTree IT(n + 5);
		memset(lst, -1, sizeof lst);
		for (int i = 1; i <= n; ++i) {
			if (lst[a[i]] != -1) {
				IT.update(lst[a[i]] + 1, i, 1);
			} else IT.update(1, i, 1);
			lst[a[i]] = i;
			IT.update(i, i, dp[i - 1][j - 1]);
			if (i < j) dp[i][j] = -N;
			else {
				dp[i][j] = IT.query(1, i);
			}
		}
		dp[0][j] = -N;
	}
	cout << dp[n][k] << endl;

	return 0;
}