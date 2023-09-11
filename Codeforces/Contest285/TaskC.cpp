#include <bits/stdc++.h>

using namespace std;
#define int long  long

const int N = 3e5 + 5;
int n, a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	int res = 0;
	for (int i = 1; i <= n; ++i) res += abs(a[i] - i);
	cout << res << endl;

	return 0;
}