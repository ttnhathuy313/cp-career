#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e4 + 5;
int n, a[N], b[N], d, wa[N], wb[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	cin >> n >> d;
	int V = 0;
	for (int i = 1; i <= n; ++i) {
		int v, x, y;
		cin >> v >> x >> y;
		a[v] += x;
		b[v] += y;
		V += x + y;
	}
	int wx = 0, wy = 0;
	for (int i = 1; i <= d; ++i) {
		if (a[i] > b[i]) {
			wa[i] = a[i] - (a[i] + b[i]) / 2 - 1, wb[i] = b[i];
			cout << "A " << wa[i] << ' ' << b[i] << endl;
		} else {
			wa[i] = a[i], wb[i] = b[i] - (a[i] + b[i]) / 2 - 1;
			cout << "B " << wa[i] << ' ' << wb[i] << endl;
		}
		wx += wa[i];
		wy += wb[i];
	}
	cout << fixed << setprecision(9) << 1.0 * abs(wx - wy) / V << endl;

	return 0;
}