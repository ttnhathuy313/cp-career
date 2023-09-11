#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
const int N = 2e5 + 5;
int a[N], n, nextUp[N], f[N], dp[N];
 
main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);
 
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int pre = 0;
	for (int i = 1; i <= n; ++i) {
		nextUp[i] = pre;
		if (a[i] != -1) pre = i;
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] == -1) {
			int j = nextUp[i];
			if (j == 0) {
				f[i] = i;
				continue;
			}
			else f[i] = i - j + 1;
			int k = nextUp[j];
			int space = (a[j] - a[k]) / (j - k);
			if ((a[j] - a[k]) % (j - k) != 0 || a[j] + space * (i - j) < 0) {
				f[i] = i - k;
				continue;
			}
			if (nextUp[k] == 0) {
				if (space <= 0) f[i] = i;
				else f[i] = i - k + 1 + min(k - 1, (a[k] - 1) / space);
			} else {
				int t = nextUp[k];
				if (a[k] - (k - t) * space == a[t])
					f[i] = i - t + f[t];
				else {
					if (space <= 0) f[i] = i - t;
					else f[i] = i - k + 1 + min(k - t - 1, (a[k] - 1) / space);
				}
			}
			continue;
		}
		f[i] = i - nextUp[i];
		if (nextUp[i] == 0) continue;
		if ((a[i] - a[nextUp[i]]) % (i - nextUp[i]) != 0) continue;
		int space = (a[i] - a[nextUp[i]]) / (i - nextUp[i]);
		int j = nextUp[i];
		if (nextUp[j] == 0) {
			if (space <= 0) f[i] = i;
			else f[i] = i - j + 1 + min(j - 1, (a[j] - 1) / space);
		}
		else {
			if (a[j] - (j - nextUp[j]) * space == a[nextUp[j]])
				f[i] = i - j + f[j];
			else {
				if (space <= 0) f[i] = i - nextUp[j];
				else f[i] = i - j + 1 + min(j - nextUp[j] - 1, (a[j] - 1) / space);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cerr << "f[" << i << "] : " << f[i] << endl;
	}
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n; ++i) {
		dp[i] = 1 + dp[i - f[i]];
	}
	cout << dp[n] << endl;
 
	return 0;
}