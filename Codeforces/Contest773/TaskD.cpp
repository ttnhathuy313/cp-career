#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
typedef pair <int, int> ii;

const int N = 2e3 + 5, oo = 1e18;
int n, d[N], a[N][N];
bool used[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n;
	int minW = oo;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			cin >> a[i][j];
			a[j][i] = a[i][j];
			minW = min(minW, a[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) if (i != j) {
			a[i][j] -= minW;
		}
	}
	for (int i = 1; i <= n; ++i)
		d[i] = oo;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) if (i != j) {
			d[i] = min(d[i], 2 * a[i][j]); 
		}
	}
	for (int t = 0; t < n; ++t) {
		ii mi(oo, oo);
		for (int i = 1; i <= n; ++i) if (!used[i])
			mi = min(mi, ii(d[i], i));
		int u = mi.second, w = mi.first;
		used[u] = 1;
		for (int v = 1; v <= n; ++v) if (v != u) {
			d[v] = min(d[v], w + a[u][v]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << d[i] + minW * (n - 1) << endl;
	}

	return 0;
}