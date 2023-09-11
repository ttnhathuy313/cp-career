#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef array <int, 11> huy_t;

const int MOD = 1e9 + 7;
huy_t nothing;

huy_t operator+(const huy_t &a, const huy_t &b) {
	huy_t ret = huy_t();
	for (int i = 0; i < 11; ++i) {
		ret[i] = (a[i] + b[i]) % MOD;
	}
	return ret;
}

void mul(huy_t &a, int b) {
	for (int i = 0; i < 11; ++i) {
		a[i] = a[i] * b;
		a[i] %= MOD;
	}
	return;
}

struct SegmentTree {
	vector <huy_t> st;
	vector <int> lazy;
	int n;

	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n + 1;
		lazy.resize(4 * n + 100);
		st.resize(4 * n + 100);
		for (int i = 0; i < 4 * n + 100; ++i) {
			lazy[i] = 1;
			st[i] = huy_t();
		}
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}

	void push(int id) {
		lazy[Left(id)] = (lazy[id] * lazy[Left(id)]) % MOD;
		mul(st[Left(id)], lazy[id]);
		lazy[Right(id)] = (lazy[id] * lazy[Right(id)]) % MOD;
		mul(st[Right(id)], lazy[id]);
		lazy[id] = 1;
	}

	void mult(int id, int L, int R, int i, int j, int v) {
		if (L > j || R < i) return;
		if (L >= i && R <= j) {
			mul(st[id], v);
			(lazy[id] *= v) %= MOD;
			return;
		}
		int mid = (L + R) >> 1;
		push(id);
		mult(Left(id), L, mid, i, j, v);
		mult(Right(id), mid + 1, R, i, j, v);
		st[id] = st[Left(id)] + st[Right(id)];
	}

	void modify(int id, int L, int R, int i, const huy_t &val) {
		if (L > i || R < i) return;
		if (L == R) {
			st[id] = st[id] + val;
			return;
		}
		int mid = (L + R) >> 1;
		push(id);
		modify(Left(id), L, mid, i, val);
		modify(Right(id), mid + 1, R, i, val);
		st[id] = st[Left(id)] + st[Right(id)];
	}

	huy_t get(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return nothing;
		if (L >= i && R <= j) return st[id];
		int mid = (L + R) >> 1;
		push(id);
		return get(Left(id), L, mid, i, j) + get(Right(id), mid + 1, R, i, j);
	}
	huy_t get(int i, int j) {
		return get(1, 0, n, i, j);
	}
	void mult(int i, int j, int v) {
		mult(1, 0, n, i, j, v);
	}
	void modify(int i, const huy_t &v) {
		modify(1, 0, n, i, v);
	}
};


// sort the segment increasing by the left end
// for i :, for segment : try to add segment [l, r]

// them [l, r] voi i < l : no. cc increases 1 : use binomial theorem to update (i < l)
// them [l, r] voi i < r: no. cc remains unchanged, i became r (now l <= i < r)
// them [l, r] voi r <= i : both unchanged (now i >= r)

// now reverse a little bit

// for segment, for i : try to add segment [l, r] to collection i
// case 1 : use points update in segment tree
// case 2 : get sum and add to r
// case 3 : multiply by 2

const int N = 1e5 + 5;
int n, k, l[N], r[N], C[11][11];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("help.in", "r", stdin);
	freopen("help.out", "w", stdout);

	clock_t tStart = clock();

	nothing = huy_t();
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
	}
	vector <int> ind;
	ind.clear();
	for (int i = 1; i <= n; ++i) ind.push_back(i);
	sort(ind.begin(), ind.end(), [](int i, int j) {
		return l[i] < l[j];
	});
	for (int i = 0; i < 11; ++i) {
		for (int j = 0; j < 11; ++j) {
			if (i == 0 || i == j || j == 0) {
				C[i][j] = 1;
				continue;
			}
			C[i][j] = C[i][j - 1] + C[i - 1][j - 1];
		}
	}
	SegmentTree solver = SegmentTree(2 * n);
	huy_t ori = huy_t();
	ori[0] = 1;
	solver.modify(0, ori);
	int t = 0;
	for (int i : ind) {
		++t;
		huy_t v = solver.get(0, l[i] - 1);
		huy_t adv = huy_t();
		for (int j = 0; j < 11; ++j) {
			adv[j] = 0;
			for (int k = 0; k <= j; ++k) {
				adv[j] += C[k][j] * v[k];
				adv[j] %= MOD;
			}
		}
		v = solver.get(l[i], r[i] - 1);
		solver.mult(r[i], 2 * n, 2);
		solver.modify(r[i], v + adv);
	}
	huy_t res = solver.get(0, 2 * n);
	cout << res[k] << endl;

	fprintf(stderr, "Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

	return 0;
}