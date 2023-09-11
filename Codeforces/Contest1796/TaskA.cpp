#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	string t = "";
	for (int i = 0; i < 60; ++i) {
		if (i % 3 == 0) {
			t = t + "F";
		}
		if (i % 5 == 0) {
			t = t + "B";
		}
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int k;
		cin >> k;
		string s;
		cin >> s;
		bool ok = false;
		for (int i = 0; i < (int)t.size() - k + 1; ++i) {
			if (t.substr(i, k) == s) {
				ok = true;
				break;
			}
		}
		if (ok) {
			cout << "YES" << endl; 
		} else cout << "NO" << endl;
	}

	return 0;
}