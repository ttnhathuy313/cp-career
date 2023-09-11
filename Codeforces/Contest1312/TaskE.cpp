#include <bits/stdc++.h>

using namespace std;
 
const int N = 505, oo = 1e9;
int dp[N][N], v[N], ans[N];
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i], dp[i][i] = v[i];
	for (int i = 2; i <= n; i++)
		if (v[i] == v[i - 1])
			dp[i - 1][i] = v[i] + 1;
	for (int l = 2; l <= n; l++)
		for (int left = 1; left + l - 1 <= n; left++)
			for (int rght = left; rght <= left + l - 1; rght++)
				if (dp[left][rght] && dp[rght + 1][l + left - 1] == dp[left][rght])
					dp[left][left + l - 1] = dp[left][rght] + 1;
	for (int i = 0; i <= n; i++)
		ans[i] = oo;
	ans[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			if(dp[j][i])
				ans[i] = min(ans[j-1] + 1, ans[i]);
	cout << ans[n];
	return 0;
}