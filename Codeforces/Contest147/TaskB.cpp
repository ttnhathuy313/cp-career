#include <bits/stdc++.h>

using namespace std;

const int N = 305, oo = 1e8, LOG = 10;
int n, m, g[N][N];

struct Matrix {
	vector <vector <int>> mat;
	Matrix() {
		mat.assign(n + 5, vector <int>(n + 5, -oo));
		for (int i = 1; i <= n; ++i)
			mat[i][i] = 0;
	}
} F[LOG];

Matrix operator + (const Matrix &a, const Matrix &b) {
	Matrix res;
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				res.mat[i][j] = max(res.mat[i][j], a.mat[i][k] + b.mat[k][j]);
			}
		}
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) g[i][j] = -oo;
	}
	for (int i = 0; i < LOG; ++i)
		F[i] = Matrix();
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		cin >> g[u][v] >> g[v][u];
		F[0].mat[u][v] = g[u][v];
		F[0].mat[v][u] = g[v][u];
	}
	for (int i = 1; i <= 9; ++i)
		F[i] = F[i - 1] + F[i - 1];
	int res = 0;
	Matrix cur;
	for (int i = 9; i >= 0; --i) {
		Matrix tmp = cur + F[i];
		bool f = false;
		for (int j = 1; j <= n; ++j) if (tmp.mat[j][j] > 0) f = true;
		if (!f) {
			if (i == 9) {
				cout << 0 << endl;
				return 0;
			}
			cur = tmp, res += (1 << i);
		}
	}
	cout << res + 1 << endl;
	
	return 0;
};