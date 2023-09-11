#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
const int N = 2e5 + 5;
int n, a[N], pref[N];
 
void solve() {
	cin >> n;
	bool ok = true;
	bool found = false;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	} 
	while (a[n] == 0 && n > 0) {
		n--;
	}
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + a[i];
		if (pref[i] <= 0 && i != n) {
			ok = false;
		}
	}
	if (pref[n] != 0 || (ok == false)) {
		cout << "No" << endl;
	} else cout << "Yes" << endl;
}
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
 	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.ans", "w", stdout);


	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
 
	return 0;
}