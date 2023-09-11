#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[(int)1e6+5];
signed main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("DUAXE.INP", "r", stdin);
	freopen("DUAXE.OUT", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1;;) {
		int temp1 = 1, j, z;
		for (j = i + 1;; j++) {
			if (a[j+1] > a[j]) {
				for (z = j; z <= n; z++) {
					if (z == n) {
						if (a[z] <= a[i]) temp1 = a[z];
						ans += a[z] - temp1;
						cout << ans ;
						return 0;
					}
					temp1 = (a[z] <= a[i]) ? a[z] : temp1;

					if (a[z + 1] < a[z]) break;
				}
				ans += a[z] - temp1;
				i = z;
				break;
			}
		}
	}
	

	return 0;
}