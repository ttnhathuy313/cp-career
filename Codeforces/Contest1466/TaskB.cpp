#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, cnt[N], ok[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= 2 * n + 2; ++i)
			cnt[i] = ok[i] = 0;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			cnt[x]++;
		}
		int res = 0;
		for (int i = 1; i <= 2 * n; ++i) if (cnt[i]) {
			if (cnt[i + 1] == 0) {
				if (cnt[i] > 1 || ok[i]) res += 2;
				else res++;
			} else {
				res++;
				if (cnt[i] > 1 || ok[i]) ok[i + 1] = 1;
			}
		}
		cout << res << endl;
	}

	return 0;
}