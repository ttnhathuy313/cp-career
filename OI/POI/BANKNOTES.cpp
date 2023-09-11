#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 205, M = 2e4 + 5, oo = 1e18;
int n, b[N], c[N], k, dp[M], ans[N];
int trace[N][M];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("BANKNOTES.INP", "r", stdin);
	freopen("BANKNOTES.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	cin >> k;
	for (int i = 1; i <= k; ++i)
		dp[i] = oo;
	for (int i = 1; i <= n; ++i) {
		int w = b[i], sl = c[i];
		vector <deque <ii>> dq;
		dq.resize(w);
		for (int j = 0; j < w; ++j) dq[j].clear();
		for (int j = 0; j <= k; ++j) {
			while (!dq[j % w].empty() && dq[j % w].front().first < j - sl * w)
				dq[j % w].pop_front();
			int v = dp[j] - j / w;
			if (dq[j % w].size()) {
				if (dq[j % w].front().second + j / w < dp[j]) {
					dp[j] = dq[j % w].front().second + j / w;
					trace[i][j] = (j - dq[j % w].front().first) / w;
				}
			}
			while (!dq[j % w].empty() && dq[j % w].back().second >= v)
				dq[j % w].pop_back();
			dq[j % w].push_back({j, v});
		}
	}
	cout << dp[k] << endl;
	int i = n;
	while (k) {
		int u = trace[i][k];
		ans[i] += u;
		k -= b[i] * u;
		i--;
	}
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';

	return 0;
}