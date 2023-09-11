#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 55;
int n, a[N], b[N], c[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n;
	bool found = false;
	int bound = (int)1e3 + 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] > bound) found = true;
	}
	
	int res = 0, turn = 0;
	while (found) {
		// for (int i = 1; i <= n; ++i) {
		// 	cerr << a[i] << ' ';
		// }
		turn++;
		// cerr << endl;
		int s = 0;
		for (int i = 1; i <= n; ++i) {
			int ru = (int)ceil(1.0 * (a[i] - bound) / n);
			if (a[i] > bound) b[i] = ru, a[i] = a[i] - n * ru;
			else b[i] = 0;
			s += b[i];
		}
		res += s;
		found = false;
		for (int i = 1; i <= n; ++i) {
			a[i] = a[i] + s - b[i];
			if (a[i] > bound) found = true;
		}
	}
	// for (int i = 1; i <= n; ++i) {
	// 	cerr << a[i] << ' ';
	// }
	// cerr << turn << endl;
	int tmp = (int)1e9;
	for (int t = 0; t <= 1e5; ++t) {
		int new_bound = n - 1 - t;
		int need = 0;
		for (int i = 1; i <= n; ++i) {
			int ru = (int)ceil(1.0 * (a[i] - new_bound) / (n + 1));
			if (a[i] > new_bound) need += ru;
		}
		if (need <= t) tmp = min(tmp, t);
	}
	cout << res + tmp << endl;

	return 0;
}