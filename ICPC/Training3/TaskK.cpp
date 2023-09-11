#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1005;
int n, m, a[N], b[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskK.INP", "r", stdin);
	freopen("TaskK.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int j = 1; j <= m; ++j) {
		cin >> b[j];
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res += b[i] - a[i];
	}
	for (int i = n + 1; i <= m; ++i) {
		res += b[i];
	}
	cout << res << endl;

	return 0;
}