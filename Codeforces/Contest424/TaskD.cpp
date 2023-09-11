#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
#define all(a) a.begin(), a.end()

const int N = 305, oo = 1e9;
int Right[N][N], Left[N][N], Up[N][N], Down[N][N], a[N][N], n, res = oo, m, lazy[N];
int up, down, flat, t;
ii res1, res2;

int go(int a, int b) {
	if (a < b) return up;
	if (a > b) return down;
	if (a == b) return flat;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);

	cin >> n >> m >> t >> flat >> up >> down;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (j != 1) Right[i][j] = Right[i][j - 1] + go(a[i][j - 1], a[i][j]);
			if (j != 1) Left[i][j] = Left[i][j - 1] + go(a[i][j], a[i][j - 1]);
			if (i == 1) continue;
			Up[i][j] = Up[i - 1][j] + go(a[i][j], a[i - 1][j]);
			Down[i][j] = Down[i - 1][j] + go(a[i - 1][j], a[i][j]);
		}
	}
	for (int c1 = 1; c1 <= m; ++c1) {
		for (int c2 = c1 + 1; c2 <= m; ++c2) if (c2 - c1 > 1) {
			int cur1, cur2;
			cur1 = cur2 = 0;
			set <ii> S;
			S.clear();
			lazy[1] = Right[1][c2] - Right[1][c1];
			for (int i = 2; i <= n; ++i) {
				cur1 = Up[i][c1], cur2 = Down[i][c2];

				int now = Left[i][c2] - Left[i][c1];
				int nxt = Right[i][c2] - Right[i][c1];
				set <ii>::iterator it = S.lower_bound(ii(t - cur1 - cur2 - now, 0)); // fuck, wrong usage of std::lower_bound, it should be std::set::lower_bound
				if (it != S.end()) {
					int val = (*it).first; int id = (*it).second;
					res = min(res, cur1 + cur2 + val + now - t);
					if (res == cur1 + cur2 + val + now - t) {
						if (res == 0) {
							cout << id << ' ' << c1 << ' ' << i << ' ' << c2 << endl;
							return 0;
						}
						res1 = ii(id, c1); res2 = ii(i, c2);
					}
				}
				if (it != S.begin()) {
					it--;
					int val = (*it).first; int id = (*it).second;
					res = min(res, abs(cur1 + cur2 + val + now - t));
					if (res == abs(cur1 + cur2 + val + now - t)) {
						if (res == 0) {
							cout << id << ' ' << c1 << ' ' << i << ' ' << c2 << endl;
							return 0;
						}
						res1 = ii(id, c1); res2 = ii(i, c2);
					}
				}
				lazy[i] = nxt - cur1 - cur2;
				S.insert(ii(lazy[i - 1], i - 1));
			}
		}
	}
	cout << res1.first << ' ' << res1.second << ' ' << res2.first << ' ' << res2.second << endl;

	return 0;
}