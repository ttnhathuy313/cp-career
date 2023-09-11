#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int N = 155;
int n, m;

struct Matrix {
	int n, m;
	bitset <N> mat[N];
};

Matrix turn(Matrix u) {
  Matrix res;
  for (int i = 0; i < n; i++ ){
    for (int j = 0 ; j < n; j++) {
      res.mat[i][j] = u.mat[j][i];
    }
  }
  return res;
}

Matrix operator * (const Matrix &a, Matrix b) {
	b = turn(b);
	Matrix res;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			res.mat[i][j] = (a.mat[i] & b.mat[j]).any();
		}
	}
	return res;
}

bitset <N> operator + (const Matrix &a, const bitset <N> v) {
	bitset <N> res; res.reset();
	for (int i = 0; i < n; ++i) {
		res[i] = (a.mat[i] & v).any();
	}
	return res;
}

Matrix matPow(Matrix a, int x)  {
	x--;
	Matrix res = a;
	while (x > 0) {
		if (x & 1) res = res * a;
		a = a * a;
		x >>= 1;
	}
	return res;
}

void showmat(Matrix a) {
	for (int i = 0; i < a.n; ++i) {
		for (int j = 0; j < a.m; ++j) {
			cerr << a.mat[i][j] << ' ';
		}
		cerr << endl;
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	clock_t tStart = clock();
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);

	cin >> n >> m;
	vector <iii> flights;
	for (int i = 1; i <= m; ++i) {
		int a, b, d;
		cin >> a >> b >> d;
		flights.push_back(iii(d, ii(a, b)));
	}
	sort(flights.begin(), flights.end());
	if (flights[0].first != 0) {
		cout << "Impossible" << endl;
		return 0;
	}

	Matrix temp, strict_temp;
	bitset <N> access;
	access[0] = 1;
	for (int i = 0; i < n; ++i) temp.mat[i][i] = 1;

	int cur = 0, pre = -1;
	while (cur < flights.size()) {
		int d = flights[cur].first, a = flights[cur].second.first, b = flights[cur].second.second;
		a--, b--;
		if (d == pre) {
			cur++;
			temp.mat[b][a] = 1;
			strict_temp.mat[b][a] = 1;
			continue;
		}
		bitset <N> tmp = matPow(temp, d - pre) + access;
		if (tmp[n - 1]) break;
		bitset <N> ac = matPow(strict_temp, d - pre) + access;
		if (pre != -1) access = ac;
		pre = d;
		temp.mat[b][a] = 1;
		strict_temp.mat[b][a] = 1;
		cur++;
	}
	int l = 0, r = (int)1e9, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (mid == 0) {
			l = mid + 1;
			continue;
		}
		bitset <N> tmp = matPow(temp, mid) + access;
		if (tmp[n - 1]) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	if (ans == -1) {
		cout << "Impossible" << endl;
		return 0;
	}
	cout << ans + pre << endl;
	fprintf(stderr, "Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

	return 0;
}