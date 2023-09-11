#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int n, dp[N][N];
string s;

int calc(int i, int j) {
	if (i > j) return 0;
	if (i == j) return 1;
	if (i == j - 1) {
		if (s[i] == s[j]) return 1;
		else return 2;
	}
	if (~dp[i][j]) return dp[i][j];
	int ret = (int)1e9;
	ret = min(ret, calc(i + 1, j) + 1);
	for (int k = i + 1; k <= j; ++k) if (s[k] == s[i]) {
		ret = min(ret, calc(i + 1, k - 1) + calc(k, j));
	}
	return dp[i][j] = ret;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("xamlon.INP", "r", stdin);
	freopen("xamlon.OUT", "w", stdout);

	cin >> n;
	cin >> s;
	n = s.size();
	s = ' ' + s;
	memset(dp, -1, sizeof dp);
	cout << calc(1, n) << endl;

	return 0;
}