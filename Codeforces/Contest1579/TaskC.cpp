#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 30;
int mark[N][N], n, m, k;
string grid[N];

bool valid(int i, int j) {
	if (i == 0 || i == n + 1 || j == 0 || j == m + 1 || grid[i][j] == '.') return false;
	else return true;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> k;
		memset(mark, 0, sizeof mark);
		for (int i = 1; i <= n; ++i) {
			cin >> grid[i];
			grid[i] = ' ' + grid[i];
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) if (grid[i][j] == '*') {
				int l_ans = 0, r_ans = 0;
				for (int h = 1; h <= n; ++h) {
					if (l_ans == h - 1 && valid(i - h, j - h))
						l_ans++;
					if (r_ans == h - 1 && valid(i - h, j + h))
						r_ans++;
				}
				if (min(l_ans, r_ans) < k) continue;
				mark[i][j] = 1;
				for (int h = 1; h <= min(l_ans, r_ans); ++h) {
					mark[i - h][j - h] = mark[i - h][j + h] = 1;
				}
			}
		}
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (grid[i][j] == '*' && mark[i][j] == 0)
					ok = false;
			}
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}