#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 200;
int n, a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		bool ok = true;
		for (int i = 2; i <= sqrt(sum); ++i) if (sum % i == 0)
			ok = false;
		if (!ok || (sum == 2)) {
			cout << n << endl;
			for (int i = 1; i <= n; ++i) {
				cout << i << ' ';
			}
			cout << endl;
			continue;
		}
		int id = -1;
		for (int i = 1; i <= n; ++i) if (a[i] & 1)
			id = i;
		cout << n - 1 << endl;
		for (int i = 1; i < id; ++i) {
			cout << i << ' ';
		}
		for (int i = id + 1; i <= n; ++i) {
			cout << i << ' ';
		}
		cout << endl;
	}

	return 0;
}