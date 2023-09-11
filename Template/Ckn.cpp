const int N = 1e5, MOD = 1e9 + 7;

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