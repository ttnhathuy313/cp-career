#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, k, h[N], temp;
vector <int> adj[N];

int dfs(int u, int curDepth, int cap) {
	int ret = 0;
	for (int v : adj[u]) {
		if (curDepth + 1 > cap) {
			ret++;
			ret += dfs(v, 1, cap);
		} else ret += dfs(v, curDepth + 1, cap);
	}
	return ret;
}

void dfs2(int u, int cap) {
	h[u] = 1;
	for (int v : adj[u]) {
		dfs2(v, cap);
		if (h[v] == cap && u != 1) temp++;
		else h[u] = max(h[u], h[v] + 1);
	}}

bool check(int mid) {
	temp = 0;
	dfs2(1, mid);
	return min(dfs(1, 0, mid), temp) <= k;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
	}
	for (int i = 2; i <= n; ++i) {
		int j;
		cin >> j;
		adj[j].push_back(i);
	}

	int l = 1, r = n, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1; 
		} else l = mid + 1;
	}
	cout << ans << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}	

	return 0;
}