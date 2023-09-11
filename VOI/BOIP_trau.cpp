#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, p, a[N];

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
	// reverse(ret.begin(), ret.end());
	return ret;
}


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("BOIP.INP", "r", stdin);
	freopen("BOIP.ANS", "w", stdout);

	cin >> n >> p; // case p = 1
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int res = 0;
	for (int mask = 0; mask < (1 << n); ++mask) {
		bool ok = true;
		for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
			for (int j = 0; j < n; ++j) if (mask & (1 << j)) {
				if (a[j] == a[i] * p && i != j) ok = false;
			}
		}
		if (ok) {
			res = max(res, 1ll*__builtin_popcount(mask));
		}
	}
	
	cout << res << endl;

	return 0;
}