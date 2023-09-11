#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 105;
int n, a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		int cur = 0, ans = 1;
		for (int i = 1; i <= n; ++i) {
			if (cur + a[i] <= i - 2) {
				ans = 0;
				break;
			}
			cur += a[i] - i + 1;
		}
		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}