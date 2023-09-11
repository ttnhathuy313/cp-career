#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 65, B = 11;
int pref[B][N][(1LL << 10)][B];

int solve(int base, int l) {
	if (l == 0) return 0;
	vector <int> digit(65, 0);
	int r = l, cnt = 0, curMask = 0, mm = 0;
	while (r) {
		digit[++cnt] = r % base;
		mm ^= (1LL << (r % base));
		r /= base;
	}
	int res = 0;
	for (int i = cnt; i >= 1; --i) {
		if (digit[i]) {
			// cerr << "	+" << pref[base][i][curMask][digit[i] - 1] - (i == cnt ? pref[base][i][curMask][0] : 0) << endl;
			res += pref[base][i][curMask][digit[i] - 1] - (i == cnt ? pref[base][i][curMask][0] : 0);
		}
		if (i != 1) {
			// cerr << "	" << pref[base][i - 1][0][base - 1] - pref[base][i - 1][0][0] << endl;
			res += pref[base][i - 1][0][base - 1] - pref[base][i - 1][0][0];
		}
		curMask ^= (1LL << (digit[i]));
	}
	if (mm == 0) res++;
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	for (int base = 2; base <= 10; ++base) {
		for (int i = 0; i < base; ++i) pref[base][1][(1 << i)][i] = 1;
		for (int mask = 0; mask < (1LL << base); ++mask) {
			for (int num = 1; num < base; ++num) {
				pref[base][1][mask][num] += pref[base][1][mask][num - 1];
			}
		}
		for (int i = 2; i <= 64; ++i) {
			for (int mask = 0; mask < (1LL << base); ++mask) {
				for (int num = 0; num < base; ++num) {
					if (num != 0) pref[base][i][mask][num] = pref[base][i][mask][num - 1];
					pref[base][i][mask][num] += pref[base][i - 1][mask ^ (1LL << num)][base - 1];
				}
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int b, l, r;
		cin >> b >> l >> r;
		cout << solve(b, r) - solve(b, l - 1) << endl;
	}

	return 0;
}