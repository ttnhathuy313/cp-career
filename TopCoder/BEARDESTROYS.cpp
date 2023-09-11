#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 55;
int dp[N][(1 << 7)], h, w, p2[N], MOD, cnt[N][(1 << 7)];

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
	freopen("BEARDESTROYS.INP", "r", stdin);
	freopen("BEARDESTROYS.OUT", "w", stdout);

	cin >> w >> h >> MOD;
	memset(dp, 0, sizeof dp);
	memset(cnt, 0, sizeof cnt);
	dp[0][0] = 0;
	cnt[0][0] = 1;
	int res = 0;
	for (int i = 0; i <= h; ++i) {
		for (int mask = 0; mask < (1 << w); ++mask) {
			int cur = cnt[i][mask], val = dp[i][mask], neg = (~mask) & ((1 << w) - 1);
			if (cur == 0) continue;
			if (i == h && mask == 0) {
				res = (res + val) % MOD;
				continue;
			}
			cerr << "cnt[" << i << "][" << show(mask) << "] : " << cnt[i][mask] << endl;
			cerr << "	" << val << endl;
			for (int submask = neg;; submask = (submask - 1) & neg) {
				int cost = 0, pre = -1;
				for (int j = 0; j <= w; ++j) if ((submask & (1 << j)) || (mask & (1 << j)) || j == w) {
					if ((j - pre - 1) & 1) if (i + 1 != h) cost = -N * N;
					cost += (j - pre - 1) / 2;
					pre = j;
				}
				int ways = (1 << cost);
				if (submask & (1 << (w - 1))) ways *= 2;
				for (int j = 0; j < w - 1; ++j) if (submask & (1 << j)) {
					if (mask & (1 << (j + 1))) ways *= 2;
				}
				ways *= (1 << (__builtin_popcount(mask)));
				cost += __builtin_popcount(submask);
				if (i + 1 == h) {
					int rem = w - __builtin_popcount(mask);
					ways = (1 << rem);
				}
				if (cost >= 0) {
					(cnt[i + 1][submask] += ways * cur) %= MOD;
					(dp[i + 1][submask] += val * ways + ways * cur * cost) %= MOD;
				}
				if (submask == 0) break;
			}
		}
	}
	cout << res << endl;

	return 0;
}