#include <bits/stdc++.h>

using namespace std;

const int N = 155, oo = 1e9;
int memo[N][N][N], dp[N][N][3], n, a[N];
string s;

int calc3(int i, int j, int len);

int calc1(int i, int j) { // delete all
	if (dp[i][j][1] != oo) return dp[i][j][1];
	int res = -oo;
	for (int len = 1; len <= j - i + 1; ++len) if (a[len] != -1 && calc3(i, j, len) != -oo) res = max(res, calc3(i, j, len) + a[len]);
	return dp[i][j][1] = res;
}

int calc2(int i, int j) { // best result
	if (dp[i][j][2] != oo) return dp[i][j][2];
	int res = calc1(i, j);
	for (int k = i; k < j; ++k) res = max(res, calc2(i, k) + calc2(k + 1, j));
	res = max(res, 0);
	return dp[i][j][2] = res;
}

int calc3(int i, int j, int len) {
	if (len > j - i + 1) return -oo;
	if (j < i) return 0;
	if (len == 0) return calc1(i, j);
	if (i == j && len == 1) return 0;
	if (memo[i][j][len] != oo) return memo[i][j][len];

	int res = -oo;
	for (int k = j - 1; k >= i; --k) if (calc3(i, k, len) != -oo) res = max(res, calc3(i, k, len) + calc1(k + 1, j));
	for (int k = i; k < j; ++k) if (calc3(k + 1, j, len) != -oo) res = max(res, calc1(i, k) + calc3(k + 1, j, len));
	if (s[i] == s[j] && len >= 2) res = max(res, calc3(i + 1, j - 1, len - 2));
	return memo[i][j][len] = res;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= max(2, n); ++k) {
				memo[i][j][k] = oo;
				if (k <= 2) dp[i][j][k] = oo;
			}
		}
	}

	cout << calc2(1, n) << endl;

	return 0;
}