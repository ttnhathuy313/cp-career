#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LOG = 8;
int n, m, k, dp[1 << 8], pos[N], cur;
map <int, vector <int>> mp;

void erase(int u) {
	cur ^= (1 << u);
	for (int mask = 0; mask < (1 << k); ++mask) if (mask & (1 << u)) {
		dp[mask] = dp[mask ^ (1 << u)] = max(dp[mask], dp[mask ^ (1 << u)]);
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		int l, r;
		cin >> l >> r;
		mp[l].push_back(i);
		mp[r + 1].push_back(-i);
	}
	int lst = 0;
	for (auto it : mp) {
		for (int mask = 0; mask < (1 << k); ++mask) if (__builtin_popcount(mask & cur) & 1)
			dp[mask] += it.first - lst;
		lst = it.first;
		for (auto v : it.second) {
			if (v < 0) {
				erase(pos[-v]);
			}
		}
		for (auto v : it.second) if (v > 0) {
			int f = 0;
			while (cur & (1 << f)) f++;
			pos[v] = f;
			cur ^= (1 << f);
		}
	}
	cout << dp[0] << endl;

	return 0;
}