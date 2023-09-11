#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef pair <int, int> ii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int N = 2e5 + 5, oo = 1e18;
int n, a[N], subSize[N], h[N], ans[N];
vector <ii> adj[N];
ordered_set S;

void prepare(int u) {
	subSize[u] = 1;
	for (ii v : adj[u]) {
		h[v.first] = h[u] + v.second;
		prepare(v.first);
		subSize[u] += subSize[v.first];
	}
}

void get(int u) {
	S.insert(ii(h[u] - a[u], u));
	for (ii v : adj[u]) get(v.first);
}

void dfs(int u, bool keep) {
	int maxSz = 0, bigChild = -1;
	for (ii v : adj[u]) {
		if (subSize[v.first] > maxSz) {
			maxSz = subSize[v.first];
			bigChild = v.first;
		}
	}
	for (ii v : adj[u]) if (v.first != bigChild)
		dfs(v.first, 0);
	if (bigChild != -1) dfs(bigChild, 1);
	for (ii v : adj[u]) if (v.first != bigChild) {
		get(v.first);
	}
	ans[u] = (int)S.order_of_key(ii(h[u], oo));
	S.insert(ii(h[u] - a[u], u));
	if (!keep) S.clear();
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	S.clear();
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 2; i <= n; ++i) {
		int p, w;
		cin >> p >> w;
		adj[p].push_back(ii(i, w));
	}
	prepare(1);
	dfs(1, 1);
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';

	return 0;
}