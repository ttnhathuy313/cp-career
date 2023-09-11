#include <bits/stdc++.h>

using namespace std;
const int Z = 500 + 5;
int n, m, k, mem[Z][Z];
string a[Z];

int mn(int f, int c);
int f(int i, int j) {
	if (i == 0 && j == 0) return 0;
	if (i == 0 && j != 0) return (int)1e9;
	if (mem[i][j] != -1) return mem[i][j];
	mem[i][j] = (int) 1e9;
	for (int c = 0; c <= j; c++) {
		mem[i][j] = min(f(i - 1, j - c) + mn(i, c), mem[i][j]);
	}
	return mem[i][j];
}

int mn(int f, int c) {
	int minn  = 1000000000;
	vector <int> A;
	for (int i = 0; i <= m; i++) {
		if (a[f][i] == '1') {
			A.push_back(i);
		}
	}
	for (int i = 0; i <= c; i++) {
		int tmp = A[m - i] - A[i] + 1;
		minn = tmp < minn ? tmp : minn;  
	}
	return minn;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("840C.INP", "r", stdin);
	freopen("840C.OUT", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	memset(mem, -1, sizeof mem);
	cout << f(n, k);



	return 0;
}