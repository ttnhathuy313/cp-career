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
		if (n == 1) {
			cout << "9" << endl;
		} else if (n == 2) cout << "98" << endl; 
		else {
			cout << "989";
			int cur = 0;
			for (int i = 1; i <= n - 3; ++i) {
				cout << cur;
				cur = (cur + 1) % 10;
			}
			cout << endl;
		}
	}

	return 0;
}