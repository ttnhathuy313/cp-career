#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, M = 18;
int n, dp[N], cnt[N], k, pre[N], near[N][M], pos[1 << M];
string s;

bool check(int mid) {
	for (int j = 0; j < k; ++j) {
		near[n + 1][j] = n + 1;
		for (int i = n; i >= 1; --i) {
			if (s[i] != '?') {
				if (dp[i] >= mid && s[i] - 'a' == j) near[i][j] = i;
				else near[i][j] = near[i + 1][j];
			} else {
				if (cnt[i] >= mid) near[i][j] = i;
				else {
					int nxt = i + cnt[i];
					if (s[nxt] - 'a' == j && dp[i] >= mid) near[i][j] = i;
					else near[i][j] = near[i + 1][j];
				}
			}
		}
	}

	for (int i = 1; i < (1 << k); ++i)
		pos[i] = n + 1;
	pos[0] = 0;
	for (int mask = 0; mask < (1 << k); ++mask) if (pos[mask] != n + 1) {
		int i = pos[mask];
		for (int j = 0; j < k; ++j) if ((mask & (1 << j)) == 0) {
			if (near[i + 1][j] != n + 1) {
				pos[mask ^ (1 << j)] = min(pos[mask ^ (1 << j)], near[i + 1][j] + mid - 1);
			}
		}
	}
	if (pos[(1 << k) - 1] != n + 1) return true;
	else return false;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> k >> s;
	n = s.size();
	s = ' ' + s + ' ';

	for (int i = n; i >= 1; --i) {
		if (s[i] == s[i + 1]) cnt[i] = cnt[i + 1] + 1;
		else cnt[i] = 1;
		if (s[i] == s[i + 1]) dp[i] = dp[i + 1] + 1;
		else {
			if (s[i] == '?') dp[i] = dp[i + 1] + 1;
			else {
				if (s[i + 1] == '?') {
					if (s[i + cnt[i + 1] + 1] == s[i]) dp[i] = dp[i + 1] + 1;
					else dp[i] = 1 + cnt[i + 1];
				} else dp[i] = 1;
			}
		}
	}

	int l = 0, r = n, res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1, res = mid;
		else r = mid - 1;
	}
	cout << res << endl;

	return 0;
}