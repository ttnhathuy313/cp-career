#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e4 + 5, MOD = 1e9 + 7;
int n, t[N], T;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> T;
	int A, B, C;
	cin >> A >> B >> C >> t[1];
	for (int i = 2; i <= n; ++i) {
		t[i] = ((A * t[i - 1] + B) % C) + 1;
	}
	sort(t + 1, t + 1 + n);
	int pref = 0, ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; ++i) {
		if (t[i] <= T) {
			T -= t[i];
			pref += t[i];
			pref %= MOD;
			ans1++;
			ans2 = (ans2 + pref) % MOD;
		}
	}
	cout << ans1 << ' ' << ans2 << endl;

	return 0;
}