#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, half = (1 << 11) + 5, K = 21;
int n, a[N], k[N], f[half][half][K], dp[N], trace[N];

int bi(string s) {
	reverse(s.begin(), s.end());
	int res = 0;
	for (int i = 0; i < s.size(); ++i) if (s[i] == '1')
		res += (1 << i);
	return res;
}

string show(int d) {
	string ret; ret.clear();
	while (d) {
		ret = char((d % 2) + '0') + ret;
		d /= 2;
	}
	return ret;
}



signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("IZhO17_subsequence.INP", "r", stdin);
	freopen("IZhO17_subsequence.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)
		cin >> k[i];
	int halve = (1 << 10) - 1, res = 0;
	int f38 = a[38] >> 10, s38 = a[38] & halve, f52 = a[52] >> 10, s52 = a[52] & halve;

	for (int i = 1; i <= n; ++i) {
		int s = (a[i] & halve);
		dp[i] = 1;
		for (int fd = 0; fd <= halve; ++fd) {
			int fbc = __builtin_popcount((a[i] >> 10) & fd);
			if (fbc > k[i]) continue;
			int val = dp[f[fd][s][k[i] - fbc]] + 1;
			if (dp[i] < val) {
				dp[i] = val;
				trace[i] = f[fd][s][k[i] - fbc];
			}
		}
		for (int sc = 0; sc <= halve; ++sc) {
			int pre = dp[f[a[i] >> 10][sc][__builtin_popcount(s & sc)]];
			if (pre < dp[i]) {
				f[a[i] >> 10][sc][__builtin_popcount(s & sc)] = i;
			}
		}
		// if (i == 38) cerr << f[f38][s52][k[52] - __builtin_popcount(f52 & f38)] << endl;
		res = max(res, dp[i]);
	}
	cout << res << endl;
	int i;
	for (i = 1; i <= n; ++i) if (dp[i] == res)
		break;
	vector <int> ans; ans.clear();
	while (i) {
		ans.push_back(i);
		i = trace[i];
	}
	reverse(ans.begin(), ans.end());
	for (int j : ans) cout << j << ' ';

	return 0;
}