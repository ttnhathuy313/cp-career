#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, a[N], trace[N], ans[N];
vector <ii> adj[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("BOI13_brunhilda.INP", "r", stdin);
	// freopen("BOI13_brunhilda.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = i; k >= 0; --k) if (k % a[j] == 0) {
				adj[i].push_back({k, j});
				// cerr << i << ' ' << k << endl;
				break;
			}
		}
	}
	queue <int> q; while (!q.empty()) q.pop();
	memset(trace, -1, sizeof trace);
	q.push(m);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (ii d : adj[u]) {
			int v = d.first, val = d.second;
			if (~trace[v]) continue;
			trace[v] = u;
			ans[v] = val;
			q.push(v);
		}
	}
	int cur = 0;
	vector <ii> res; res.clear();
	while (cur != m) {
		res.push_back({trace[cur], cur});
		cur = trace[cur];
	}
	reverse(res.begin(), res.end());
	cout << res.size() << endl;
	for (ii d : res) {
		// cout << d.first << " with call " << a[ans[d.second]] << " replaced with " << d.second << endl;
		// cout << a[ans[d.second]] << ' ';
	}

	return 0;
}