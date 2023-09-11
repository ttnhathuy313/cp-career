#include <bits/stdc++.h>

using namespace std;

const int N = 505, oo = 1e9;
int memo[N][N][N], a[N], n, x;

int calc(int i, int pre, int x) {
	if (i == n) return 0;
	if (~memo[i][pre][x]) return memo[i][pre][x];
	int ret = oo;
	if (pre <= x && a[i + 1] > x) ret = min(ret, calc(i + 1, x, a[i + 1])) + 1;
	if (pre <= a[i + 1]) ret = min(ret, calc(i + 1, a[i + 1], x));
	return memo[i][pre][x] = ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		n, x;
		cin >> n >> x;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i <= n; ++i) {
			memset(memo[i], -1, sizeof memo[i]);
		}
		cout << (calc(0, 0, x) == oo ? -1 : calc(0, 0, x)) << endl;
	}

	return 0;
}