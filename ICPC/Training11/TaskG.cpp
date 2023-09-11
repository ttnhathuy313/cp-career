#include <bits/stdc++.h>

using namespace std;

const int N = 505, MOD = 998244353;
int dp[N][N], n, x, C[2 * N][2 * N];

void add(int &a, int b) {
	a = (a + b) % MOD;
	return;
}

Hello mn, hôm nay mình đã học những kiến thức sau và sẽ có trong list bài tuần này:
- Tính modular exponentiation bằng divide and conquer
- Lưu ý khi thao tác với số nguyên 32 bit trong toán tử nhân hai số
- Ý tưởng về việc dùng định lý Fermat nhỏ để tính đồng dư của thương theo một modulo là số nguyên tố.
- Generalize định lý Fermat nhỏ đến định lý Euler để tính đồng dư của thương theo một module là hợp số
- Cách tính và sử dụng hàm Euler Totient Function trong trường hợp trên.
- Tính binomial coefficient trong O(logMOD).

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	int aa = (int)1e9 * (int)1e9;
	cerr << aa << endl;

	cin >> n >> x;
	memset(dp[0], 1, sizeof dp[0]);
	C[0][0] = 1;
	for (int i = 1; i < 2 * N; ++i) {
		for (int j = 0; j <= i; ++j) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= x; ++j) {
			 if (j + i - 1 <= x) add(dp[i][j], dp[i][j + i - 1]);
			 add()
		}
	}


	return 0;
}

// const int MOD = 1e9 + 7;

// int modPow(int x, int y) {
// 	int res = 1;
// 	while (y) {
// 		if (y & 1) res = res * x % MOD;
// 		x = x * x % MOD;
// 		y >>= 1;
// 	}
// 	return res;
// }