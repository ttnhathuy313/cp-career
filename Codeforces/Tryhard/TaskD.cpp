#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5005;
int r[N], x[N], y[N], n, m;
double p[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> r[i] >> p[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i];
	}
	double res = 0;
	for (int i = 1; i <= n; ++i) {
		int avail = 0;
		for (int j = 1; j <= m; ++j) {
			if (x[j] * x[j] + y[j] * y[j] <= r[i] * r[i]) avail++;
		}
		res += 1.0 * avail * p[i] / 100.0;
	}
	cout << fixed << setprecision(10) << res;

	return 0;
}