#include <bits/stdc++.h>

using namespace std;
#define int long long

int dp[25][99], digit[25];

int f(int i, int cnt) {
	if (cnt > 3) return 0;
	if (i == 0) return 1;
	if (~dp[i][cnt]) return dp[i][cnt];
	int ret = f(i - 1, cnt);
	for (int j = 1; j <= 9; ++j) {
		ret += f(i - 1, cnt + 1);
	}
	return dp[i][cnt] = ret;
}

int solve(int d) {
	memset(digit, 0, sizeof digit);
	if (d == 0) return 1;
	int tmp = d, dem = 0;
	while (tmp) {
		digit[++dem] = tmp % 10;
		tmp /= 10;
	}
	int ret = 0, curcnt = 0;
	for (int i = dem; i >= 1; --i) {
		for (int j = 0; j < digit[i]; ++j) {
			if (i == dem && j == 0) continue;
			ret += f(i - 1, curcnt + (j != 0));
		}
		if (digit[i]) curcnt++;
	}
	ret += f(dem - 1, 0);
	return ret + (curcnt <= 3);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	memset(dp, -1, sizeof dp);
	cin >> tc;
	while (tc--) {
		int l, r;
		cin >> l >> r;
		cout << solve(r) - solve(l - 1) << endl;
	}

	return 0;
}