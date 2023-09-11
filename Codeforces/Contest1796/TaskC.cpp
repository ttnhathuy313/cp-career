#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 6, MOD = 998244353;
int pref[N], lst[N], fac[500];

bitset <N + 7> bs;

void sieve() {
	bs.set();
	bs[0] = 0;
	bs[1] = 0;
	for (int i = 2; i < N; ++i) if (bs[i]) {
		lst[i] = i;
		for (long long j = i * i; j < N; j += i) {
			bs[i] = 0;
			lst[j] = i;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	sieve();

	fac[0] = 1;
	for (int i = 1; i < 50; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
	}

	for (int i = 1; i <= N - 6; ++i) {
		map <int, int> cnt;
		cnt.clear();
		int x = i, dem = 0;
		while (x > 1) {
			dem++;
			cnt[lst[x]]++;
			x = x / lst[x];
		}

		pref[i] = fac[dem];
		for (auto d : cnt) {
			pref[i] = pref[i] / fac[d.second];
		}
	}


	for (int i = 1; i <= N - 6; ++i) {
		(pref[i] += pref[i - 1]) %= MOD;
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int l, r;
		cin >> l >> r;
		cout << (int)log2(r / l) + 1 << ' ';
		int L = 1 << ((int)log2(r / l)), R = r / l;
		int all2 = r / L - l + 1;
		int one3 = 0;
		if (L / 2 * 3 != 0) {
			one3 = max(0LL, r / (L / 2 * 3) - l + 1);
		}
		one3 = one3 * (int)log2(r / l) % MOD;
		cout << (all2 + one3) % MOD << endl;
	}

	return 0;
}