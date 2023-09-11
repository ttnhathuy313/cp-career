#include<bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2005, MOD = 924844033;
int a, b, vv[100001], cnn, dp[N][N][3]; 
int su[N][N],dp1[N][N],fac[N];
vector <int> qu[100001];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.inp", "r", stdin);

	fac[0] = 1;
	for (int i = 1;i <= 2000; i++) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	cin >> a >> b;
	for(int i = 1 ; i <= a; i++) {
		if (vv[i]) break;
		cnn++;
		for(int j = i; j <= a; j += b * 2) {
			vv[j] = 1;
			qu[cnn].push_back(j);
		}
	}
	for(int i = 1; i <= cnn; i++) {
		dp[1][0][0] = 1;
		if(qu[i][0] + b <= a) {
			dp[1][1][1] = 1;
		} else dp[1][1][1]=0;
		if (qu[i][0] > b) {
			dp[1][1][2] = 1;
		} else dp[1][1][2]=0;
		for (int j = 1; j < qu[i].size(); j++) {
			for (int k = 0;k <= j + 1; k++) {
				dp[j + 1][k][0] = dp[j][k][0] + dp[j][k][1] + dp[j][k][2];
				if (k > 0) dp[j + 1][k][1] = dp[j][k - 1][0] + dp[j][k - 1][1] + dp[j][k - 1][2];
				if (qu[i][j] + b > a) dp[j + 1][k][1] = 0;
				if (k > 0) dp[j +1 ][k][2] = dp[j][k - 1][0] + dp[j][k - 1][2];
				if (qu[i][j] <= b) dp[j + 1][k][0] = 0;
				dp[j + 1][k][0] %= MOD;
				dp[j + 1][k][1] %= MOD;
				dp[j + 1][k][2] %= MOD;
			}
		}
		for(int j = 0; j <= qu[i].size(); j++) {
			su[i][j] = (dp[qu[i].size()][j][0] + dp[qu[i].size()][j][1] + dp[qu[i].size()][j][2]) % MOD;
		}
	}
	int sum = 0;
	dp1[0][0] = 1;
	for(int i = 1; i <= cnn; i++) {
		for(int j = 0; j <= qu[i].size(); j++) {
			for(int k = 0; k <= sum; k++) {
				(dp1[i][j + k] += dp1[i - 1][k] * su[i][j] % MOD) %= MOD;
			}
		}
		sum += qu[i].size();
	}
	int tt = 1, ans = 0;
	for (int i = 0; i <= a; i++) {
		(dp1[cnn][i] *= fac[a - i]) %= MOD;
		(ans += dp1[cnn][i] * tt) %= MOD;
		tt *= -1;
	}
	(ans += MOD) %= MOD;
	cout << ans << endl;

	return 0;
}