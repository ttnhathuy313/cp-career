#include <bits/stdc++.h>

using namespace std;
#define int long long
#define forn(i, a, b) for (int i = a; i <= b; ++i)

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int s, t;
	cin >> s >> t;
	int res = 0;
	forn(i, 0, s) forn(j, 0, s) forn(k, 0, s) {
		if (i + j + k <= s && i * j * k <= t) res++;
	}
	cout << res << endl;

	return 0;
}