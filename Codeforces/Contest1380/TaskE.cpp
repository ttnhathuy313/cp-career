#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, a[N], lt, m, pre[N], lab[N], mark[N];
vector <int> pt[N];

int root(int x) {
	return (lab[x] == -1 ? x : lab[x] = root(lab[x]));
}

void merge(int u, int v) {
	int x = root(u), y = root(v);
	if (x == y) return;
	if (pt[x].size() < pt[y].size()) {
		swap(x, y);
	}
	lab[y] = x;
	for (int v : pt[y]) {
		pt[x].push_back(v);
		if (root(v) == root(v - 1)) {
			lt += 1 - mark[v - 1];
			mark[v - 1] = 1;
		}
		if (root(v) == root(v + 1)) {
			lt += 1 - mark[v];
			mark[v] = 1;
		}
	}
	
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	memset(pre, -1, sizeof pre);
	memset(lab, -1, sizeof lab);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pt[i].push_back(i);
		if (~pre[a[i]]) {
			merge(pre[a[i]], i);
		}
		pre[a[i]] = i;
	}
	cout << n - 1 - lt << endl;
	for (int i = 1; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		merge(pre[u], pre[v]);
		cout << n - 1 - lt << endl;
	}

	return 0;
}