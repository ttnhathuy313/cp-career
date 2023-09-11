#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;

double lg(double x) {
	if (abs(x) < 1e-9) {
		return 0;
	} else return log2(x);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int p, tot;
	cin >> p >> tot;
	if (p == 0) {
		cerr << 0 << endl;
		return 0;
	}
	double x = 1.0 * p / tot;
	cerr << fixed << setprecision(8) << -(x * lg(x) + (1 - x) * lg(1 - x)) << endl;

	return 0;
}