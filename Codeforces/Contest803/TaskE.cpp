#include <bits/stdc++.h>

using namespace std;

const int N = 1005, offset = N - 5;
int n, k, trace[N][2 * N], p[N], ans[N];
bool dp[N][2 * N];
string s;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> k >> s;
	s = ' ' + s;
	dp[0][offset] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = -k + 1 - (i == n ? 1 : 0); j <= k - 1 + (i == n ? 1 : 0); ++j) {
			if (dp[i - 1][j + offset] && (s[i] == 'D' || s[i] == '?')) {
				dp[i][j + offset] = 1;
				trace[i][j + offset] = j + offset;
			}
			if (s[i] == 'W' || s[i] == '?') {
				dp[i][j + offset] |= dp[i - 1][j + offset - 1];
				if (dp[i - 1][j + offset - 1]) trace[i][j + offset] = j + offset - 1;
			}
			if (s[i] == 'L' || s[i] == '?') {
				dp[i][j + offset] |= dp[i - 1][j + offset + 1];
				if (dp[i - 1][j + offset + 1]) trace[i][j + offset] = j + offset + 1;
			}
		}
	}
	if (!dp[n][-k + offset] && !dp[n][k + offset]) {
		cout << "NO" << endl;
		return 0;
	}
	if (dp[n][-k+offset]) {
		int cur = -k + offset;
		for (int i = n; i >= 1; --i) {
			p[i] = cur - trace[i][cur];
			cur = trace[i][cur];
		}
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			if (p[i] == 0) cout << "D";
			else if (p[i] == 1) cout << "W";
			else if (p[i] == -1) cout << "L";
			res += p[i];
			// cerr << res << endl;
		}
		return 0;
	}
	if (dp[n][k+offset]) {
		vector <int> res;
		res.clear();
		int cur = k + offset;
		for (int i = n; i >= 1; --i) {
			p[i] = cur - trace[i][cur];
			cur = trace[i][cur];
		}
		for (int i = 1; i <= n; ++i) {
			if (p[i] == 0) cout << "D";
			else if (p[i] == 1) cout << "W";
			else if (p[i] == -1) cout << "L";
		}
		return 0;
	}

	return 0;
}