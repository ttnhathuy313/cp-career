#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 105;
int n, mark[N], k;
ii p[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {
			cin >> p[i].first >> p[i].second;
		}
		sort(p + 1, p + 1 + n);
		memset(mark, 0, sizeof mark);
		int res = 0;
		for (int i = 1; i <= n; ++i) if (!mark[i]) {
			res++;
			for (int j = 1; j <= n; ++j) if (abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second) <= k)
				mark[j] = 1;

		}
		cout << res << endl;
	}

	return 0;
}