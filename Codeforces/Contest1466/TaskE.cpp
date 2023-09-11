#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e5 + 5, MOD = 1e9 + 7;
int n, x[N], term1[N], term2[N], cnt[66];

void add(int &a, int b) {
	b %= MOD;
	a %= MOD;
	a = (a + b) % MOD;
}
void mul(int &a, int b) {
	b %= MOD;
	a %= MOD;
	a = a * b % MOD;
}

void solve() {
	cin >> n;
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= n; ++i) {
		term2[i] = 0;
		cin >> x[i];
		for (int j = 0; j < 60; ++j) if (x[i] & (1LL << j))
			cnt[j]++;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 60; ++j) {
			if (x[i] & (1LL << j)) { 
				add(term2[i], ((1LL << j) % MOD) * n);
			} else if (cnt[j]) add(term2[i], ((1LL << j) % MOD) * cnt[j] % MOD);
		}
	}
	int res = 0;
	for (int j = 1; j <= n; ++j) {
		// cerr << term2[j] << endl;
		int tmp = 0;
		for (int k = 0; k < 60; ++k) {
			if (x[j] & (1LL << k)) add(tmp, ((1LL << k) % MOD) * cnt[k] % MOD);
		}
		mul(tmp, term2[j]);
		add(res, tmp);
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}