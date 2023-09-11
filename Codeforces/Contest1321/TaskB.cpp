#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, offset = 2 * N;
int res[N * 6], n, b[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		res[offset + i - b[i]] += b[i];
	}
	int ans = 0;
	for (int i = 0; i < N * 6; ++i) {
		ans = max(ans, res[i]);
	}
	cout << ans << endl;

	return 0;
}