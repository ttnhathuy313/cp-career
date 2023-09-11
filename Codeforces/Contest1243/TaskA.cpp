#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1005;
int a[N];

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.inp", "r", stdin);
	freopen("TaskA.out", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		sort(a + 1, a + 1 + n);
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			if (i + a[i] - 1 <= n) res = max(res, a[i]);
			else res = max(res, n - i + 1);
		}
		cout << res << endl;
	}

	return 0;
}