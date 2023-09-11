#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e3 + 5;
int n, b[N], dp[N * 12], c[N], moves[N], k;

void init() {
	for (int i = 2; i < N; ++i)
		moves[i] = N;
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++j) if (i + i / j < N) {
			moves[i + i / j] = min(moves[i + i / j], moves[i] + 1);
		}
	}
}

void solve() {
	cin >> n >> k;
	int mxMoves = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		mxMoves += moves[b[i]];
	}
	cerr << endl;
	k = min(k, mxMoves);

	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= k; ++i) {
		dp[i] = -(int)1e18;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = k; j >= 0; j--) {
			if (j >= moves[b[i]]) {
				dp[j] = max(dp[j], dp[j - moves[b[i]]] + c[i]);
				res = max(res, dp[j]);
			}
		}
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	init();
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}