#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, a[N], p[N];
map <int, int> lst;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int res = 0, l = 1;
	lst[0] = 0;
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i - 1] + a[i];
		int newL;
		if (lst.find(p[i]) == lst.end()) {
			newL = 1;
		} else {
			newL = lst[p[i]] + 2;
		}
		lst[p[i]] = i;
		l = max(l, newL);
		res += i - l + 1;
		cerr << l << ' ' << i << endl;
	}
	cout << res << endl;

	return 0;
}