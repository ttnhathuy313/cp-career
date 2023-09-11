#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 40500;
int a[N], b[N], n, m, k, f[N], g[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	int pre = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0) {
			pre = i;
			continue;
		}
		f[1]++;
		f[i - pre + 1]--;
	}
	pre = 0;
	for (int i = 1; i <= m; ++i) {
		if (b[i] == 0) {
			pre = i;
			continue;
		}
		g[1]++;
		g[i - pre + 1]--;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) f[i] += f[i - 1];
	for (int i = 1; i <= m; ++i) g[i] += g[i - 1];
	for (int i = 1; i <= n; ++i) if (k % i == 0) {
		int j = k / i;
		if (j > m) continue;
		res += f[i] * g[j];
	}
	cout << res << endl;

	return 0;
}