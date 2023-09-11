#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 3e5 + 5;
int n, dpl[N], cons1[N], cons0[N], dpr[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		n = s.size();
		s = ' ' + s;
		dpl[0] = 0;
		dpr[n + 1] = 0;
		for (int i = 1; i <= n; ++i) {
			dpl[i] = dpl[i - 1] + (s[i] == '1');
			if (s[i] == '1') cons1[i] = cons1[i - 1] + 1;
			else cons1[i] = 0;
		}
		cons0[n + 1] = cons0[n + 2] = 0;
		for (int i = n; i >= 1; --i) {
			dpr[i] = dpr[i + 1] + (s[i] == '0');
			if (s[i] == '0') cons0[i] = cons0[i + 1] + 1;
			else cons0[i] = 0;
		}
		int res = N;
		for (int i = 1; i <= n + 1; i++) {
			res = min(res, dpl[i - 1] + dpr[i]);
		}
		int res2 = 0;
		for (int i = 1; i <= n + 1; ++i) if (dpl[i - 1] + dpr[i] == res) {
			if (i >= 2) res2 = max(res2, cons1[i - 2]);
			res2 = max(res2, cons0[i + 1]);
		} 
		cout << res * (int)1e12 + res - res2 << endl;
	}

	return 0;
}