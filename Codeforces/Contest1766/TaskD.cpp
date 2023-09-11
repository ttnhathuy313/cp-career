#include <bits/stdc++.h>

using namespace std;

const int V = 4000, N = 1e7;
int f[N];

void sieve() {
	for (int i = 2; i < N; ++i) if (f[i] == 0) {
		f[i] = i;
		for (long long j = 1LL * i * i; j < N; j += i) f[j] = i;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	sieve();

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		if (a == b - 1) {
			cout << -1 << endl;
			continue;
		}
		if (__gcd(a, b) != 1) {
			cout << 0 << endl;
			continue;
		}
		if ((a % 2) == (b % 2)) {
			cout << 1 << endl;
			continue;
		}
		int need_fac = b - a;
		vector <int> facc;
		facc.clear();
		while (need_fac > 1) {
			int g = f[need_fac];
			facc.push_back(g);
			while (need_fac % g == 0) {
				need_fac /= g;
			}
		}

		int res = (int)1e7;
		for (auto d : facc) {
			int v = d;
			res = min(res, (v + (v - a % v)) % v);
		}
		if (res == (int)1e7) {
			cout << -1 << endl;
		} else cout << res << endl;
	}

	return 0;
}