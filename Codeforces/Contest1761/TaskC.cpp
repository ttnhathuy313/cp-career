#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int n, b[N][N], deg[N];
set <int> ans[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			string t;
			cin >> t;
			for (int j = 1; j <= n; ++j) {
				b[i][j] = t[j - 1] == '1';
				if (b[i][j]) {
					deg[j]++;
				}
			}
			ans[i].clear();
			ans[i].insert(i);
		}
		queue <int> q;
		while (!q.empty()) {
			q.pop();
		}
		for (int i = 1; i <= n; ++i) {
			if (deg[i] == 0) {
				q.push(i);
				cerr << i << endl;
			}
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v = 1; v <= n; ++v) if (b[u][v]) {
				for (int vv : ans[u]) {
					ans[v].insert(vv);
				}
				b[u][v] = 0;
				deg[v]--;
				if (deg[v] == 0) {
					q.push(v);
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			cout << ans[i].size() << ' ';
			for (int v : ans[i]) {
				cout << v << ' ';
			}
			cout << endl;
		}
	}

	return 0;
}