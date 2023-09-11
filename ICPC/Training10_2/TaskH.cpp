#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 3e5 + 5;
int n, mark[N], deg[N], mark2[N];
vector <int> pt[N], adj[N], res2, adj2[N];
map <ii, int> pos; 
set <ii> rem;
queue <int> q;

void dfs(int u) {
	mark[u] = 1;
	cout << u << ' ';
	for (int v : adj2[u]) {
		if (!mark[v]) {
			dfs(v);
		}
	}
}

void init() {
	for (int i = 1; i <= n; ++i) {
		mark[i] = mark2[i] = 0;
		deg[i] = 0;
		pt[i].clear();
		adj[i].clear();
		adj2[i].clear();
	}
	while (!q.empty()) q.pop();
	res2.clear();
	pos.clear();
	rem.clear();
}

void solve() {
	cin >> n;
	init();
	for (int i = 1; i <= n - 2; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		pt[i].push_back(a);
		pt[i].push_back(b);
		pt[i].push_back(c);
		sort(pt[i].begin(), pt[i].end());
		for (int x1 = 0; x1 < 3; ++x1) {
			for (int y1 = x1 + 1; y1 < 3; ++y1) {
				rem.insert({pt[i][x1], pt[i][y1]});
			}
		}
	}

	for (int i = 1; i <= n - 2; ++i) {
		bool print = (i == 7);
		for (int x1 = 0; x1 < 3; ++x1) {
			for (int y1 = x1 + 1; y1 < 3; ++y1) {
				if (pos.find({pt[i][x1], pt[i][y1]}) != pos.end()) {
					int j = pos[{pt[i][x1], pt[i][y1]}];
					if (rem.find({pt[i][x1], pt[i][y1]}) != rem.end()) {
						rem.erase({pt[i][x1], pt[i][y1]});
					}
					adj[i].push_back(j);
					adj[j].push_back(i);
					deg[i]++;
					deg[j]++;
				} else {
					pos[{pt[i][x1], pt[i][y1]}] = i;
				}
			}
		}
	}

	for (ii d : rem) {
		adj2[d.first].push_back(d.second);
		adj2[d.second].push_back(d.first);
	}

	dfs(1);
	cout << endl;

	for (int i = 1; i <= n - 2; ++i) if (deg[i] == 1) {
		q.push(i);
		mark2[i] = 1;
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		res2.push_back(u);
		for (int v : adj[u]) if (!mark2[v]) {
			deg[v]--;
			deg[u]--;
			if (deg[v] == 1) {
				mark2[v] = 1;
				q.push(v);
			}
		}
	}

	if (res2.empty()) {
		cout << 1 << endl;
		return;
	}

	for (int v : res2) {
		cout << v << ' ';
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskH.INP", "r", stdin);
	freopen("TaskH.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}