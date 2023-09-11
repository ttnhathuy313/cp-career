#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 250005;
int n, subSize[N], items[N / 2 + 15], d[N / 2 + 15], p2[N], p1[N], ans;
vector <int> adj[N];
ii res;

void prepare(int u, int pre) {
	subSize[u] = 1;
	for (int v : adj[u]) {
		if (v == pre) continue;
		prepare(v, u);
		subSize[u] += subSize[v];
	}
}

void solve(int u, int pre) {
	int mx = 0;
	for (int v : adj[u]) if (v != pre) {
		mx = max(mx, subSize[v]);
		solve(v, u);
	}
	if (~pre) mx = max(mx, n - subSize[u]);
	if (mx > (n - 1) / 2) {
		if (abs(n - 2 * (n - 1 - mx)) < abs(n - 2 * res.first)) {
			res.first = n - 1 - mx;
			res.second = u;
		}
		return;
	}
	memset(items, 0, sizeof items);
	memset(d, 0, sizeof d);
	d[0] = 1;
	int m = (n - 1) / 2;
	for (int v : adj[u]) if (v != pre)
		items[subSize[v]]++;
	items[n - subSize[u]]++;
	for (int i = 1; i <= mx; ++i) if (items[i]) {
		int w = i, sl = items[i];
		vector <int> pre; pre.assign(w, -(int)1e18);
		for (int j = 0; j <= m; ++j) {
			if (d[j]) pre[j % w] = j;
			else {
				if (pre[j % w] >= j - sl * w) {
					d[j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= m; ++i) if (d[i] && abs(n - 2 * i) < abs(n - 2 * res.first)) {
		res.first = i;
		res.second = u;
	}
}

int dfs_count(int u, int pre) {
	int ret = 0;
	for (int v : adj[u]) if (v != pre) {
		ret += dfs_count(v, u);
		subSize[u] += subSize[v];
	}
	ret += subSize[u];
	subSize[u]++;
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("POLARIZATION.INP", "r", stdin);
	freopen("POLARIZATION.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	prepare(1, -1);
	solve(1, -1);
	memset(subSize, 0, sizeof subSize);
	ans = res.first * (n - 1 - res.first) + dfs_count(res.second, -1);
	cout << n - 1 << ' ' << ans << endl;

	return 0;
}