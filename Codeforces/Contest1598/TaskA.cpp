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
		string s, t;
		cin >> s >> t;
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (s[i] + t[i] - '0' - '0' == 2) ok = false;
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	

	return 0;
}