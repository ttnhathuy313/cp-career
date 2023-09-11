#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2025, M = 1e6 + 6, MOD = 998244353;
int n, a[2 * N], m, b[N * 2], cnt[M], dp[N * 2][N], fac[2 * N], invfac[N * 2];
bitset <M> bs;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= 1e6; ++i) {
		for (long long j = i * i; j <= 1e6; j += i) {
			bs[j] = 0;
		}
	}
}

int modPow(int x, int y) {
	x %= MOD;
	int res = 1;
	while (y) {
		if (y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

int inv(int x) {
	return modPow(x, MOD - 2);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	sieve();
	cin >> n;
	fac[0] = 1;
	for (int i = 1; i <= 2 * n; ++i) {
		cin >> a[i];
		fac[i] = fac[i - 1] * i % MOD;
		invfac[i] = inv(fac[i]);
		cnt[a[i]]++;
	}
	invfac[0] = inv(1);
	sort(a + 1, a + 1 + 2 * n);
	for (int i = 1; i <= 2 * n; ++i) {
		if (a[i] != a[i - 1]) {
			b[++m] = a[i];
		}
	}
	dp[0][0] = fac[n];
	for (int i = 0; i <= m - 1; ++i) {
		for (int j = 0; j <= min(i, n); ++j) {
			int cur = dp[i][j];
			dp[i + 1][j] += (cur * invfac[cnt[b[i + 1]]] % MOD);
			dp[i + 1][j] %= MOD;
			if (bs[b[i + 1]]) {
				dp[i + 1][j + 1] += (cur * invfac[cnt[b[i + 1]] - 1] % MOD);
				dp[i + 1][j + 1] %= MOD;
			}
		}
	}
	vector <int> num = {2, 3, 5, 7};
	int ans = 0;
	for (int mask = 1; mask < (1 << 4); ++mask) {
		int prod = 1, cnt = 0;
		string pp = "";
		for (int i = 0; i < 4; ++i) if (mask & (1 << i)) {
			prod = prod * num[i] * num[i];
			cnt++;
			pp = pp + to_string(num[i]) + "^2";
			if (cnt != __builtin_popcount(mask)) {
				pp = pp + " \\cdot";
			}
		}
		if (cnt & 1) {
			ans = ans + 100 / prod;
		} else ans = ans - 100 / prod;
		if (cnt == 4) {
			cerr << " + " << "\\left|\\lfloor\\frac{100}{" + pp + "}\\right\\rfloor";
		}
	}
	cerr << ans << endl;

	ans = fac[9] * fac[4] + fac[3] * fac[10] + fac[5] * fac[8] - fac[4] * fac[3] * fac[7] - fac[4] * fac[5] * fac[5] - fac[3] * fac[5] * fac[6] + fac[4] * fac[3] * fac[5] * fac[3];
	cerr << fac[12] -  ans << endl;

	int res = dp[m][n];
	cout << res << endl;


	return 0;
}