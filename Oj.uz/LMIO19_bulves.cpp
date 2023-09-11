#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e5 + 5;
int n, a[N], b[N], c[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("LMIO19_bulves.INP", "r", stdin);
	freopen("LMIO19_bulves.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		c[i] = c[i - 1] + a[i] - b[i];
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (c[i] < 0) {
			res += -c[i];
			c[i] = 0;
		}
		if (c[i] > c[n]) {
			res += c[i] - c[n];
			c[i] = c[n];
		}
	}
	priority_queue <int> pq;
	while (!pq.empty()) pq.pop();
	for (int i = 1; i <= n; ++i) {
		pq.push(c[i]);
		if (c[i] < pq.top()) {
			res += pq.top() - c[i];
			pq.pop();
			pq.push(c[i]);
		}
	}
	cout << res << endl;

	return 0;
}