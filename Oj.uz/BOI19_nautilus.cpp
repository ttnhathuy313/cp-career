#include <bits/stdc++.h>

using namespace std;

const int N = 505;
int r, c, m, g[N][N];
string s;
bitset <N> dp[N][5005], state[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("BOI19_nautilus.INP", "r", stdin);
	freopen("BOI19_nautilus.OUT", "w", stdout);

	cin >> r >> c >> m;
	for (int i = 1; i <= r; ++i) {
		string t;
		cin >> t;
		for (int j = 1; j <= c; ++j) {
			if (t[j - 1] == '.') g[i][j] = 1;
			else g[i][j] = 0;
		}
	}
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j)
			dp[i][j][0] = g[i][j];
	}
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			state[i][j] = g[i][j];
		}
	}
	for (int i = 1; i <= r; ++i) {
		dp[i][0] = state[i];
		for (int j = 1; j <= m; ++j) dp[i][m].reset();
	}
	for (int k = 1; k <= m; ++k) {
		for (int i = 1; i <= r; ++i) {
			if (s[k] == 'W' || s[k] == '?')
				dp[i][k] |= (dp[i][k - 1] >> 1) & state[i];
			if (s[k] == 'E' || s[k] == '?')
				dp[i][k] |= (dp[i][k - 1] << 1) & state[i];
			if (s[k] == 'N' || s[k] == '?')
				dp[i][k] |= dp[i + 1][k - 1] & state[i];
			if (s[k] == 'S' || s[k] == '?')
				dp[i][k] |= dp[i - 1][k - 1] & state[i];
		}
	}

	int res = 0;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			res += dp[i][m][j];
		}
	}
	cout << res << endl;

	return 0;
}