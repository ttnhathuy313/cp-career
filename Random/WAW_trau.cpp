#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, a[N], rev[N], subSize[N], cnt[N], ccnt[N], ans[N];
vector <int> adj[N], r1, r2;

void prepare(int u) {
	subSize[u] = 1;
	for (int v : adj[u]) {
		prepare(v);
		subSize[u] += subSize[v];
	}
}

void get(int u, vector <int> &w) {
	w.push_back(u);
	for (int v : adj[u])
		get(v, w);
}

void dfs(int u) {
	vector <int> w;
	w.clear();
	get(u, w);
	memset(cnt, 0, sizeof cnt);
	int mx = 0;
	for (int v : w) {
		cnt[a[v]]++;
		mx = max(mx, cnt[a[v]]);
		cerr << a[v] << endl;
	}
	for (int v = 0; v <= 1000; ++v) {
		if (cnt[v] == mx) {
			ans[u] += v;
			cnt[v] = 0;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("WAW.INP", "r", stdin);
	freopen("WAW.OUT", "w", stdout);

	cin >> n;
	vector <int> val; val.clear();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		val.push_back(a[i]);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i)
		dfs(i);
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';

	return 0;
}