#include <bits/stdc++.h>

using namespace std;

const int N = 505, LOG = 9;
int n, m, a[N][N], q, ddd[300], f[N][N][5], cons[N][N][2], g[N][N], sparse[N * 2][N * 2][10][10], lg[N];

int get(int r1, int c1, int r2, int c2) {
	int lenx = r2 - r1 + 1, leny = c2 - c1 + 1;
	int kx = lg[lenx], ky = lg[leny];
	int m1 = max(sparse[r1][c1][kx][ky], sparse[r1][c2 - (1 << ky) + 1][kx][ky]);
	int m2 = max(sparse[r2 - (1 << kx) + 1][c2 - (1 << ky) + 1][kx][ky], sparse[r2 - (1 << kx) + 1][c1][kx][ky]);
	return max(m1, m2);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	ddd['G'] = 2; ddd['R'] = 1; ddd['Y'] = 3; ddd['B'] = 4;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		s = ' ' + s;
		for (int j = 1; j <= m; ++j) {
			a[i][j] = ddd[s[j]];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cons[i][j][0] = (a[i][j] == a[i - 1][j] ? cons[i - 1][j][0] + 1 : 1);
			cons[i][j][1] = (a[i][j] == a[i][j - 1] ? cons[i][j - 1][1] + 1 : 1);
			// cerr << "left consecutive at " << i << ", " << j << " is " << cons[i][j][1] << endl;
			int cur = min(cons[i][j][0], cons[i][j][1]);
			f[i][j][1] = min(cur, f[i - 1][j - 1][1] + 1);
			// cerr << "up left subrectangle at " << i << ", " << j << " is " << f[i][j][1] << endl;
		}
	}
	memset(cons, 0, sizeof cons);
	for (int i = 1; i <= n; ++i) {
		for (int j = m; j >= 1; --j) {
			cons[i][j][0] = (a[i][j] == a[i - 1][j] ? cons[i - 1][j][0] + 1 : 1);
			cons[i][j][1] = (a[i][j] == a[i][j + 1] ? cons[i][j + 1][1] + 1 : 1);
			int cur = min(cons[i][j][0], cons[i][j][1]);
			f[i][j][2] = min(cur, f[i - 1][j + 1][2] + 1);
			// cerr << "up right subrectangle at " << i << ", " << j << " is " << f[i][j][2] << endl;
		}
	}
	memset(cons, 0, sizeof cons);
	for (int i = n; i >= 1; --i) {
		for (int j = 1; j <= m; ++j) {
			cons[i][j][0] = (a[i][j] == a[i + 1][j] ? cons[i + 1][j][0] + 1 : 1);
			cons[i][j][1] = (a[i][j] == a[i][j - 1] ? cons[i][j - 1][1] + 1 : 1);
			int cur = min(cons[i][j][0], cons[i][j][1]);
			f[i][j][3] = min(cur, f[i + 1][j - 1][3] + 1);
		}
	}
	memset(cons, 0, sizeof cons);
	for (int i = n; i >= 1; --i) {
		for (int j = m; j >= 1; --j) {
			cons[i][j][0] = (a[i][j] == a[i + 1][j] ? cons[i + 1][j][0] + 1 : 1);
			cons[i][j][1] = (a[i][j] == a[i][j + 1] ? cons[i][j + 1][1] + 1 : 1);
			int cur = min(cons[i][j][0], cons[i][j][1]);
			f[i][j][4] = min(cur, f[i + 1][j + 1][4] + 1);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] != 1 || a[i][j + 1] != 2 || a[i + 1][j] != 3 || a[i + 1][j + 1] != 4) continue;
			g[i][j] = min(f[i][j][1], f[i][j + 1][2]);
			g[i][j] = min(g[i][j], min(f[i + 1][j][3], f[i + 1][j + 1][4]));
			// cerr << "Answer at " << i << ", " << j << " is : " << g[i][j] << endl;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			sparse[i][j][0][0] = g[i][j];
		}
		for (int lj = 1; lj <= LOG; ++lj) {
			for (int j = 1; j - 1 + (1 << lj) <= m; ++j) {
				sparse[i][j][0][lj] = max(sparse[i][j][0][lj - 1], sparse[i][j + (1 << (lj - 1))][0][lj - 1]);
			}
		}
	}
	for (int i = 1; i <= 500; ++i) lg[i] = (int)log2(i);
	for (int li = 1; li <= lg[n]; ++li) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				for (int lj = 0; lj <= lg[m]; ++lj) {
					sparse[i][j][li][lj] = max(sparse[i][j][li - 1][lj], sparse[i + (1 << (li - 1))][j][li - 1][lj]);
				}
			}
		}
	}
	while (q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int l = 1, r = m, ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			int x1 = r1 + mid - 1, x2 = r2 - mid, y1 = c1 + mid - 1, y2 = c2 - mid;
			bool check;
			if (x1 > x2 || y2 < y1) check = false; else check = (get(x1, y1, x2, y2) >= mid);
			// cerr << mid << "		" << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;			
			if (check) l = mid + 1, ans = mid;
			else r = mid - 1;
		}
		cout << 4 * ans * ans << endl;
	}

	return 0;
}