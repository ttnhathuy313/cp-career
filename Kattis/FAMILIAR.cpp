#include <bits/stdc++.h>

using namespace std;
#define int long long
#define rep(i, a) for (int i = 0; i < a; ++i)
#define forn(i, a, b) for (int i = a; i <= b; ++i)
typedef vector <int> vi;

const int N = 20, MOD = 1e9 + 7, msk = (1 << 10) - 1;
int dp[N][1 << 10][2][2][2], f[N], sos[1 << 10];

int C[N][N];

void updateckn() {
	for (int k = 0; k < N; ++k)
		for (int n = 0; n < N; ++n) {
			if (k == 0 || k == n || n == 0) {
				C[k][n] = 1;
				continue;
			} else {
				C[k][n] = (C[k - 1][n - 1] + C[k][n - 1]) % MOD;
			}
		}
}

vi dig(int a) {
	vi ret; ret.clear();
	while (a) {
		ret.push_back(a % 10);
		a /= 10;
	}
	while (ret.size() < 18)
		ret.push_back(0);
	ret.push_back(0);
	reverse(ret.begin(), ret.end());
	return ret;
}

int modPow(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return ret;
}

void reset() {
	memset(dp, 0, sizeof dp);
	memset(f, 0, sizeof f);
	memset(sos, 0, sizeof sos);
}

void solve() {
	int a, b, k, d;
	cin >> a >> b >> k >> d;
	vi A = dig(a), B = dig(b);
	// number indexed from 1 to 18, dummy at beginning
	reset();
	dp[0][0][0][0][0] = 1;
	int n = 18;
	rep(i, n + 1) rep(mask, (1 << 10)) rep(f1, 2) rep(f2, 2) rep(start, 2) {
		int cur = dp[i][mask][f1][f2][start];
		if (cur == 0) continue;
		// cerr << i << ' ' << mask << ' ' << f1 << ' ' << f2 << ' ' << start << endl;
		if (i == n) {
			(sos[(~mask) & msk] += cur) %= MOD;
			continue;
		}
		int l = (f1 ? 0 : A[i + 1]), r = (f2 ? 9 : B[i + 1]);
		forn(nxt, l, r) {
			int nmask = mask;
			if (nxt == 0 && start) nmask |= 1;
			else if (nxt > 0) nmask |= (1 << nxt);
			(dp[i + 1][nmask][f1 | (nxt > A[i + 1])][f2 | (nxt < B[i + 1])][start | (nxt > 0)] += cur) %= MOD;
		}
	}
	for (int i = 0; i < 10; ++i) {
		for (int mask = 0; mask <= msk; ++mask) if (mask & (1 << i)) {
			(sos[mask] += sos[mask ^ (1 << i)]) %= MOD;
		}
	}
	for (int i = 0; i <= msk; ++i) {
		int cur = sos[i];
		if (cur < k) continue;
		int add = 1;
		for (int i = cur; i > cur - k; --i) add = (add * i) % MOD;
		int fac = 1;
		for (int i = 1; i <= k; ++i) fac = fac * i % MOD;
		add = (add * modPow(fac, MOD - 2)) % MOD;
		(f[10 - __builtin_popcount(i)] += add) %= MOD;
	}
	for (int i = 9; i >= 0; --i) {
		for (int j = i + 1; j <= 10; ++j) {
			f[i] = (f[i] - f[j] * C[i][j] + MOD * MOD) % MOD;
		}
	}
	cout << f[d] << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("FAMILIAR.INP", "r", stdin);
	freopen("FAMILIAR.OUT", "w", stdout);

	updateckn();
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}