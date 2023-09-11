#include <bits/stdc++.h>

using namespace std;

const int N = 305;
int a[N], b[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res += abs(a[i] - b[i]);
	}
	cout << fixed << setprecision(9) << 1.0 / n * res << endl;

	return 0;
}