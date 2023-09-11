#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
int f[N][N], g[N][N], n, a[N], cnt[N][3];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[i][1] = cnt[i - 1][1] + (a[i] == 1);
		cnt[i][2] = cnt[i - 1][2] + (a[i] == 2);
	}
	for (int i = 1; i <= n; ++i) {
		int lst1 = -1, lst2 = -1;
		f[i][i] = 1;
		if (a[i] == 1) lst1 = i; else lst2 = i;
		for (int j = i + 1; j <= n; ++j) {
			if (a[j] == 1) {
				f[i][j] = 1;
				if (~lst1) f[i][j] = max(f[i][j], f[i][lst1] + 1);
				lst1 = j;
			} else {
				f[i][j] = 1;
				if (~lst2) f[i][j] = max(f[i][j], f[i][lst2] + 1);
				if (~lst1) f[i][j] = max(f[i][j], f[i][lst1] + 1);
				lst2 = j;
			}
		}
		for (int j = i + 1; j <= n; ++j) {
			f[i][j] = max(f[i][j], f[i][j - 1]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		int lst1 = -1, lst2 = -1;
		g[i][i] = 1;
		if (a[i] == 1) lst1 = i; else lst2 = i;
		for (int j = i - 1; j >= 1; --j) {
			if (a[j] == 1) {
				g[i][j] = 1;
				if (~lst1) g[i][j] = max(g[i][j], g[i][lst1] + 1);
				lst1 = j;
			} else {
				g[i][j] = 1;
				if (~lst2) g[i][j] = max(g[i][j], g[i][lst2] + 1);
				if (~lst1) g[i][j] = max(g[i][j], g[i][lst1] + 1);
				lst2 = j;
			}
		}
		for (int j = i - 1; j >= 1; --j) {
			g[i][j] = max(g[i][j], g[i][j + 1]);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			int cur = f[1][j - 1] + cnt[n][2] - cnt[j - 1][2];
			cur = max(cur, cnt[j - 1][1] + g[i][j] + cnt[n][2] - cnt[i][2]);
			cur = max(cur, cnt[i][1] + f[i + 1][n]);
			res = max(res, cur);
			// if (j == 3 && i == 7) cerr << cur << endl;
		}
	}
	cout << res << endl;

	return 0;
}