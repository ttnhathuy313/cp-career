#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1005;
int n, k, a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int res = (int)1e9, id = -1;
	for (int first = 1; first <= 1000; ++first) {
		int cur = 0;
		for (int i = 1; i <= n; ++i) {
			cur += (first + (i - 1) * k != a[i]);
		}
		if (cur < res) {
			res = cur;
			id = first;
		}
	}
	cout << res << endl;
	for (int i = 1; i <= n; ++i) {
		int req = id + (i - 1) * k;
		if (a[i] != req) {
			if (a[i] > req) {
				cout << "- " << i << ' ' << a[i] - req << endl;
			} else cout << "+ " << i << ' ' << req - a[i] << endl;
		}
	}

	return 0;
}