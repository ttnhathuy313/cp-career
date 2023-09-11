#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, k, d, w, dead[N];

void solve() {
	cin >> n >> k >> d >> w;
	for (int i = 1; i <= n; ++i) {
		cin >> dead[i];
	}
	sort(dead + 1, dead + 1 + n);
	int res = 0, cur_rem = 0, expire = -1;
	for (int i = 1; i <= n; ++i) {
		if (expire < dead[i]) {
			cur_rem = k - 1;
			expire = dead[i] + w + d;
			res++;
		} else if (cur_rem > 0) {
			cur_rem--;
		} else {
			cur_rem = k - 1;
			expire = dead[i] + w + d;
			res++;
		}
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}