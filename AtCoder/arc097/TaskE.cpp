#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 4005;
int a[N], b[N], n1, n2, n, r_idx[N][2], dp[N][N], f[N][N], g[N][N];
vector <int> ind[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= 2 * n; ++i) {
		char type; int x;
		cin >> type >> x;
		if (type == 'W') a[++n1] = x, r_idx[n1][0] = i;
		else b[++n2] = x, r_idx[n2][1] = i;
	}
	vector <ii> A(n + 5, {0, 0}), B(n + 5, {0, 0});
	A[0] = {N, N}; for (int i = n + 1; i <= n + 4; ++i) A[i] = {N, N};
	for (int i = 1; i <= n; ++i) {
		f[a[i]][r_idx[i][0]] = 1;
		A[i] = {a[i], r_idx[i][0]};
	}
	sort(A.begin() + 1, A.end());
	B[0] = {N, N}; for (int i = n + 1; i <= n + 4; ++i) B[i] = {N, N};
	for (int i = 1; i <= n; ++i) {
		g[b[i]][r_idx[i][1]] = 1;
		B[i] = {b[i], r_idx[i][1]};
	}
	sort(B.begin() + 1, B.end());
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 2 * n; ++j) {
			f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
			g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j)
			dp[i][j] = N * N;
	}
	dp[0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i + j == 0) continue;
			int ind1 = A[i].second, aa = A[i].first, ind2 = B[j].second, bb = B[j].first;
			int cost_a, cost_b; cost_a = cost_b = N;
			if (i != 0) cost_a = (i - 1 - f[i - 1][ind1]) + (j - g[j][ind1]);
			if (j != 0) cost_b = (i - f[i][ind2]) + (j - 1 - g[j - 1][ind2]);
			if (i != 0) dp[i][j] = dp[i - 1][j] + cost_a;
			if (j != 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + cost_b);
			// cerr << "dp[" << i << "][" << j << "] : " << dp[i][j] << endl;
		}
	}
	cout << dp[n][n] << endl;
	return 0;
}