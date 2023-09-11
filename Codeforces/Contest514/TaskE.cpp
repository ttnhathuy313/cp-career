#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7, N = 1e5 + 5;
int f[N], cnt[N], d[N], n, x;

struct Matrix {
	vector <vector <int> > mat;
	int n, m;
	Matrix() {}
	Matrix(int _n, int _m) {
		this -> n = _n;
		this -> m = _m;
		mat.assign(n + 5, vector <int>(m + 5, 0));
	}
};

Matrix operator * (const Matrix &a, const Matrix &b) {
	int n = a.n, m = a.m, q = b.n;
	Matrix res(n, q);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < q; ++j) {
			for (int k = 0; k < m; ++k) {
				(res.mat[i][j] += 1LL * a.mat[i][k] * b.mat[k][j] % MOD) %= MOD;
			}
		}
	}
	return res;
}

Matrix matrixPow(Matrix &a, int n) {
	Matrix res = a;
	n--;
	while (n) {
		if (n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);

	cin >> n >> x;
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
		cnt[d[i]]++;
	}
	f[0] = 1;
	int s = 1;
	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= i; ++j) {
			(f[i] += 1LL * cnt[j] * f[i - j] % MOD) %= MOD;
		}
		s = (s + f[i]) % MOD;
	}
	if (x <= 100) {
		int res = 0;
		for (int i = 0; i <= x; ++i) res = (res + f[i]) % MOD;
		cout << res << endl;
		return 0;
	}
	Matrix f0(101, 1);
	for (int i = 1; i <= 100; ++i) f0.mat[i - 1][0] = f[i];
	f0.mat[100][0] = s;
	Matrix trans(101, 101);
	for (int i = 1; i <= 100; ++i) {
		trans.mat[99][100 - i] = trans.mat[100][100 - i] = cnt[i];
	}
	trans.mat[100][100] = 1;
	for (int i = 0; i <= 98; ++i) {
		trans.mat[i][i + 1] = 1;
	}
	cout << (matrixPow(trans, x - 100) * f0).mat[100][0] << endl;

	return 0;
}