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
		string s;
		cin >> s;
		int n = s.size();
		int res = 0;
		for (int i = 1; i < n; ++i) {
			if (s[i] == s[i - 1]) {
				res++;
				s[i] = '$';
			}
			if (i > 1 && s[i] == s[i - 2] && s[i] != '$') {
				res++;
				s[i] = '$';
			}
		}
		cout << res << endl;
	}

	return 0;
}