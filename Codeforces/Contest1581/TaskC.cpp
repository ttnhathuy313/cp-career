#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 405;
int n, m, a[N][N], sub[N][N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			a[i][j] = s[j - 1] - '0';
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			sub[i][j] = sub[i - 1][j] + a[i][j];
		}
	}
	int res = N * N;
	for (int upb = 2; upb <= n; ++upb) {
		for (int lwb = upb + 2; lwb < n; ++lwb) {
			bool print = (upb == 2 && lwb == 4);
			vector <int> pref(m + 1, 0), cur(m + 1, 0);
			for (int j = 1; j <= m; ++j) {
				pref[j] = pref[j - 1] + sub[lwb][j] - sub[upb - 1][j];
				if (a[upb - 1][j] == 0) pref[j]++;
				if (a[lwb + 1][j] == 0) pref[j]++;
			}
			for (int j = 1; j <= m; ++j) {
				cur[j] = (lwb - upb + 1) - sub[lwb][j] + sub[upb - 1][j];
				cur[j] -= pref[j];
				if (j != 1) cur[j] = min(cur[j], cur[j - 1]);
			}
			for (int j = 4; j <= m; ++j) {
				int val = (lwb - upb + 1) - sub[lwb][j] + sub[upb - 1][j] + pref[j - 1];
				res = min(res, val + cur[j - 3]);
			}
		}
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}