#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, k, d, a[N], f[N], g[N];
map <int, int> lst;
stack <int> mx, mi;

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

	void update(int id, int L, int R, int i, int j, int val) {
		if (L > j || R < i) return;
		if (L >= i && R <= j) {
			st[id].lazy += val;
			st[id].mx += val;
			return;
		}
		int mid = (L + R) >> 1;
		push(id);
		update(Left(id), L, mid, i, j, val);
		update(Right(id), mid + 1, R, i, j, val);
		st[id].mx = max(st[Left(id)].mx, st[Right(id)].mx);
	}

	int query(int id, int L, int R, int i, int j, int val) {
		if (L > j || R < i) return -1;
		if (st[id].mx < val) return -1;
		if (L == R) return L;
		push(id);
		int mid = (L + R) >> 1;
		int ret = -1;
		ret = query(Left(id), L, mid, i, j, val);
		if (ret == -1) ret = query(Right(id), mid + 1, R, i, j, val);
		st[id].mx = max(st[Left(id)].mx, st[Right(id)].mx);
		return ret;
	}
	void add(int i, int j, int val) {
		update(1, 1, n, i, j, val);
	}
	int get(int i, int j, int val) {
		return query(1, 1, n, i, j, val);
	}
};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> k >> d;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	if (d == 0) {
		int l = 0;
		pair <int, int> ans;
		int pre = 1;
		for (int i = 1; i <= n; ++i) {
			if (a[i] != a[i - 1] && i != 1) {
				pre = i;
			}
			if (i - pre + 1 > l) {
				l = i - pre + 1;
				ans = {pre, i};
			}
		}
		cout << ans.first << " " << ans.second << endl;
		return 0;
	}
	int up = (int)2e9 / d;
	up *= d;
	f[1] = 1; lst[a[1]] = 1;
	for (int i = 2; i <= n; ++i) {
		if (lst.find(a[i]) == lst.end()) f[i] = f[i - 1];
		else f[i] = max(f[i - 1], lst[a[i]] + 1);
		lst[a[i]] = i;
	}
	int cur = 0, rem = -1;
	for (int i = 1; i <= n; ++i) {
		if (rem != (a[i] + up) % d) {
			rem = (a[i] + up) % d;
			cur = 0;
		}
		cur++;
		g[i] = cur;
		f[i] = max(f[i], i - cur + 1);
	}

	SegmentTree IT(n + 5);
	mx.push(0); mi.push(0);
	int res_sz = 0;
	pair <int, int> ans(0, 0);
	for (int i = 1; i <= n; ++i) {
		while (!mi.empty() && mi.top() != 0 && a[mi.top()] > a[i]) {
			int u = mi.top(); mi.pop();
			int v = mi.top();
			IT.add(v + 1, u, -a[u] + a[i]);
		}
		while (!mx.empty() && mx.top() != 0 && a[mx.top()] < a[i]) {
			int u = mx.top(); mx.pop();
			int v = mx.top();
			IT.add(v + 1, u, a[u] - a[i]);
		}
		mi.push(i); mx.push(i);
		IT.add(i, i, (k - i) * d);
		int j = IT.get(f[i], i, -i * d);
		if (j == -1) continue;
		if (i - j + 1 > res_sz) {
			res_sz = i - j + 1;
			ans = {j, i};
		}
	}
	cout << ans.first << ' ' << ans.second << endl;

	return 0;
}