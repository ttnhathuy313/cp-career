#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int mx = 0, g = -1;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			if (i == 1) {
				g = x;
			} else g = __gcd(g, x);
			mx = max(mx, x);
		}
		cout << (mx / g) << endl;
	}

	return 0;
}