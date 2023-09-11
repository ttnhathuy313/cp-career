#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;

struct Matrix {
	int n, m;
	vector <vector <int>> mat;
	Matrix() {}
	Matrix(int _n, int _m) {
		this -> n = _n;
		this -> m = _m;
		mat.assign(n, vector <int>(m, 0));
	}
} identity;

Matrix operator * (const Matrix a, const Matrix b) {
	int n = a.n, m = a.m, q = b.m;
	Matrix res(n, q);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < q; ++j) {
			for (int k = 0; k < m; ++k) {
				res.mat[i][j] += a.mat[i][k] * b.mat[k][j] % MOD;
				res.mat[i][j] %= MOD;
			}
		}
	}
	return res;
}

Matrix MatExp(Matrix a, int n) {
	Matrix res = identity;
	while (n) {
		if (n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

const int N = 105;
int n, k, a[N], b[N], c[N];

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}
	identity = Matrix(16, 16);
	for (int i = 0; i <= 15; ++i) identity.mat[i][i] = 1;
	Matrix Y(16, 1);
	Y.mat[0][0] = 1ll;
	for (int i = 1; i <= n; ++i) {
		Matrix trans(16, 16);
		for (int j = 0; j <= c[i]; ++j) {
			for (int k = 0; k <= c[i]; ++k) if (abs(j - k) <= 1) trans.mat[j][k] = 1;
		}
		Y = Y * MatExp(trans, min(b[i], k) - a[i]);
	}
	cout << Y.mat[0][0] << endl;

	return 0;
}