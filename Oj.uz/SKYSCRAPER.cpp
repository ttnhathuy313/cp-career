#include <bits/stdc++.h>

using namespace std;

const int N = 105, L = 1005, MOD = 1e9 + 7;
int dp[N][L][2][N][2], a[N], n, maxCost;

void add(int &a, int b) {
	a = (a + b) % MOD;
	return;
}

int calc(int pos, int curCost, int l, int k, int r) {
	int nxtCost = curCost;
	if (pos > 1)
		nxtCost += (l + (k << 1) + r) * abs(a[pos] - a[pos - 1]);
	if (nxtCost > maxCost) return 0;
	if (k < 0) return 0;
	if (pos == n)
		return (k == 0 ? 1 : 0);
	if (~dp[pos][curCost][l][k][r]) return dp[pos][curCost][l][k][r];
	int ret = 0;
	add(ret, calc(pos + 1, nxtCost, 1, k, r));
	add(ret, 1LL * calc(pos + 1, nxtCost, 1, k - 1, r) * k % MOD);
	add(ret, calc(pos + 1, nxtCost, l, k, 1));
	add(ret, 1LL * calc(pos + 1, nxtCost, l, k - 1, 1) * k % MOD);
	add(ret, calc(pos + 1, nxtCost, l, k + 1, r));
	add(ret, 1LL * calc(pos + 1, nxtCost, l, k - 1, r) * k * (k - 1) % MOD);
	add(ret, 1LL * calc(pos + 1, nxtCost, l, k, r) * k * 2 % MOD);
	ret %= MOD;
	return dp[pos][curCost][l][k][r] = ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("SKYSCRAPER.INP", "r", stdin);
	freopen("SKYSCRAPER.OUT", "w", stdout);

	memset(dp, -1, sizeof dp);
	cin >> n >> maxCost;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	cout << calc(1, 0, 0, 0, 0) << endl;

	return 0;
}