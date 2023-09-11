#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, MOD = 998244353;
int n, m, l[55], r[55], ll[55], rr[55], mm, dp[55][N], mobius[N];
bitset <N> bs;
vector <int> primes;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= N - 5; ++i) if (bs[i]) {
		for (int j = i * i; j <= N - 5; j += i) bs[j] = false;
		primes.push_back(i);
	}
}

int mob(int x) {
	int PF_idx = 0, PF = primes[0];
	int v = 0;
	while (PF * PF <= x) {
		int cnt = 0;
		while (x % PF == 0) {
			x /= PF;
			cnt++;
		}
		if (cnt > 1) return 0;
		if (cnt > 0) v++;
		PF = primes[++PF_idx];
	}
	if (x > 1) v++;
	if (v & 1) return -1;
	else return 1;
}

void add(int &a, int b) {
	a = (a + b) % MOD;
}

int F(int x) {
	mm = m / x;
	for (int i = 1; i <= n; ++i) {
		ll[i] = (l[i] + x - 1) / x;
		rr[i] = r[i] / x;
	}
	// O(mm * n)
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= mm; ++j) {
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i <= mm; ++i)
		dp[0][i] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= mm; ++j) {
			if (j - ll[i] < 0) continue;
			int le = max(0LL, j - rr[i]), ri = j - ll[i];
			if (le > ri) continue;
			add(dp[i][j], dp[i - 1][ri] - (le == 0 ? 0 : dp[i - 1][le - 1]) + MOD);
		}
		for (int j = 1; j <= mm; ++j) {
			add(dp[i][j], dp[i][j - 1]);
		}
	}
	return dp[n][mm];
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
	}
	sieve();
	for (int i = 1; i <= m; ++i) {
		mobius[i] = mob(i);
	}

	int res = 0;
	for (int i = 1; i <= m; ++i) if (mobius[i] != 0) {
		res = (res + mobius[i] * F(i) + MOD) % MOD;
	}
	cout << res << endl;

	return 0;
}