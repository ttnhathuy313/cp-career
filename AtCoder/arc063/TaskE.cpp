#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, val[N], k;
vector <int> adj[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int k;
	cin >> k;
	memset(val, -1, sizeof val);
	priority_queue <ii, vector <ii>, greater <ii>> pq;
	for (int i = 1; i <= k; ++i) {
		int v, p;
		cin >> v >> p;
		val[v] = p;
		pq.push({p, v});
	}
	while (!pq.empty()) {
		int v = pq.top().second;
		int p = pq.top().first;
		pq.pop();
		for (int u : adj[v]) {
			if (~val[u]) {
				if (abs(val[u] - val[v]) != 1) {
					cout << "No" << endl;
					return 0;
				}
			} else {
				val[u] = val[v] + 1;
				pq.push({val[u], u});
			}
		}	
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= n; ++i)
		cout << val[i] << endl;

	return 0;
}