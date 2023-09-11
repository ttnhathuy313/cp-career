#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, offset = 2e5;
//sublime text
int n, m, perm[N], a[N], pref[N], cnt_l[2 * N], cnt_r[2 * N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskEE.INP", "r", stdin);
	freopen("TaskEE.OUT", "w", stdout);

	cin >> n >> m;
	int idx_m = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> perm[i];
		if (perm[i] < m) {
			a[i] = -1;
		} else if (perm[i] > m) {
			a[i] = 1;
		} else a[i] = 0;

		if (perm[i] == m) {
			idx_m = i;
		}
	}

	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + a[i];
		cerr << pref[i] << ' ';
	}
	cerr << endl;

	cnt_l[offset]++;
	for (int i = 1; i < idx_m; ++i) {
		cnt_l[pref[i] + offset]++;
	}
	for (int i = idx_m; i <= n; ++i) {
		cnt_r[pref[i] + offset]++;
	}

	int res = 0;
	for (int i = idx_m; i <= n; ++i) {
		res += cnt_l[pref[i] + offset] + cnt_l[pref[i] - 1 + offset];
	}

	cout << res << endl;

	return 0;
}