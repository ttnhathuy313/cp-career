#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1005;
int n, x[N], y[N];
map <ii, int> M;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}
	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		M.clear();
		for (int j = 1; j <= n; ++j) if (j != i) {
			int X = x[j] - x[i], Y = y[j] - y[i];
			int vv = __gcd(X, Y);
			X /= vv; Y /= vv;
			if (Y < 0) {
				X *= -1;
				Y *= -1;
			}
			mx = max(mx, ++M[{X, Y}]);
		}
	}
	if ((mx + 1) / 2 > n - mx - 1) cout << n - mx - 1 << endl;
	else cout << n / 3 << endl;

	return 0;
}