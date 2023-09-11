#include <bits/stdc++.h>

using namespace std;

const int N = 10, MSK = 1048576;
int a[N][N], n, m, b[MSK][N];
short memo[N][N][MSK];

int val(string t) {
	int ret = 0;
	for (int i = 0; i < t.size(); ++i) ret += (t[i] - '0') * (1 << (2 * i));
	return ret;
}

int calc(int i, int j, int mask) {
	if (i == n) return 0;
	if (~memo[i][j][mask]) return memo[i][j][mask];
	int ret = 0;
	if (a[i][j] == 1 || a[i][j] == 0) {
		int type;
		if (b[mask][0] == 0 && (b[mask][m - 1] == 0 && j)) type = 3;
		else if (b[mask][0] == 0 || (b[mask][m - 1] == 0 && j)) type = 2;
		else type = 1;
		if (j == m - 1) ret = max(ret, calc(i + 1, 0, (mask >> 2) + type * (1 << (2 * m - 2))));
		else ret = max(ret, calc(i, j + 1, (mask >> 2) + type * (1 << (2 * (m - 1)))));
	}
	if (a[i][j] == 2 || a[i][j] == 0) {
		int add = 0, type = 1;
		if (b[mask][0] == 2) add++;
		else if (b[mask][0] == 3) add += 2;
		if (b[mask][m - 1] == 2 && j) add++;
		else if (b[mask][m - 1] == 3 && j) add += 2;
		if (j == m - 1) ret = max(ret, calc(i + 1, 0, (mask >> 2) + type * (1 << (2 * (m - 1)))) + add);
		else ret = max(ret, calc(i, j + 1, (mask >> 2) + type * (1 << (2 * (m - 1)))) + add);
	}
	if (a[i][j] == 0) {
		int type = 0;
		if (j == m - 1) ret = max(ret, calc(i + 1, 0, (mask >> 2) + type * (1 << (2 * (m - 1)))));
		else ret = max(ret, calc(i, j + 1, (mask >> 2) + type * (1 << (2 * (m - 1)))));
	}
	return memo[i][j][mask] = (short)ret;
}

class EllysFlags {
	public :
	int getMax(vector <string> paper) {
		n = paper.size(), m = paper[0].size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (paper[i][j] == 'W') a[i][j] = 0;
				else if (paper[i][j] == 'G') a[i][j] = 1;
				else a[i][j] = 2;
			}
		}
		int start = 0;
		for (int i = 0; i < m; ++i)
			start += 1 << (2 * i);
		for (int i = 0; i < (1 << (2 * m)); ++i) {
			int cur = i;
			for (int j = 0; j < m; ++j) {
				b[i][j] = cur % 4;
				cur /= 4;
			}
		}
		memset(memo, -1, sizeof memo);
		return (int)calc(0, 0, start);
	}
};


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("ELLYSFLAGS.INP", "r", stdin);
	freopen("ELLYSFLAGS.OUT", "w", stdout);

	EllysFlags sol;
	cerr << sol.getMax({"WWWWWWW", "WWWWWWW", "WWWWWWW", "WWWWWWW", "WWWWWWW", "WWWWWWW", "WWWWWWW", "WWWWWWW"}) << endl;

	return 0;
}