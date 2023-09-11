#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int u, v, c;
};

const int N = 1e5 + 5;
int n, m, rev[N], mark[N];
vector <Edge> Elist;
vector <int> adj[N], topo;
bool ok;

void dfs(int u) {
	mark[u] = 1;
	for (int v : adj[u]) {
		if (mark[v] == 0) {
			dfs(v);
		} else if (mark[v] == 1) {
			ok = false;
			return;
		}
	}
	topo.push_back(u);
	mark[u] = 2;
}

bool check(int mid) {
	for (int i = 1; i <= n; ++i) adj[i].clear();
	topo.clear();
	for (Edge e : Elist) {
		if (e.c > mid) {
			adj[e.u].push_back(e.v);
		}
	}
	ok = true;
	memset(mark, 0, sizeof mark);
	for (int i = 1; i <= n; ++i) if (!mark[i]) {
		dfs(i);
	}
	reverse(topo.begin(), topo.end());
	return ok;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		Elist.push_back({u, v, c});
	}
	int l = 0, r = (int)1e9, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	check(ans);
	for (int i = 0; i < n; ++i) rev[topo[i]] = i;
	vector <int> res; res.clear();
	for (int i = 0; i < m; ++i) if (rev[Elist[i].u] > rev[Elist[i].v])
		res.push_back(i);
	cout << ans << ' ' << res.size() << endl;
	for (int v : res) cout << v + 1 << ' ';

	return 0;
}