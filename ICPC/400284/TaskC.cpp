#include <bits/stdc++.h>

using namespace std;

const int N = 55;
int n, a[N][N], res[N], index[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	for (int val = 1; val <= n; ++val) {
		for (int i = 1; i <= n; ++i) {
			bool ok = true;
			for (int j = 1; j <= n; ++j) {
				if (i == j)
					continue;
				if (a[i][j] < val) {
					if (index[a[i][j]] != j) {
						ok = false;
					}
				}
				if (a[i][j] > val)
					ok = false;
			}
			if (ok) {
				// cerr << val << ' ' << i << endl;
				res[i] = val;
				index[val] = i;
				break;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << res[i] << ' ';
	}

	return 0;
}