#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		string s, t;
		cin >> s >> t;
		int n = s.size();
		s = ' ' + s; t = ' ' + t;
		int res = 0, ok = 1, cur = 0;
		for (int i = 1; i <= n / 2; ++i) {
			char a = s[i], b = s[n - i + 1], c = t[i], d = t[n - i + 1];
			if (cur == 0) {
				if (a == c && b == d) continue;
				if (a == d && b == c) res++;
				else {
					ok = 0;
					break;
				}
				cur = 1;
			} else {
				if (a == d && b == c) continue;
				if (a == c && b == d) res++;
				else {
					ok = 0;
					break;
				}
				cur = 0;
			}
		}
		if (s[n/2 + 1] != t[n / 2 + 1]) {
			cout << -1 << endl;
			continue;
		}
		if (!ok) {
			cout << -1 << endl;
			continue;
		}
		cout << res << endl;
	}

	return 0;
}