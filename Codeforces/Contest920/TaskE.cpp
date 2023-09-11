#include <bits/stdc++.h>

using namespace std;

struct SegmentTree  {
	int n;
	vector <int> st;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n + 5;
		st.assign(4 * n + 5, 0);
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}
	void update(int id, int L, int R, int i, int d) {
		if (L > i || R < i) return;
		if (L == R) {
			st[id] = d;
			return;
		}
		int mid = (L + R) >> 1;
		update(Left(id), L, mid, i, d);
		update(Right(id), mid + 1, R, i, d);
		st[id] = st[Left(id)] + st[Right(id)];
	}
	int q(int id, int L, int R, int i) {
		if (L > i || R < i) return -1;
		if (L == R) return st[id];
		int mid = (L + R) >> 1;
		return max(q(Left(id), L, mid, i), q(Right(id), mid + 1, R, i));
	}
	int get(int id, int L, int R) {
		if (st[id] == 0) return -1;
		if (L == R) return L;
		int mid = (L + R) >> 1;
		if (st[Left(id)] > 0) return get(Left(id), L, mid);
		else return get(Right(id), mid + 1, R);
	}
	int get() {
		return get(1, 1, n);
	}
	int at(int i) {
		return q(1, 1, n, i);
	}
	void update(int i, int j) {
		update(1, 1, n, i, j);
	}
} IT;

const int N = 2e5 + 5;
int n, m, sz[N], cc;
bool mark[N];
vector <int> adj[N];

void dfs(int u) {
	IT.update(u, 0);
	vector <int> hoisinh; hoisinh.clear();
	for (int v : adj[u]) if (IT.at(v)) {
		hoisinh.push_back(v);
		IT.update(v, 0);
	}
	vector <int> nxt; nxt.clear();
	while (1) {
		int v = IT.get();
		if (v == -1) break;
		nxt.push_back(v);
		IT.update(v, 0);
	}
	for (int v : hoisinh) IT.update(v, 1);
	sz[cc]++;
	for (int v : nxt) dfs(v);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	IT = SegmentTree(n);
	for (int i = 1; i <= n; ++i) IT.update(i, 1);
	for (int i = 1; i <= n; ++i) if (IT.at(i)) {
		++cc;
		dfs(i);
	}
	cout << cc << endl;
	sort(sz + 1, sz + 1 + cc);
	for (int i = 1; i <= cc; ++i)
		cout << sz[i] << ' ';

	return 0;
}