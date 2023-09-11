#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 3e5 + 5;
int mask[N], n, val[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n;
	int s = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i] >> mask[i];
		s += val[i];
	}
	if (s < 0) {
		for (int i = 1; i <= n; ++i)
			val[i] = -val[i];
	}
	int curSum = 0, curmask = 0;
	for (int i = 0; i < 62; ++i) {
		int tmp = 0;
		for (int j = 1; j <= n; ++j) if ((int)log2(mask[j]) == i) {
			if (__builtin_popcountll(mask[j] & curmask) & 1) tmp -= val[j];
			else tmp += val[j];
		}
		if (tmp > 0) curmask ^= (1LL << i);
		curSum += tmp;
	}
	cout << curmask << endl;

	return 0;
}