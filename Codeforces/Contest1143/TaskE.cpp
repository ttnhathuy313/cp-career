#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

struct SegmentTree {
	vector <pair <int, int> > st;
	int n;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.resize(4 * n + 5);
		for (int i = 0; i < 4 * n + 5; ++i) st[i] = make_pair(oo, 0);
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}
 
	void update(int id, int L, int R, int i, int val) {
		if (L > i || R < i) return;
		if (L == R) {
			st[id] = make_pair(val, i);
			return;
		} else {
			int mid = (L + R) >> 1;
			update(Left(id), L, mid, i, val);
			update(Right(id), mid + 1, R, i, val);
			st[id] = min(st[Left(id)], st[Right(id)]);
		}
	}

	pair <int, int> query(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return make_pair(oo, 0);
		if (L >= i && R <= j) return st[id];
		int mid = (L + R) >> 1;
		return min(query(Left(id), L, mid, i, j), query(Right(id), mid + 1, R, i, j));
	}
 
	void update(int i, int val) {update(1, 1, n, i, val);}
	int query(int i, int j) {
		return query(1, 1, n, i, j).first;
	}
};

const int N = 2e5 + 5, LOGA = 20;
int n, m, q, p[N], A[N], trv[N][LOGA], lst[N], dwn[N][LOGA], ending[N], nextOne[N], a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);

	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		int d;
		cin >> d;
		p[d] = i;
	}
	for (int i = 1; i <= m; ++i) cin >> A[i];
	for (int i = 1; i <= m; ++i) a[i] = p[A[i]];
	memset(trv, -1, sizeof trv);
	memset(lst, -1, sizeof lst);
	memset(dwn, -1, sizeof dwn);
	memset(ending, -1, sizeof ending);

	for (int i = m; i >= 1; --i) {
		lst[a[i]] = i;
		trv[i][0] = lst[a[i] + 1];
		dwn[i][0] = lst[a[i] - 1];
		nextOne[i] = lst[1];
		for (int j = 1; j < LOGA; j++) {
			if (~trv[i][j - 1]) trv[i][j] = trv[trv[i][j - 1]][j - 1];
			if (~dwn[i][j - 1]) dwn[i][j] = dwn[dwn[i][j - 1]][j - 1];
		}
	}

	// for (int i = 1; i <= m; ++i) cerr << a[i] << ' ';
	// cerr << endl;

	SegmentTree IT(m);
	for (int i = 1; i <= m; ++i) {
		int cur = i;
		for (int j = LOGA - 1; j >= 0; --j) if ((1 << j) <= n - a[cur] && trv[cur][j] != -1)
			cur = trv[cur][j];
		if (a[cur] != n || (nextOne[cur] == -1 && a[i] != 1)) continue;
		if (a[i] == 1) {
			ending[i] = cur;
			IT.update(i, cur);
			//cerr << "ending of " << i << " is " << cur << endl;
			continue;
		}
		cur = nextOne[cur];
		for (int j = LOGA - 1; j >= 0; --j) if ((1 << j) <= a[i] - 1 - a[cur] && trv[cur][j] != -1) {
			cur = trv[cur][j];
		}
		if (a[cur] != a[i] - 1) continue;
		ending[i] = cur;
		//cerr << "ending of " << i << " is " << cur << endl;
		IT.update(i, cur);
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (IT.query(l, r) <= r) cout << 1;
		else cout << 0;
	}

	return 0;
}