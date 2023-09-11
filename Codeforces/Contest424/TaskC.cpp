#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 5;
int xorSum[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	freopen("TaskC.out", "w", stdout);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		int p;
		cin >> p;
		res ^= p;
	}
	for (int i = 1; i <= n; ++i) {
		xorSum[i] = xorSum[i - 1] ^ i;
	}
	for (int i = 2; i <= n; ++i) {
		if ((n / i) % 2 == 1) res ^= xorSum[i - 1];
		res ^= (xorSum[n % i]);
	}
	cout << res << endl;

	return 0;
}