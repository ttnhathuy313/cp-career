#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 3e5 + 5;
int suf[N], pref[N], a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			suf[i] = pref[i] = 0;
		}
		for (int i = 2; i < n; ++i) {
			if (a[i] > a[i + 1] && a[i] > a[i - 1]) pref[i] = 1;
			if (a[i] < a[i + 1] && a[i] < a[i - 1]) pref[i] = 1;
			pref[i] = pref[i - 1] + pref[i];
		}
		for (int i = n - 1; i >= 2; --i) {
			if (a[i] > a[i + 1] && a[i] > a[i - 1]) suf[i] = 1;
			if (a[i] < a[i + 1] && a[i] < a[i - 1]) suf[i] = 1;
			suf[i] = suf[i + 1] + suf[i];
		}
		int res = pref[n - 1];
		a[0] = a[1]; a[n + 1] = a[n];
		for (int i = 2; i < n; ++i) {
			int tmp = pref[i - 2] + suf[i + 2];
			int mi = min(a[i - 1], a[i + 1]);
			int tmp1 = 0;
			if ((a[i - 1] - mi + 1) * (a[i - 1] - a[i - 2]) > 0) tmp1++;
			if ((a[i + 1] - mi + 1) * (a[i + 1] - a[i + 2]) > 0) tmp1++;
			res = min(res, tmp + tmp1 + 1);
			int mx = max(a[i - 1], a[i + 1]);
			tmp1 = 0;
			if ((a[i - 1] - mx - 1) * (a[i - 1] - a[i - 2]) > 0) tmp1++;
			if ((a[i + 1] - mx - 1) * (a[i + 1] - a[i + 2]) > 0) tmp1++;
			res = min(res, tmp + tmp1 + 1);
			tmp1 = (a[i + 1] - a[i - 1]) * (a[i + 1] - a[i + 2]) > 0 ? 1 : 0;
			res = min(res, tmp + tmp1);
			tmp1 = (a[i - 1] - a[i + 1]) * (a[i - 1] - a[i - 2]) > 0 ? 1 : 0;
			res = min(res, tmp + tmp1);
		}
		cout << res << endl;
	}

	return 0;
}