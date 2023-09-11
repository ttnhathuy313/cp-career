#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		s = ' ' + s;
		int res = 0;
		for (int i = 2; i <= n; ++i) {
			if (s[i - 1] == '0' && s[i] == '0') {
				res += 2;
			} else {
				if (i > 2 && s[i - 2] == '0' && s[i] == '0') {
					res++;
				}
			}
		}
		cout << res << endl;
	}

	return 0;
}