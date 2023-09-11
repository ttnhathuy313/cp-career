#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e5 + 5;
int dp[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		for (int i = 0; i < (int)1e9; ++i) {
			a += i;
			if (a >= b && (a - b) % 2 == 0) {
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}