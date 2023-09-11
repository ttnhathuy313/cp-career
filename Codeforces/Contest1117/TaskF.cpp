#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LOG = 17;
int n, p, bad[1 << LOG], f[1 << LOG], g[25][25], ins[1 << LOG], cnt[26];
string s;

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
	int r = p - ret.size();
	while (r--) ret = '0' + ret;
	return ret;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n >> p;
	cin >> s;
	s = ' ' + s;
	for (int i = 0; i < p; ++i) {
		for (int j = 0; j < p; ++j) {
			cin >> g[i][j];
		}
	}
	for (int i = 0; i < p; ++i) {
		for (int j = 0; j < p; ++j) if (!g[i][j]) {
			int pre = -1, curMask = 0;
			for (int k = 1; k <= n; ++k) {
				if (s[k] - 'a' == j) {
					if (~pre) {
						bad[curMask] = 1;
						ins[curMask] = 1;
						pre = -1;
						curMask = 0;
					} 
				} 
				if (s[k] - 'a' == i) {
					pre = k;
					curMask = 0;
				} 
				if (s[k] - 'a' != i && s[k] - 'a' != j) curMask |= (1 << (s[k] - 'a'));
			}
			for (int mask = 0; mask < (1 << p); ++mask) if (ins[mask]) {
				for (int k = 0; k < p; ++k) if (k != i && k != j && (mask & (1 << k)) == 0) {
					bad[mask | (1 << k)] = 1;
					ins[mask | (1 << k)] = 1;
				}
				ins[mask] = 0;
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		cnt[s[i] - 'a']++;
	memset(f, -1, sizeof f);
	f[0] = 0;
	// for (int i = 1; i < (1 << p); ++i) if (bad[i]) {
	// 	cerr << show(i) << endl;
	// }
	int res = 0;
	for (int mask = 1; mask < (1 << p); ++mask) if (!bad[mask]) {
		for (int i = 0; i < p; ++i) if (mask & (1 << i)) {
			if (~f[mask ^ (1 << i)]) f[mask] = max(f[mask], f[mask ^ (1 << i)] + cnt[i]);
		}
		res = max(res, f[mask]);
		if (f[mask] == n) cerr << show(mask) << endl;
	}
	cout << n - res << endl;

	return 0;
}