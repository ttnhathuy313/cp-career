#include <bits/stdc++.h>

using namespace std;

const int N = 3505;
int n, a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		int d = m - 1;
		k = min(k, m - 1);
		d = m - 1 - k;
		int res = 0;
		for (int i = 0; i <= k; ++i) {
			int t = (int)1e9 + 5;
			for (int j = 0; j <= d; ++j) {
				int l = i + j + 1, r = n - (k - i) - (d - j);
				t = min(t, max(a[l], a[r]));
			}
			res = max(res, t);
		}
		cout << res << endl;
	}

	return 0;
}