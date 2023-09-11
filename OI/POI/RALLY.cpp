#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e5 + 5;
int n, m, dp[N], dp_rev[N], mx[N], mx_rev[N], pos[N];
vector <int> adj[N], topo, fadj[N], topo2;
bool mark[N];

void dfs1(int u) {
	mark[u] = 1;
	for (int v : adj[u]) if (!mark[v]) {
		dfs1(v);
	}
	topo.push_back(u);
}

void dfs2(int u) {
	mark[u] = 1;
	for (int v : fadj[u]) if (!mark[v]) {
		dfs2(v);
	}
	topo2.push_back(u);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("RALLY.INP", "r", stdin);
	freopen("RALLY.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		fadj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) if (!mark[i]) 
		dfs1(i);
	reverse(topo.begin(), topo.end());
	int id = 0;
	for (int u : topo) {
		cerr << u << ' ';
		pos[u] = id++;
		dp[u] = max(dp[u], 1LL);
		for (int v : adj[u])
			dp[v] = max(dp[v], dp[u] + 1);
	} cerr << endl;
	memset(mark, 0, sizeof mark);
	for (int i = 1; i <= n; ++i) if (!mark[i]) 
		dfs2(i);
	reverse(topo2.begin(), topo2.end());
	for (int u : topo2) {
		dp_rev[u] = max(dp_rev[u], 1LL);
		for (int v : fadj[u])
			dp_rev[v] = max(dp_rev[v], dp_rev[u] + 1);
	}	
	int beg = 0, res = (int)1e18;
	multiset <int> lst, cross; lst.clear(), cross.clear();
	for (int i = 1; i < n; ++i) lst.insert(dp_rev[topo[i]]);
	for (int i = 1; i < n - 1; ++i) {
		int u = topo[i - 1];
		cerr << topo[i] << endl;	
		beg = max(beg, dp[u]);
		cerr << "	Left side : " << beg << endl;
		lst.erase(lst.find(dp_rev[topo[i]]));
		for (int v : adj[u]) if (pos[v] > i) {
			cross.insert(dp[u] + dp_rev[v]);
		}
		u = topo[i];
		for (int v : fadj[u]) if (pos[v] < i - 1) {
			cross.erase(cross.find(dp_rev[u] + dp[v]));
		}
		int tmp = beg;
		if (cross.size()) tmp = max(tmp, *(cross.rbegin()));
		tmp = max(tmp, *(lst.rbegin()));
		res = min(res, tmp);
		cerr << "	Right side : " << *(lst.rbegin()) << endl;
		cerr << "	Crossfire  : ";
		if (cross.size()) cerr << *(cross.rbegin()) << endl;
		else cerr << "none" << endl;
	}
	cout << res << endl;

	return 0;
}