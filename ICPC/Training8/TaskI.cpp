#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskI.INP", "r", stdin);
	freopen("TaskI.OUT", "w", stdout);

	double r, R, h, ans;
	cin >> r >> R >> h;

	ans = tan((0.5 * atan(h / (R - r)))) * R;
	if (ans > h / 2) ans = h / 2;
	cout << fixed << setprecision(12) << ans << endl;

	return 0;
}