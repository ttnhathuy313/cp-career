#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

const int N = 4e5 + 5;
int n, q, a[N], st[8 * N], tin[N], tout[N], dfsTime;
vector <int> adj[N];

void dfs(int u, int pre) {
	tin[u] = ++dfsTime;
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
	}
	tout[u] = ++dfsTime;
}

int Left(int x) {return (x << 1);}
int Right(int x) {return (x << 1) + 1;}

void update(int id, int L, int R, int i, int val) {
	if (L > i || R < i) return;
	if (L == R) {
		st[id] = (1LL << (val - 1));
		return;
	}
	int mid = (L + R) >> 1;
	update(Left(id), L, mid, i, val);
	update(Right(id), mid + 1, R, i, val);
	st[id] = st[Left(id)] | st[Right(id)];
}

int get(int id, int L, int R, int i, int j) {
	if (L > j || R < i) return 0;
	if (L >= i && R <= j) return st[id];
	int mid = (L + R) >> 1;
	return get(Left(id), L, mid, i, j) | get(Right(id), mid + 1, R, i, j);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; ++i) {
		update(1, 1, 2 * n, tin[i], a[i]);
	}
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int u, c;
			cin >> u >> c;
			update(1, 1, 2 * n, tin[u], c);
		} else {
			int u;
			cin >> u;
			cout << __builtin_popcountll(get(1, 1, 2 * n, tin[u], tout[u])) << endl;
		}
	}

	return 0;
}