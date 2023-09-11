#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int k, a, b, v;
	cin >> k >> a >> b >> v;
	int afford = b / (k - 1);
	if (afford * k * v >= a) {
		cout << a / (k * v) + (a % (k * v) != 0) << endl;
		return 0;
	}
	a -= afford * k * v;
	int res = afford, rem = (b % (k - 1));
	if ((rem + 1) * v >= a) {
		cout << res + 1 << endl;
		return 0;
	}
	a -= (rem + 1) * v;
	res++;
	res += (a / v) + (a % v != 0);
	cout << res << endl;

	return 0;
}