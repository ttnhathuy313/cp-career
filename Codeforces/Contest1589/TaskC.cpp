#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 405, offset = 100;
int n, a[N], b[N], f[N], g[N], ff[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int mx = 0;
	for (int x = 1; x <= 1000; ++x) {
		for (int y = 1; y <= 1000; ++y) {
			int tot = x * x + y * y;
			int cnt = 0;
			int s = x + y;
			for (int i = 1; i <= x + y; ++i) if (i <= (s - i)) {
				if (i * i + (s - i) * (s - i) == tot) cnt++;
			}
			mx = max(mx, cnt);
		}
	}
	cerr << mx << endl;

	return 0;
}