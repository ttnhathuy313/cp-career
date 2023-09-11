#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
typedef pair <ii, int> iii;
#define lc (id << 1)
#define rc ((id << 1) + 1)

const int N = 2e5 + 5, A = 1e6 + 5;
int n, m, p, a[N], ca[N], b[N], cb[N], f[A], g[A], gg[A];
int tree[A << 2], lazy[A << 2];
vector <ii> pack[A];
 
void push(int id) {
    tree[lc] += lazy[id];
    tree[rc] += lazy[id];
    lazy[rc] += lazy[id];
    lazy[lc] += lazy[id];
    lazy[id] = 0;
}
 
void update(int id, int l, int r, int L, int R, int val) {
    if (l > R || r < L) {
        return;
    }
    if (L <= l && r <= R) {
        lazy[id] = val;
        tree[id] += val;
        return;
    }
    int mid = (l + r) >> 1;
    push(id);
    update(lc, l, mid, L, R, val);
    update(rc, mid + 1, r, L, R, val);
    tree[id] = max(tree[lc], tree[rc]);
}
 
int query(int id, int l, int r, int L, int R) {
    if (l > R || r < L) {
        return 0;
    }
    if (L <= l && r <= R) {
        return tree[id];
    }
    int mid = (l + r) >> 1;
    push(id);
    return max(query(lc, l, mid, L, R), query(rc, mid + 1, r, L, R));
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> m >> p;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> ca[i];
		if (g[a[i]] == 0) g[a[i]] = ca[i];
		else g[a[i]] = min(g[a[i]], ca[i]);
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i] >> cb[i];
		if (f[b[i]] == 0) f[b[i]] = cb[i];
		else f[b[i]] = min(f[b[i]], cb[i]);
	}
	int cur = N;
	for (int i = A - 5; i >= 0; --i) {
		if (f[i] != 0) cur = min(cur, f[i]);
		update(1, 1, n, i, i, -cur);
	}
	cur = N;
	for (int i = A - 4; i >= 0; --i) {
		if (g[i] != 0) {
			cur = min(cur, g[i]);
		}
		gg[i] = cur;
	}
	for (int i = 1; i <= m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		pack[x].push_back({y, z});
	}
	int res = 0;
	for (int i = 1; i <= A - 5; ++i) {
		cerr << i << ' ' << gg[i + 1] << endl;
		if (i > 10) break;
		for (ii v : pack[i]) {
			cerr << "	" << v.first << endl;
			update(1, 1, n, v.first + 1, A - 5, v.second);
		}
		cerr << "	-> " << tree[1] << endl;
		res = max(res, tree[1] - gg[i + 1]);
	}
	cout << res << endl;

	return 0;
}