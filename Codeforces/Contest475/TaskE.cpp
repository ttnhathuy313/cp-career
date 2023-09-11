#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2005;
int n, m, tin[N], low[N], dfsTime, biComp[N], biCount, val[N], res, subSize[N], cnt[N];
vector <int> adj[N], Tadj[N];
bool mark[N], F[N];
stack <int> S;

void dfs(int u, int pre) {
	mark[u] = 1;
	S.push(u);
	tin[u] = low[u] = ++dfsTime;
	for (int v : adj[u]) {
		if (v == pre) continue;
		if (!mark[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else low[u] = min(low[u], tin[v]);
	}
	if (low[u] == tin[u]) {
		biCount++;
		// cerr << "Biconnected Components no" << biCount << " includes : ";
		while (S.top() != u) {
			int v = S.top(); S.pop();
			biComp[v] = biCount;
			// cerr << v << ' ';
			val[biCount]++;
		}
		biComp[u] = biCount; S.pop();
		// cerr << u << endl;
		val[biCount]++;
	}
}

void calc(int u, int pre) {
	for (int v : Tadj[u]) {
		if (v == pre) continue;
		calc(v, u);
		cnt[u] += cnt[v];
		subSize[u] += subSize[v];
	}
	subSize[u] += val[u];
	cnt[u] += subSize[u] * val[u];
	int ans = 0;
	if (pre != -1) return;
	for (int v : Tadj[u]) ans += cnt[v] + subSize[v] * val[u];
	ans += val[u] * val[u];
	F[0] = 1;
	int tot = subSize[u] - val[u];
	for (int v : Tadj[u]) {
		for (int i = tot; i >= subSize[v]; --i)
			F[i] |= F[i - subSize[v]];
	}
	int tmp = 0;
	for (int i = 0; i <= tot; ++i) if (F[i]) {
		tmp = max(tmp, i * (tot - i));
	}
	ans += tmp;
	res = max(res, ans);
}

signed main() {
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
	dfs(1, -1);
	set <ii> cur; cur.clear();
	for (int i = 1; i <= n; ++i) {
		for (int j : adj[i]) {
			int u = biComp[i], v = biComp[j];
			if (u == v) continue;
			if (cur.find({u, v}) != cur.end()) continue;
			cur.insert({u, v}); cur.insert({v, u});
			Tadj[u].push_back(v); Tadj[v].push_back(u);
		}
	}
	for (int i = 1; i <= biCount; ++i) {
		memset(subSize, 0, sizeof subSize);
		memset(cnt, 0, sizeof cnt);
		memset(F, 0, sizeof F);
		calc(i, -1);
	}
	cout << res << endl;

	return 0;
}