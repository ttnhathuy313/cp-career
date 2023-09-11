#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, oo = 1e9 + 7;
int n, x, a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> x;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		int mi = oo, mx = 0, res = 0;
		for (int i = 1; i <= n; ++i) {
			mi = min(mi, a[i]);
			mx = max(mx, a[i]);
			if (mx - mi > 2 * x) {
				res++;
				mi = a[i];
				mx = a[i];
			}
		}
		cout << res << endl;
	}

	return 0;
}