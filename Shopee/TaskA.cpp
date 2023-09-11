#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, K = 21, base1 = 37, base2 = 31, MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
int n, k, basePow1[N], basePow2[N], dp[1 << K], org[K];
string s, t[K];

struct hashValue {
	int hash1, hash2;
	bool operator==(const hashValue other) {
		return (hash1 == other.hash1 && hash2 == other.hash2);
	}
	void add(char c) {
		int cur = c - 'a' + 1;
		hash1 = hash1 * base1 + cur;
		hash1 %= MOD1;
		hash2 = hash2 * base2 + cur;
		hash2 %= MOD2;
	}

} pref[N], hs[K];

hashValue get(int j, int i) {
	if (i < j || j < 0) return {-1, -1};
	hashValue ret;
	ret.hash1 = pref[i].hash1 - pref[j - 1].hash1 * basePow1[i - j + 1] + MOD1 * MOD1;
	ret.hash1 %= MOD1;
	ret.hash2 = pref[i].hash2 - pref[j - 1].hash2 * basePow2[i - j + 1] + MOD2 * MOD2;
	ret.hash2 %= MOD2;
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	cin >> n >> s >> k;
	n = s.size();
	basePow1[0] = 1; basePow2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		basePow1[i] = basePow1[i - 1] * base1 % MOD1;
		basePow2[i] = basePow2[i - 1] * base2 % MOD2;
	}

	for (int i = 0; i < k; ++i) {
		cin >> t[i];
	}
	s = ' ' + s;
	pref[0] = {0, 0};
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1];
		pref[i].add(s[i]);
	}
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < t[i].size(); ++j) {
			hs[i].add(t[i][j]);
		}
	}

	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	int res = k + 1;
	string printedRes;
	for (int mask = 0; mask < (1 << k); ++mask) if (~dp[mask]) {
		int cur_len = 0;
		for (int i = 0; i < k; ++i) if (mask & (1 << i))
			cur_len += (int)t[i].size();
		for (int i = 0; i < k; ++i) if ((mask & (1 << i)) == 0) {
			int len = t[i].size();
			if (hs[i] == get(n - cur_len - len + 1, n - cur_len)) {
				int nxt_mask = mask | (1 << i);
				if (~dp[nxt_mask]) {
					dp[nxt_mask] = min(dp[nxt_mask], i);
				} else dp[nxt_mask] = i;
			}
		}
		if (cur_len == n) {
			string temp; temp.clear();
			vector <int> used; used.clear();
			int cur = mask;
			while (cur) {
				used.push_back(dp[cur]);
				cur ^= (1 << (dp[cur]));
			}
			for (int i : used) {
				temp += char(i + 1 + '0');
				temp += ' ';
			}
			temp.pop_back();
			if (res > (int)__builtin_popcount(mask)) {
				res = (int)__builtin_popcount(mask);
				printedRes = temp;
			} else if (res == (int)__builtin_popcount(mask)) {
				if (printedRes > temp) {
					printedRes = temp;
				}
			}
		}
	}
	cout << res << endl << printedRes;

	return 0;
}