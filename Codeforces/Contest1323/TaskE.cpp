#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
typedef pair <int, int> ii;

const int N = 5e5 + 5, MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
int n, m, c[N], d[N];
vector <int> adj[N];
map <vector <int>, int> D;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
		}
		for (int i = 1; i <= n; ++i) cin >> c[i];
		for (int i = 1; i <= m; ++i) {
			int u, v;
			cin >> u >> v;
			// cerr << v << ' ' << u << endl;
			adj[v].push_back(u);
		}
		D.clear();
		for (int i = 1; i <= n; ++i) {
			sort(adj[i].begin(), adj[i].end());
			if (adj[i].size() > 0) D[adj[i]] += c[i];
		}
		int res = 0;
		for (auto &item : D) res = __gcd(res, item.second);
		cout << res << endl;
	}

	return 0;
}