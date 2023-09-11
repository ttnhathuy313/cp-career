#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int a[N], n, d[130], res = N;
bool mark[130];

void dfs(int u, int pre) {
	mark[u] = 1;
	if (~pre) d[u] = d[pre] + 1;
	for (int v = 1; v <= n; ++v) if (a[v] && (a[u] & a[v]) != 0 && v != u) {
		if (mark[v]) {
			if (v != pre) res = min(res, abs(d[u] - d[v]) + 1);
		} else {
			// cerr << u << ' ' << v << endl;
			dfs(v, u);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i]) cnt++;
	}
	if (cnt > 128) {
		cout << 3 << endl;
		return 0;
	}
	sort(a + 1, a + 1 + n, greater <int>());
	for (int i = 1; i <= n; ++i) if (a[i]) {
		memset(mark, 0, sizeof mark);
		memset(d, 0, sizeof d);
		dfs(i, -1);
	}
	if (res == N) res = -1;
	cout << res << endl;

	return 0;
}