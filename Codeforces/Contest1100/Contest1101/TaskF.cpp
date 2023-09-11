#include <bits/stdc++.h>

using namespace std;
#define int long long

struct Truck {
	int s, f, c, r;
};

const int N = 2e5 + 5e4 + 5;
int a[N], n, m, o[N];
Truck t[N];

bool check(int mid, int id) {
	int rem = mid, require = 0;
	for (int i = t[id].s; i < t[id].f; ++i) {
		if ((a[i + 1] - a[i]) * t[id].c > mid) return false;
	}
	for (int i = t[id].s + 1; i < t[id].f; ++i) {
		rem -= (a[i] - a[i - 1]) * t[id].c;
		if ((a[i + 1] - a[i]) * t[id].c > rem) {
			require++;
			rem = mid;
		}
	}
	if (require > t[id].r) return false;
	else return true;
}

main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.inp", "r", stdin);
	freopen("TaskF.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i) {
		cin >> t[i].s >> t[i].f >> t[i].c >> t[i].r;
		o[i] = i;
	}
	random_shuffle(o + 1, o + 1 + m);
	int res = 0;
	for (int i = 1; i <= m; ++i) {
		if (check(res, o[i])) continue;
		int l = 0, r = 1e18, ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid, o[i])) r = mid - 1, ans = mid;
			else l = mid + 1;
		}
		res = ans;
	}
	cout << res << endl;

	return 0;
}