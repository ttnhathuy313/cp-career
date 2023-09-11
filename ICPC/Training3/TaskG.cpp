#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e4 + 6;
int n, a[N], m, p[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	cin >> m >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> p[i];
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (p[i]) res = max(res, m - a[i]);
		else res = max(res, a[i]);
	}
	cout << res << endl;

	return 0;
}