#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 105;
int a[N], b[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int cnt0 = 0;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			a[i] = x;
			if (x == 0) cnt0++;
		}
		int cnt1 = 0;
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			if (x != a[i])
				res++;
			if (x == 0) cnt1++;
		}

		cout << min(abs(cnt0 - cnt1) + 1, res) << endl;
	}

	return 0;
}