#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, a[N], rev[N], subSize[N], cnt[N], ccnt[N], ans[N];
vector <int> adj[N], r1, r2;

void prepare(int u, int pre) {
	subSize[u] = 1;
	for (int v : adj[u]) if (v != pre) {
		prepare(v, u);
		subSize[u] += subSize[v];
	}
}

void get(int u, vector <int> &w, int pre) {
	w.push_back(u);
	for (int v : adj[u]) if (v != pre)
		get(v, w, u);
}

void add(int color) {
	ccnt[cnt[color]] -= rev[color];
	r1.push_back(cnt[color]);
	cnt[color]++;
	ccnt[cnt[color]] += rev[color];
	r1.push_back(cnt[color]);
	r2.push_back(color);
}

int dfs(int u, bool keep, int pre) {
	int maxSz = 0, bigChild = -1;
	for (int v : adj[u]) {
		if (v == pre) continue;
		if (subSize[v] > maxSz) {
			maxSz = subSize[v];
			bigChild = v;
		}
	}
	for (int v : adj[u]) if (v != bigChild && v != pre)
		dfs(v, 0, u);
	int mx = 0;
	if (~bigChild) mx = dfs(bigChild, 1, u);
	for (int v : adj[u]) if (v != bigChild && v != pre) {
		vector <int> w;
		w.clear();
		get(v, w, u);
		for (int vv : w) {
			add(a[vv]);
			mx = max(mx, cnt[a[vv]]);
		}
	}
	add(a[u]);
	mx = max(mx, cnt[a[u]]);

	ans[u] = ccnt[mx];
	if (keep) return mx;
	for (int k : r1) ccnt[k] = 0;
	for (int k : r2) cnt[k] = 0;
	r1.clear(); r2.clear();
	return mx;
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
		adj[v].push_back(u);
	}
	map <int, int> mp; mp.clear();
	sort(val.begin(), val.end());
	int pre = -1, id = 0;
	for (int i = 0; i < n; ++i) {
		if (pre != val[i])
			id++;
		mp[val[i]] = id;
		rev[id] = val[i];
		pre = val[i];
	}
	for (int i = 1; i <= n; ++i)
		a[i] = mp[a[i]];
	prepare(1, -1);
	dfs(1, 1, -1);
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';

	return 0;
}