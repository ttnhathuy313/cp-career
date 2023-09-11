#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int dp[N][2][3], n;
string s;

void update(int &a, int b) {
	a = max(a, b);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n;
	cin >> s;
	int res = 0;
	s = ' ' + s;
	for (int i = 1; i <= n; ++i) {
		for (int take = 0; take < 2; ++take) {
			if (take == s[i] - '0') update(dp[i][take][0], dp[i - 1][take ^ 1][0] + 1);
			update(dp[i][take][0], dp[i - 1][take][0]);
			if (s[i] - '0' == (take ^ 1)) {
				update(dp[i][take][1], dp[i - 1][take ^ 1][0] + 1);
				update(dp[i][take][1], dp[i - 1][take ^ 1][1] + 1); 
			}
			update(dp[i][take][1], dp[i - 1][take][1]);
			if (s[i] - '0' == take) {
				update(dp[i][take][2], dp[i - 1][take ^ 1][2] + 1);
				update(dp[i][take][2], dp[i - 1][take ^ 1][1] + 1);
			}
			update(dp[i][take][2], dp[i - 1][take][2]);
			for (int phase = 0; phase < 3; ++phase) if (i == n) res = max(res, dp[i][take][phase]);
		}
	}
	cout << res << endl;

	return 0;
}