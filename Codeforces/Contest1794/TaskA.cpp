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
		string s = "", t = "";
		for (int i = 1; i <= 2 * n - 2; ++i) {
			string x;
			cin >> x;
			if (x.size() == n - 1) {
				if (s == "") {
					s = x;
				} else t = x;
			}
		}
		reverse(t.begin(), t.end());
		if (s == t) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;
	}

	return 0;
}