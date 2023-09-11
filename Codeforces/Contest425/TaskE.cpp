#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 505, MOD = 1e9 + 7;
int dp[2][N][N], shl[N], n, k;

int mult(int a, int b) {
	return 1LL * a * b % MOD;
}

void add(int &a, int b) {
	a = (a + b) % MOD;
}

signed main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> k;
	shl[0] = 1;
	for (int i = 1; i <= n; ++i) {
		shl[i] = shl[i - 1];
		shl[i] = mult(shl[i], 2);
	}
	int res = 0;
	dp[0][0][0] = 1;
	for (int i = 0; i <= n; ++i) {
		int id = i & 1, nxt = id ^ 1;
		for (int last = 0; last <= i; ++last) {
			for (int j = 0; j <= min(i, k); ++j) {
				int trans = shl[last];
				add(dp[nxt][last][j], mult(dp[id][last][j], trans));
				int trans2 = mult(trans, shl[i + 1 - last] - 1 + MOD);
				add(dp[nxt][i + 1][j + 1], mult(dp[id][last][j], trans2));
				if (i == n && j == k) add(res, dp[id][last][j]);
			}
		}
		for (int j = 0; j <= n; ++j)
			for (int z = 0; z <= k; ++z)
				dp[id][j][z] = 0;
	}	
	cout << res << endl;

	return 0;
}
