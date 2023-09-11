#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <double, int> ii;

const int N = 1e5 + 5;
int n, t[N];
double x[N], rem[N];

double check(double T) {
	double l = 0.0, r = 1e9;
	for (int i = 1; i <= n; ++i) {
		rem[i] = T - t[i];
		// cerr << x[i] - rem[i] << ' ' << x[i] + rem[i] << endl;
		if (rem[i] < 0) {
			return -1;
		}
		l = max(l, x[i] - rem[i]);
		r = min(r, x[i] + rem[i]);
	}
	if (l > r) return -1;
	else return l;
	
	return -1;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
	}
	int iterator = 120;
	double l = 0, r = 1e9, ans = -1;
	while (iterator--) {
		double mid = (l + r) / 2;
		// cerr << fixed << setprecision << mid << endl;
		double curAns = check(mid);
		if (curAns != -1) {
			r = mid;
			ans = curAns;
		} else {
			l = mid;
		}
	}
	cout << fixed << setprecision(9) << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}