#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, offset = 1e5;
int cnt[3 * N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		string s;
		cin >> s;
		int bal = 0;
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') bal++;
			else bal--;
			cnt[bal + offset]++;
		}
		if (bal == 0) {
			if ((x >= -n && x <= n && cnt[x + offset] > 0) || x == 0) cout << "-1\n";
			else cout << 0 << endl;
			continue;
		}
		int lw = max(0LL, (x - n) / bal), up = max(0LL, (x + n) / bal);
		int res = 0;
		if (x == 0) res++;
		for (int i = min(lw, up); i <= max(up, lw); ++i) {
			if (!(x - i * bal >= -n && x - i * bal <= n)) continue;
			res += cnt[x - i * bal + offset];
		}
		cout << res << endl;
	}

	return 0;
}