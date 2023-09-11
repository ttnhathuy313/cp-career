#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int n, a[N], b[N], c[N], res[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1; i <= n; ++i)
			cin >> b[i];
		for (int i = 1; i <= n; ++i)
			cin >> c[i];
		memset(res, 0, sizeof res);
		res[1] = a[1];
		for (int i = 2; i <= n; ++i) {
			if (i == n) {
				if (a[i] != res[i - 1] && a[i] != res[1]) {
					res[i] = a[i];
					continue;
				}
				if (b[i] != res[i - 1] && b[i] != res[1]) {
					res[i] = b[i];
					continue;
				}
				if (c[i] != res[i - 1] && c[i] != res[1]) {
					res[i] = c[i];
					continue;
				}

				break;
			}
			if (a[i] != res[i - 1]) {
				res[i] = a[i];
				continue;
			}
			if (b[i] != res[i - 1]) {
				res[i] = b[i];
				continue;
			}
			if (c[i] != res[i - 1]) {
				res[i] = c[i];
				continue;
			}
		}
		for (int i = 1; i <= n; ++i)
			cout << res[i] << ' ';
		cout << endl;
	}

	return 0;
}