#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
	string s;
	cin >> s;
	int mask = 0, n = s.size();
	for (int i = 0; i < s.size(); ++i) {
		int num = s[i] - '0';
		mask ^= (1 << num);
	}
	int notZero = n;
	for (int i = s.size() - 1; i >= 0; --i) {
		int num = s[i] - '0';
		if (i == 0 && num == 1) break;
		mask ^= (1 << num);
		if (num == 0) continue;
		// Check if any permutation satisfy
		bool ok = false;
		int bc = __builtin_popcount(mask);
		if ((bc & 1) != ((n - i) & 1)) continue;
		if (bc > (n - i)) continue;

		if (bc < (n - i)) ok = true;
		else {
			if (mask & ((1 << num) - 1)) {
				ok = true;
			} else ok = false;
		}
		// End checking
		if (ok) {
			//generate best string
			for (int j = 0; j < i; ++j)
				cout << s[j];
			if (bc < n - i) {
				cout << num - 1;
				mask ^= (1 << (num - 1));
			} else {
				int tmp = mask & ((1 << num) - 1);
				int lg = (int)log2(tmp);
				cout << lg;
				mask ^= (1 << lg);
			}
			int rem = (n - i - 1 - __builtin_popcount(mask));
			assert(rem % 2 == 0);
			while (rem--)
				cout << 9;
			for (int j = 9; j >= 0; --j) if (mask & (1 << j)) {
				cout << j;
			}
			cout << endl;
			return;
		}
	}
	if (s[0] == '1') {
		mask ^= (1 << 1);
		n--;
		if (n & 1) n--;
		int bc = __builtin_popcount(mask);
		for (int i = 0; i < (n - bc); ++i)
			cout << 9;
		for (int i = 9; i >= 0; --i) if (mask & (1 << i)) {
			cout << i;
		}
		cout << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}