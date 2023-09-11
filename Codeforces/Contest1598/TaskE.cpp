#include <bits/stdc++.h>

using namespace std;

struct Node {
	int ans;
	short int consl, consr, len;
	Node() {}
	Node(int _ans, short int _consl, short int _consr, short int _len) : ans(_ans), consl(_consl), consr(_consr), len(_len) {}
};

Node combine(Node trai, Node phai) {
	Node ret;
	ret.ans = trai.ans + phai.ans;
	if (trai.consl == trai.len)
		ret.consl = trai.len + phai.consl;
	else ret.consl = trai.consl;
	if (phai.consr == phai.len)
		ret.consr = phai.len + trai.consr;
	else ret.consr = phai.consr;
	ret.len = trai.len + phai.len;
	ret.ans += trai.consr * phai.consl;
	return ret;
}

struct SegmentTree {
	int n;
	vector <Node> st;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, Node(0, 0, 0, 1));
	}
	int Left(int x) {
		return (x << 1);
	}
	int Right(int x) {
		return (x << 1) + 1;
	}
	void update(int id, int L, int R, int i, int val) {
		if (L > i || R < i) return;
		if (L == R) {
			if (val == 1) {
				st[id] = Node(0, 1, 1, 1);
			} else st[id] = Node(0, 0, 0, 1);
			return;
		}
		int mid = (L + R) >> 1;
		update(Left(id), L, mid, i, val);
		update(Right(id), mid + 1, R, i, val);
		st[id] = combine(st[Left(id)], st[Right(id)]);
	}
	void update(int i, int val) {
		update(1, 1, n, i, val);
	}
	int val() {
		return st[1].ans;
	}
};

const int N = 2005;
int a[N][N], b[N][N], n, m;
SegmentTree IT[2 * N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> m;
	int offset = m, tot = n * m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			b[i][j] = 1;
			a[i + j][i - j + offset] = 1;
		}
	}

	for (int i = 0; i <= n + m; ++i) {
		IT[i] = SegmentTree(n + m + 9);
	}

	for (int i = 2; i <= n + m; ++i) {
		for (int j = 1 - m; j <= n - 1; ++j) {
			if (a[i][j + offset] || a[i][j + offset + 1]) {
				IT[j + offset].update(i, 1);
			}
		}
	}
	int f = 1;
	int res = 0;
	for (int i = 1; i <= n + m; ++i) {
		res += IT[i].val();
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (b[x][y]) {
			tot--;
			b[x][y] = 0;
			if (x == 1 && y == m) f = false;
			int i = x + y, j = x - y;
			res -= IT[j + offset].val() + IT[j + offset - 1].val();
			IT[j + offset].update(i, 0);
			IT[j + offset - 1].update(i, 0);
			res += IT[j + offset].val() + IT[j + offset - 1].val();

		} else {
			tot++;
			b[x][y] = 1;
			if (x == 1 && y == m) f = true;
			int i = x + y, j = x - y;
			res -= IT[j + offset].val() + IT[j + offset - 1].val();
			IT[j + offset].update(i, 1);
			IT[j + offset - 1].update(i, 1);
			res += IT[j + offset].val() + IT[j + offset - 1].val();
		}
		cout << res + tot << endl;
	}

	return 0;
}