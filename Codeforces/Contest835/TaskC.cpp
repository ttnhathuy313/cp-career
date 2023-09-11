#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int f[N][N][15], c, n = 100;

int calc(int x1, int y1, int x2, int y2, int k) {
	return f[x1][y1][k] - f[x1][y2 + 1][k] - f[x2 + 1][y1][k] + f[x2 + 1][y2 + 1][k];
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int nn, q, c;
	cin >> nn >> q >> c;
	for (int i = 1; i <= nn; ++i) {
		int x, y, s;
		cin >> x >> y >> s;
		f[x][y][s]++;
	}
	for (int k = 0; k <= c; ++k) {
		for (int i = n; i >= 1; --i) {
			for (int j = n; j >= 1; --j) {
				f[i][j][k] += f[i + 1][j][k] + f[i][j + 1][k] - f[i + 1][j + 1][k];
			}
		}
	}
	while (q--) {
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		t %= (c + 1);
		int res = 0;
		for (int beauty = 1; beauty <= c; ++ beauty) {
			int pre = beauty - t + c + 1;
			pre %= (c + 1);
			res += calc(x1, y1, x2, y2, pre) * beauty;
		}
		cout << res << endl;
	}

	return 0;
}