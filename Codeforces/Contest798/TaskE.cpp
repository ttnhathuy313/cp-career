#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

struct SegmentTree {
	vector <ii> st;
	int n;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.resize(4 * n + 5);
		for (int i = 0; i < 4 * n + 5; ++i)
			st[i] = ii(-1, -1);
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}	
	void update(int id, int L, int R, int i, int val) {
		if (L > i || R < i) return;
		if (L == R) {
			st[id] = ii(val, i);
			return;
		}
		int mid = (L + R) >> 1;
		update(Left(id), L, mid, i, val);
		update(Right(id), mid + 1, R, i, val);
		st[id] = max(st[Left(id)], st[Right(id)]);
	}
	ii get(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return ii(-1, -1);
		if (L >= i && R <= j) {
			return st[id];
		}
		int mid = (L + R) >> 1;
		return max(get(Left(id), L, mid, i, j), get(Right(id), mid + 1, R, i, j));
	}
	void update(int i, int val) {
		update(1, 1, n, i, val);
	}
	ii get(int i, int j) {
		return get(1, 1, n, i, j);
	}
} IT;

const int N = 5e5 + 5;
int n, a[N], b[N], ans[N];
bool mark[N];
vector <int> topo_sort;

void dfs(int i) {
	IT.update(i, 0);
	mark[i] = 1;
	if (!mark[b[i]] && b[i] != n + 1 && IT.get(b[i], b[i]).second) dfs(b[i]);
	while (1) {
		ii d = IT.get(1, a[i] - 1);
		if (d.first <= i) break;
		IT.update(d.second, 0);
		if (!mark[d.second] && IT.get(d.second, d.second).second) dfs(d.second);
	}
	topo_sort.push_back(i);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n;
	IT = SegmentTree(n);
	for (int i = 1; i <= n; ++i) {
		b[i] = n + 1;
	}	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] == -1) a[i] = n + 1;
		b[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		IT.update(i, b[i]);
	}
	for (int i = 1; i <= n; ++i) if (!mark[i]) {
		dfs(i);
	}
	for (int i = 0; i < topo_sort.size(); ++i) {
		ans[topo_sort[i]] = i + 1;
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';

	return 0;
}