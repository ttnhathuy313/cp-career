#include <bits/stdc++.h>

using namespace std;
#define int long long
#define NAME "BONUS"

const int N = 305, oo = 1e18;
int memo[N][N][N], n, k, a[N];

int calc(int i, int j, int rem) {
	if (rem == 0) return 0;
	if (i == j) return -oo;
	if (i > j) return -oo;
	if (memo[i][j][rem] != -1) return memo[i][j][rem];
	int ret = -oo;
	ret = max(ret, abs(a[j] - a[i]) + calc(i + 1, j - 1, rem - 2));
	ret = max(ret, abs(a[i] - a[i + 1]) + calc(i + 2, j, rem - 2));
	ret = max(ret, abs(a[j] - a[j - 1]) + calc(i, j - 2, rem - 2));
	ret = max(ret, calc(i + 1, j, rem));
	ret = max(ret, calc(i, j - 1, rem));
	return memo[i][j][rem] = ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(NAME".inp", "r", stdin);
	freopen(NAME".out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	memset(memo, -1, sizeof memo);
	cerr << calc(1, n - 2, 2 * k - 2) << endl;
	cout << calc(1, n, 2 * k) << endl;

	return 0;
}