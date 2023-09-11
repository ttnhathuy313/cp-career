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
		int n, k;
		cin >> n >> k;
		int res = 0;
		while (n) {
			res += n % k;
			n = n / k * k;
			if (n == 0) {
				break;
			}
			res++;
			n = n / k;
		}
		cout << res << endl;
	}

	return 0;
}