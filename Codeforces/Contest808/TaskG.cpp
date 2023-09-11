#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.inp", "r", stdin);
	freopen("TaskG.out", "w", stdout);

	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	if (m > n) {
		cout << 0 << endl;
		return 0;
	}
	s = ' ' + s; t = ' ' + t;
	vector <vector <int> > dp;
	dp.assign(n + 5, vector <int> (m + 5, -1));
	vector <vector <int> > Next;
	vector <int> pi;
	pi.assign(m + 5, 0);
	Next.assign(m + 5, vector <int>(30, 0));
	pi[1] = 0;
	for (int i = 2; i <= m; ++i) {
		int j = pi[i - 1];
		while (1) {
			if (t[j + 1] == t[i]) {
				pi[i] = j + 1;
				break;
			}
			if (j == 0) break;
			j = pi[j];
		}
	}
	for (int i = 0; i <= m; ++i) {
		for (int NextChar = 0; NextChar <= 'z' - 'a'; ++NextChar) {
			int j = i;
			if (j == m) j = pi[j];
			while (1) {
				if (j != m && t[j + 1] - 'a' == NextChar) {
					Next[i][NextChar] = j + 1;
					break;
				}
				if (j == 0) break;
				j = pi[j];
			}
		}
	}
	dp[0][0] = 0;
	int res = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (dp[i][j] == -1) continue;
			if (j == m) dp[i][j]++;
			if (i == n) {
				res = max(res, dp[i][j]);
				continue;
			}
			//cerr << "dp[" << i << "][" << j << "] : " << dp[i][j] << endl;
			if (s[i + 1] == '?') {
				for (int k = 0; k <= 'z' - 'a'; ++k) {
 					dp[i + 1][Next[j][k]] = max(dp[i][j], dp[i + 1][Next[j][k]]);
				}
			} else dp[i + 1][Next[j][s[i + 1] - 'a']] = max(dp[i][j], dp[i + 1][Next[j][s[i + 1] - 'a']]);
		}
	}
	cout << res << endl;

	return 0;
}