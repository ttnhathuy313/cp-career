#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5e5 + 5, LOG = 20;
int n, a[N], truyvan, ans[N], basis[N][LOG], b[LOG];
 
struct Query {
	int l, r, id;
	Query() {}
	Query(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}
};
vector <Query> st[4 * N], R[N], L[N];
 
int Left(int x) {return (x << 1);}
int Right(int x) {return (x << 1) + 1;}
 
void add(int id, int L, int R, Query q) {
	int mid = (L + R) >> 1;
	if (L > q.r || R < q.l) return;
	if (q.l <= mid && q.r > mid) {
		st[id].push_back(q);
		return;
	}
	add(Left(id), L, mid, q);
	add(Right(id), mid + 1, R, q);
}
 
void dac(int id, int l_range, int r_range) {
	// cerr << "At [" << l_range << ", " << r_range << "] : " << (l_range + r_range) / 2 << endl;
	for (int i = l_range - 1; i <= r_range + 1; ++i) {
		memset(basis[i], -1, sizeof basis[i]);
	}
	int mid = (l_range + r_range) >> 1;
	for (int i = mid; i >= l_range; --i) {
		int val = a[i];
		for (int j = 0; j < LOG; ++j) basis[i][j] = basis[i + 1][j];
		for (int j = LOG - 1; j >= 0; --j) if (val & (1 << j)) {
			if (~basis[i][j]) val ^= basis[i][j];
			else {
				basis[i][j] = val;
				break;
			}
		}
	}
	for (int i = mid + 1; i <= r_range; ++i) {
		int val = a[i];
		if (i != mid + 1) {
			for (int j = 0; j < LOG; ++j) basis[i][j] = basis[i - 1][j];
		}
		for (int j = LOG - 1; j >= 0; --j) if (val & (1 << j)) {
			if (~basis[i][j]) {
				val ^= basis[i][j];
			} else {
				basis[i][j] = val;
				break;
			}
		}
	}

	for (Query q : st[id]) {
		for (int j = 0; j < LOG; ++j) b[j] = basis[q.l][j];
		for (int j = 0; j < LOG; ++j) if (~basis[q.r][j]) {
			int val = basis[q.r][j];
			for (int k = LOG - 1; k >= 0; --k) if (val & (1 << k)) {
				if (~b[k]) val ^= b[k];
				else {
					b[k] = val;
					break;
				}
			}
		}
		int tmp = 0;
		for (int j = LOG - 1; j >= 0; --j) if (~b[j] && (tmp & (1 << j)) == 0) {
			tmp ^= b[j];
		}
		ans[q.id] = tmp;
	}

	if (l_range == r_range) return;
	dac(Left(id), l_range, mid);
	dac(Right(id), mid + 1, r_range);
}
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.inp", "r", stdin);
	freopen("TaskF.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> truyvan;
	for (int i = 1; i <= truyvan; ++i) {
		int l, r;
		cin >> l >> r;
		if (l != r) add(1, 1, n, Query(l, r, i));
		else ans[i] = a[l];
	}
	dac(1, 1, n);
	for (int i = 1; i <= truyvan; ++i) 
		cout << ans[i] << endl;
 
	return 0;
}