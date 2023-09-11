#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, w[N], deg[N], ans[N];

void solve() {
	vector <int> id;
	id.clear();
	cin >> n;
	ans[1] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
		ans[1] += w[i];
		id.push_back(i);
		deg[i] = 0;
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
	}
	sort(id.begin(), id.end(), [](int i, int j) {
		return w[i] > w[j];
	});
	int l = 1;
	for (int i : id) {
		int v = deg[i]; v--;
		while (v--) {
			l++;
			ans[l] = ans[l - 1] + w[i];
		}
	}
	for (int i = 1; i < n; ++i)
		cout << ans[i] << ' ';
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}