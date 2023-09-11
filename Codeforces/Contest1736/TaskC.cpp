#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			a[i] -= i;
		}
		int r = 1, res = 0;
		for (int l = 1; l <= n; ++l) {
			while (r <= n && a[r] >= -l + 1) {
				r++;
			}
			res += r - l;
		}
		cout << res << endl;
	}

	return 0;
}