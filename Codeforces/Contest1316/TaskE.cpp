#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, LOG = 8;
int n, a[N], s[N][LOG], f[N][1 << LOG], p, k;

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


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	vector <int> id; id.clear();
	cin >> n >> p >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		id.push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= p; ++j) {
			cin >> s[i][j];
		}
	}
	sort(id.begin(), id.end(), [](int i, int j) {
		return a[i] > a[j];
	});
	memset(f, -1, sizeof f);
	f[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		int ii = id[i - 1];
		cerr << ii << endl;
		for (int mask = 0; mask < (1 << p); ++mask) {
			if (__builtin_popcount(mask) > i) continue;
			int rem = i - 1 - __builtin_popcount(mask);
			for (int j = 0; j < p; ++j) if (mask & (1 << j)) {
				if (f[i - 1][mask ^ (1 << j)] != -1) f[i][mask] = max(f[i][mask], f[i - 1][mask ^ (1 << j)] + s[ii][j + 1]);
			}
			if (rem >= k) f[i][mask] = max(f[i][mask], f[i - 1][mask]);
			else if (~f[i - 1][mask]) f[i][mask] = max(f[i][mask], f[i - 1][mask] + a[ii]);
			// cerr << "f[" << i << "][" << show(mask) << "] : " << f[i][mask] << endl;
		}
	}
	cout << f[n][(1 << p) - 1] << endl;

	return 0;
}