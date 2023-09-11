#include <bits/stdc++.h>

using namespace std;

const int N = 85, M = 1e5 + 5;
int dp[N][M], n, m;

struct antenna {
	int in, mid, out;
} a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int x, s;
		cin >> x >> s;
		a[i].mid = x;
		a[i].in = max(1, x - s);
		a[i].out = min(m, x + s);
	}
	sort(a + 1, a + 1 + n, [](antenna a, antenna b) {
		return (a.in < b.in || (a.in == b.in && a.out > b.out));
	});
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) dp[i][j] = M;
	}
	dp[0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) if (dp[i][j] <= M) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			if (i && j) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
			if (a[i + 1].in - 1 <= j) {
				dp[i + 1][a[i + 1].out] = min(dp[i + 1][a[i + 1].out], dp[i][j]);
			} else {
				int add = a[i + 1].in - j - 1;
				int bound = min(m, a[i + 1].out + add);
				dp[i + 1][bound] = min(dp[i + 1][bound], dp[i][j] + add);
			}
		}
	}
	cout << dp[n][m] << endl;

	return 0;
}