#include <bits/stdc++.h>

using namespace std;
#define int long long

bool cmp(int x, int k) {
	return 2.0 * x / k >= k + 1;
}

const int N = 1e6 + 5;
int res[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int n, k;
	cin >> n >> k;
	if (k + 1 > 2.0 * n / k) {
		cout << -1 << endl;
		return 0;
	}
	int maxID = -1;
	for (int i = 1; i <= sqrt(n); ++i) if (n % i == 0) {
		if (cmp(i, k)) maxID = max(maxID, n / i);
		if (cmp(n / i, k)) maxID = max(maxID, i);
	}
	int req = n / maxID;
	for (int i = 1; i <= k; ++i) {
		res[i] = i;
		req -= i;
	}
	res[k] += req;
	for (int i = 1; i <= k; ++i)
		cout << res[i] * maxID << ' ';

	return 0;
}