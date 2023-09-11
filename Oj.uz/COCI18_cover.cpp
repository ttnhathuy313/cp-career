#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5005, oo = 1e18;
int n, f[N], g[N], x[N], y[N], lst[N];
map <int, int> mpList;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("COCI18_cover.INP", "r", stdin);
	freopen("COCI18_cover.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		x = abs(x), y = abs(y);
		cerr << "(" << x << ", " << y << ")" << endl;
		mpList[x] = max(mpList[x], y);
	}
	int m = 0;
	for (auto V : mpList) {
		int _x = V.first, _y = V.second;
		m++;
		x[m] = _x;
		y[m] = _y;
	}
	for (int i = m; i >= 1; --i) {
		int j = i + 1;
		for (j = i + 1; j <= m; ++j) {
			if (y[j] > y[i]) break;
		}
		lst[i] = j - 1;
	}
	for (int i = 1; i <= m; ++i) {
		f[i] = g[i] = oo;
	}
	f[1] = g[1] = x[1] * y[1];
	for (int i = 2; i <= m; ++i) {
		int k = i;
		for (k = i; k >= 1; --k) if (y[k] > y[i])
			break;
		k++;
		f[i] = x[i] * y[i] + g[k - 1];
		g[i] = f[i];
		for (int j = 1; j < i; ++j) if (lst[j] >= i)
			g[i] = min(g[i], f[j] + (x[i] - x[j]) * y[j]);
	}
	g[m] <<= 2;
	cout << g[m] << endl;

	return 0;
}