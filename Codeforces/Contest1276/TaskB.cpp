#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ms(a) memset(a, 0, sizeof a)

const int N = 4e5 + 5;
int n, m, a, b, dfsTime, tin[N], low[N], cnt, val[N], tout[N];
vector <int> adj[N], biComp[N], Tadj[N];
bool mark[N], isCut[N];
stack <int> S;

void init() {
	cnt = dfsTime = 0;
	for (int i = 1; i <= 2 * n; ++i) {
		tin[i] = low[i] = val[i] = tout[i] = isCut[i] = mark[i] = 0;
		Tadj[i].clear(); adj[i].clear(); biComp[i].clear();
	}
	while (!S.empty()) S.pop();
}

void dfs(int u, int pre) {
	S.push(u);
	mark[u] = 1;
	tin[u] = low[u] = ++dfsTime;
	for (int v : adj[u]) {
		if (v == pre) continue;
		if (!mark[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= tin[u]) {
				cnt++;
				//cerr << "Biconnected cc no " << cnt << " includes : ";
				while (S.top() != v) {
					//cerr << S.top() << ' ';
					biComp[S.top()].push_back(cnt);
					S.pop();
				}
				S.pop();
				//cerr << u << ' ' << v << endl;
				biComp[u].push_back(cnt);
				biComp[v].push_back(cnt);
			}
		} else low[u] = min(low[u], tin[v]);
	}
}

void trv(int u, int pre) {
	tin[u] = ++dfsTime;
	for (int v : Tadj[u]) {
		if (v == pre) continue;
		trv(v, u);
		val[u] += val[v];
	}
	tout[u] = ++dfsTime;
}	

void solve() {
	cin >> n >> m >> a >> b;
	init();
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; ++i) {
		if (biComp[i].size() == 1) {
			val[n + biComp[i][0]]++;
		} else {
			isCut[i] = 1;
			for (int j : biComp[i]) {
				Tadj[i].push_back(n + j);
				Tadj[j + n].push_back(i);
				val[i] = 1;
			}
		}
	}
	if (!isCut[a] || !isCut[b]) {
		cout << 0 << endl;
		return;
	}
	dfsTime = 0;
	trv(n + 1, -1);
	int res = 0;
	if (tin[a] > tin[b]) swap(a, b);
	if (tout[a] > tout[b]) {
		for (int v : Tadj[a]) if (tin[v] <= tin[b] && tout[v] >= tout[b] && tin[v] > tin[a]) {
			res = (val[b] - 1) * (n - val[v] - 1);
		}
	} else res = (val[a] - 1) * (val[b] - 1);
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}