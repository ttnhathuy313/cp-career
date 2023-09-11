#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int p, f, a, b, s, w;
		cin >> p >> f >> a >> b >> s >> w;
		if (s > w) {
			swap(s, w);
			swap(a, b);
		}
		int res = 0;
		for (int cs = 0; cs <= a; ++cs) {
			if (cs * s <= p) {
				int cw = min(b, (p - cs * s) / w);
				int remb = b - cw;
				int d;
				if (f <= (a - cs) * s) d = f / s;
				else {
					int v = f - (a - cs) * s;
					d = a - cs + min(remb, v / w);
				}
				res = max(res, cs + cw + d);
			}
		}
		cout << res << endl;
	}

	return 0;
}