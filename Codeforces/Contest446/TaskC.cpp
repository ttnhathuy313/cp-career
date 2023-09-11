#include <bits/stdc++.h>

using namespace std;
#define int long long
#define Left(x) x >> 1
#define Right(x) (x >> 1) + 1
typedef pair <int, int> ii;

const int N = 3e5 + 5, MOD = 1e9 + 9;
int a[N], n, m, f1[4 * N], f2[4 * N];

void add(int &x, int y) {
	x = (x + y) % MOD;
}

int mult(int &x, int y) {
	return x * y % MOD;
}

ii fib(int n) {
	if (n == 0) {
		return ii(0, 1);
	}
	ii pre = fib(n >> 1);
	int c = pre.first * (2 * pre.second - pre.first + MOD) % MOD;
	int d = (pre.first * pre.first) % MOD + (pre.second * pre.second) % MOD;
	if (n & 1) return ii(d, c + d);
	else return ii(c, d);
}

void update(int id, int L, int R, int i, int j) {
	if (L > j || R < i) return;
	if (L >= i && R <= j) {
		ii c = fib(L - i + 1);
		add(f1[id], c.first);
		add(f2[id], c.second);
		return;
	}
	int mid = (L + R) >> 1;
	update(Left(id), L, mid, i, j);
	update(Right(id), mid + 1, R, i, j);
}

int query(int id, int L, int R, int i) {
	int t = 0;
	if (L <= i && R >= i) {
		ii c = fib(i - L - 1);
		add(t, mult(c.first, f1[id]));
		add(t, mult(c.second, f2[id]));
	} else return 0;
	int mid = (L + R) >> 1;
	return (query(Left(id), L, mid, i) + query(Right(id), mid + 1, R, i) + t) % MOD;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	freopen("TaskC.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i) {
		int type, l, r;
		cin >> type >> l >> r;
		if (type == 1) {
			update(1, 1, n, l, r);
		} else {
			cout << query(1, 1, n, l, r) << endl;
		}
	}

	return 0;
}