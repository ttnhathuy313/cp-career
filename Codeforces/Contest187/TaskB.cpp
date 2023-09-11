#include <bits/stdc++.h>

using namespace std;

const int N = 65, oo = 1e9;
int n, m, r, f[N][N][N], g[N][N], ans[(int)1e5 + 7], dp[N][N], temp[N][N];

struct Query {
	int l, r, id, k;
};
vector <Query> q[1005];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			g[i][j] = oo;
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				cin >> f[i][j][k];				
			}
		}
		for (int mid = 1; mid <= n; ++mid) {
			for (int j = 1; j <= n; ++j) {
				for (int k = 1; k <= n; ++k) {
					f[i][j][k] = min(f[i][j][k], f[i][j][mid] + f[i][mid][k]);
				}
			}
		}
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				g[j][k] = min(g[j][k], f[i][j][k]);
			}
		}
	}
	for (int i = 1; i <= r; ++i) {
		Query qr;
		cin >> qr.l >> qr.r >> qr.k;
		qr.id = i;
		q[qr.k].push_back(qr);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) dp[i][j] = g[i][j];
	}
	for (Query qr : q[0]) {
		ans[qr.id] = g[qr.l][qr.r];
	}
	for (int turn = 1; turn <= 1000; ++turn) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)
				temp[i][j] = dp[i][j];
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int k = 1; k <= n; ++k) {
					temp[i][j] = min(temp[i][j], dp[i][k] + g[k][j]);
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)
				dp[i][j] = temp[i][j];
		}
		for (Query qr : q[turn]) {
			ans[qr.id] = dp[qr.l][qr.r];
		}
	}
	for (int i = 1; i <= r; ++i) {
		cout << ans[i] << endl;
	}

	return 0;
}