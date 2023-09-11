#include <bits/stdc++.h>

using namespace std;
#define _sz(x) (int)x.size()
 
const int N = 1e5 + 20, LG = 20;
int n, q, h[N], ord[N];
 
int sz, root[N];
struct Node {
	int lc, rc;
	int mx, l, r;
	bool full;
	Node () { lc = rc = mx = l = r = full = 0 ; }
} seg[LG * N];
 
inline bool cmp (int a , int b) { return h[a] > h[b] ; }
 
Node merge (Node a, Node b) {
	Node res;
	res.full = a.full && b.full;
	res.l = (a.full ? a.l + b.l : a.l);
	res.r = (b.full ? a.r + b.r : b.r);
	res.mx = max(max(max(a.mx, b.mx), a.r + b.l), max(res.l, res.r));
	return res;
}
 
Node upd (Node a, Node b) {
	a.full = b.full;
	a.l = b.l;
	a.r = b.r;
	a.mx = b.mx;
	return a;
}
 
void build (int &v, int s = 0, int e = n) {
	if (!v) v = ++sz;
	if (s + 1 == e) return;
	int mid = (s + e) >> 1;
	build(seg[v].lc, s, mid);
	build(seg[v].rc, mid, e);
}
 
void add (int &v, int prv, int p, int s = 0, int e = n) {
	if (!v) v = ++sz;
	if (s + 1 == e) {
		seg[v].full = seg[v].l = seg[v].r = seg[v].mx = 1;
		return;
	}

	int mid = (s + e) >> 1;
	if (p < mid) {
		add(seg[v].lc, seg[prv].lc, p, s, mid);
		seg[v].rc = seg[prv].rc;
	} else {
		add(seg[v].rc, seg[prv].rc, p, mid, e);
		seg[v].lc = seg[prv].lc;
	}
	seg[v] = upd(seg[v], merge(seg[seg[v].lc], seg[seg[v].rc]));
}
 
Node get (int v, int l, int r, int s = 0, int e = n) {
	if (s >= r || e <= l) {
		Node dummy;
		return dummy;
	}
	if (s >= l && e <= r) return seg[v];
	int mid = (s + e) >> 1;
	return merge(get(seg[v].lc, l, r, s, mid), get(seg[v].rc, l, r, mid, e));
}
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> h[i];
 
	iota(ord, ord + n, 0);
	sort(ord, ord + n, cmp);
 
	build(root[0]);
	for (int i = 0; i < n; i++) add(root[i + 1], root[i], ord[i]);
	cin >> q;
	while (q--) {
		int l, r, w;
		cin >> l >> r >> w;
		l--;
		int low = 0, high = n;
		while (high - low > 1) {
			int mid = (low + high) >> 1;
 
			if (get(root[mid], l, r).mx >= w) high = mid;
			else low = mid;
		}
		cout << h[ord[high - 1]] << '\n' ;
	}
	return 0;
}