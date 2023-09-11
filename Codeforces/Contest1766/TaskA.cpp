#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 5;
int res[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	for (int i = 1; i < N; ++i) {
		int x = i;
		int cnt = 0;
		while (x) {
			if (x % 10 > 0) cnt++;
			x /= 10;
		}
		if (cnt == 1) res[i] = 1;
	}
	for (int i = 1; i < N; ++i) {
		res[i] += res[i - 1];
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		cout << res[n] << endl;
	}

	return 0;
}