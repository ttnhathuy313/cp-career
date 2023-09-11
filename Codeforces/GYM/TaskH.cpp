#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, m, tin[N], low[N], dfsTime, biComp[N], biCount, dp[N], res;
vector <int> adj[N], Tadj[N];
bool mark[N];
stack <int> st;

void dfs(int u, int pre) {
	tin[u] = low[u] = ++dfsTime;
	st.push(u);
	mark[u] = 1;
	for (int v : adj[u]) {
		if (v == pre) continue;
		if (!mark[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else low[u] = min(low[u], tin[v]);
	}
	if (tin[u] == low[u]) {
		biCount++;
		while (st.top() != u) {
			int v = st.top();
			st.pop();
			biComp[v] = biCount;
		}
		biComp[u] = biCount;
		st.pop();
	}
}

void dfs2(int u, int pre) {
	vector <int> w;
	w.clear();
	for (int v : Tadj[u]) {
		if (v == pre) continue;
		dfs2(v, u);
		w.push_back(dp[v]);
	}
	sort(w.begin(), w.end(), greater <int> ());
	if (w.size() == 0) {
		dp[u] = 0;
		return;
	}
	dp[u] = w[0] + 1;
	res = max(res, dp[u]);
	if ((int)w.size() > 1) {
		res = max(res, w[0] + w[1] + 2);
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskH.inp", "r", stdin);
	freopen("TaskH.out", "w", stdout);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		res = 0;
		memset(dp, 0, sizeof dp);
		memset(tin, 0, sizeof tin);
		dfsTime = 0;
		memset(biComp, 0, sizeof biComp);
		biCount = 0;
		memset(mark, 0, sizeof mark);
		while (!st.empty()) st.pop();
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
			Tadj[i].clear();
		}
		for (int i = 1; i <= m; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(1, -1);
		set <ii> S;
		S.clear();
		for (int u = 1; u <= n; ++u) {
			for (int v : adj[u]) {
				if (biComp[u] == biComp[v]) continue;
				int x = biComp[u], y = biComp[v];
				if (x > y) swap(x, y);
				if (S.find(ii(x, y)) != S.end()) continue;
				S.insert(ii(x, y));
				Tadj[x].push_back(y);
				Tadj[y].push_back(x);
			}
		}
		dfs2(1, -1);
		cout << biCount - 1 - res << endl;
	}
	return 0;
}