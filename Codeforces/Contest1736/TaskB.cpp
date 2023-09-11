#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, a[N], b[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (int i = 1; i <= n + 1; ++i) {
			if (i == 1) {
				b[i] = a[i];
			} else if (i == n + 1) {
				b[i] = a[i - 1];
			} else {
				b[i] = a[i] * a[i - 1] / __gcd(a[i], a[i - 1]);
			}
		}
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			if (__gcd(b[i], b[i + 1]) != a[i]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;
	}

	return 0;
}