#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1005, MOD = 1e9 + 7;
int k, pa, pb, dp[N][N];

int modPow(int x, int y) {
	x %= MOD;
	int ret = 1;
	while (y) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return ret;
}

int inv(int x) {
	return modPow(x, MOD - 2);
}

void add(int &a, int b) {
	a = (a + b) % MOD;
}
void mul(int &a, int b) {
	a = a * b % MOD;
}
void sub(int &a, int b) {
	a = (a - b + MOD) % MOD; 
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> k >> pa >> pb;
	int iv = inv(pa + pb);
	dp[0][0] = 1;
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j <= k; ++j) {
			add(dp[i][j], dp[i - 1][j] * pa);
			if (j >= i) add(dp[i][j], dp[i][j - i] * pb);
			//mul(dp[i][j], iv);
		}
	}
	for (int i = k; i >= 1; --i) {
		for(int j = k; j >= 0; --j) {
			if (j >= i) sub(dp[i][j], dp[i][j - i] * pb);
		}
	}
	int iv2 = inv(pb), res = 0;
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j <= k; ++j) if (i + j >= k) {
			int ev = pb * j % MOD;
			add(ev, pa + pb);
			mul(ev, dp[i][j]);
			mul(ev, pa + pb);
			add(res, ev);
		}
	}
	mul(res, inv((pa + pb) * pb));
	cout << res << endl;

	return 0;
}