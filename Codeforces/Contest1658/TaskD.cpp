#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, a[N], l, r, org[N];
map <int, int> cnt;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> l >> r;
		n = r + 1;
		cnt.clear();
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			org[i] = a[i];
			int msk = 0;
			for (int j = 17; j >= 0; --j) {
				msk |= (1 << j);
				cnt[a[i] & msk]++;
			}
		}
		int res = -1;
		for (int i = 1; i <= n; ++i) {
			int assume = a[i];
			int msk = 0;
			bool ok = true;
			for (int j = 17; j >= 0; --j) {
				msk |= (1 << j);
				int equal = (assume & msk) ^ (r & msk);
				if (equal & (1 << j)) continue;
				if (cnt[equal ^ (1 << j)]) ok = false;
			}
			if (ok) res = assume;
		}
		for (int i = 1; i <= n; ++i) {
			cerr << (org[i] ^ res) << ' ';
		} cerr << endl;
		cout << res << endl;
	}

	return 0;
}