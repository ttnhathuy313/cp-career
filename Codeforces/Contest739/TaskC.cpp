#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
int n, A[N], lazy[4 * N];

struct obj {
	int res, zic_l, zic_r, decl, incr, l_val, r_val, l, r, incl, decr;
} null, st[4 * N];

obj operator + (const obj a, const obj b) {
	if (a.res == -1) return b;
	if (b.res == -1) return a;
	obj c;
	c.res = max(a.res, b.res);
	if (a.decl == a.r - a.l + 1 && a.r_val > b.l_val) {
		c.decl = a.r - a.l + 1 + b.decl;
	} else c.decl = a.decl;
	if (b.incr == b.r - b.l + 1 && b.l_val > a.r_val) {
		c.incr = b.r - b.l + 1 + a.incr;
	} else c.incr = b.incr;
	c.l_val = a.l_val; c.r_val = b.r_val;
	c.l = a.l, c.r = b.r;
	if (b.zic_l && a.r_val < b.l_val) c.res = max(c.res, b.zic_l + a.incr);
	if (a.zic_r && a.r_val > b.l_val) c.res = max(c.res, a.zic_r + b.decl);
	if (b.zic_l && a.incr == a.r - a.l + 1 && a.r_val < b.l_val) {
		c.zic_l = b.zic_l + a.incr;
	} else c.zic_l = a.zic_l;
	if (a.zic_r && b.decl == b.r - b.l + 1 && a.r_val > b.l_val) {
		c.zic_r = a.zic_r + b.decl;
	} else c.zic_r = a.zic_r;
	if (a.r_val != b.l_val) if (b.decl + a.incr > 2) if (!(b.decl == 1 && b.l_val > a.r_val)) if (!(a.incr == 1 && a.r_val > b.l_val)) {
		c.res = max(c.res, b.decl + a.incr);
		if (b.decl == b.r - b.l + 1) c.zic_r = max(c.zic_r, b.decl + a.incr);
		if (a.incr == a.r - a.l + 1) c.zic_l = max(c.zic_l, b.decl + a.incr);
	}
	if (a.incl == a.r - a.l + 1 && a.r_val < b.l_val) {
		c.incl = a.incl + b.incl;
	} else c.incl = a.incl;
	if (b.decr == b.r - b.l + 1 && b.l_val < a.l_val) {
		c.decr = b.decr + a.decr;
	} else c.decr = b.decr;
	c.res = max(c.res, c.incl);
	c.res = max(c.res, c.decr);
	c.res = max(c.res, c.zic_l);
	c.res = max(c.res, c.zic_r);
	c.res = max(c.res, c.decl);
	c.res = max(c.res, c.incr);
	if (a.r_val > b.l_val) c.res = max(c.res, a.decr + b.decl);
	if (a.r_val < b.l_val) c.res = max(c.res, a.incr + b.incl);
	return c;
};

int Left(int x) {return (x << 1);}
int Right(int x) {return (x << 1) + 1;}

void build(int id, int L, int R) {
	if (L == R) {
		st[id].l_val = st[id].r_val = A[L];
		st[id].zic_l = st[id].zic_r = 0;
		st[id].decl = st[id].incr = st[id].decr = st[id].incl = 1;
		st[id].res = 1;
		st[id].l = L, st[id].r = R;
		return;
	}
	int mid = (L + R) >> 1;
	build(Left(id), L, mid);
	build(Right(id), mid + 1, R);
	st[id] = st[Left(id)] + st[Right(id)];
	cerr << "[" << L << ", " << R << "] : " << st[id].res << " decl : " << st[id].decl << " incr : " << st[id].incr;
	cerr << " decr : " << st[id].decr << " incl " << st[id].incl << endl;
}

void push(int id) {
	st[Left(id)].l_val += lazy[id];
	st[Left(id)].r_val += lazy[id];
	lazy[Left(id)] += lazy[id];
	st[Right(id)].l_val += lazy[id];
	st[Right(id)].r_val += lazy[id];
	lazy[Right(id)] += lazy[id];
	lazy[id] = 0;
}

void update(int id, int L, int R, int i, int j, int val) {
	if (L > i || R < j) return;
	if (L >= i && R <= j) { 
		st[id].l_val += val;
		st[id].r_val += val;
		lazy[id] += val;
		return;
	}
	int mid = (L + R) >> 1;
	push(id);
	update(Left(id), L, mid, i, j, val);
	update(Right(id), mid + 1, R, i, j, val);
	st[id] = st[Left(id)] + st[Right(id)];
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> A[i];
	null.res = -1;
	build(1, 1, n);
	cerr << st[1].res << endl;
	int m;
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		int l, r, d;
		cin >> l >> r >> d;
		update(1, 1, n, l, r, d);
		cout << st[1].res << endl;
	}

	return 0;
}