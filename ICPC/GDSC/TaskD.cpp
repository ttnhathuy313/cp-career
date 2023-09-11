#include <bits/stdc++.h>

using namespace std;

const int N = 5005, M = 1e5 + 5;
int n, k, a[N], cnt[M];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int rem = k - a[i] - a[j];
			if (rem <= 0) continue;
			int temp = cnt[rem] - (a[i] == rem) - (a[j] == rem);
			res += temp;
		}
	}
	res /= 3 ;
	cout << res << endl;

	return 0;
}