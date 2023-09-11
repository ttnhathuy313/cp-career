#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2005, MOD = 1e9 + 7;
int n, s, t, memo[N][N];

void add(int &a, int b) {
	a = (a + b) % MOD;
	return;
}

int calc(int pos, int k) {
	if (pos == n + 1)
		return (k == 1);
	if (~memo[pos][k]) return memo[pos][k];
	int ret = 0;
	if (pos == s) {
		add(ret,  calc(pos + 1, k));
		add(ret, calc(pos + 1, k + 1));
	} else if (pos == t) {
		add(ret, calc(pos + 1, k));
		add(ret, calc(pos + 1, k + 1));
	} else {
		add(ret, calc(pos + 1, k + 1) * (k + 1 - (pos > s) - (pos > t)));
		if (k >= 2) add(ret, calc(pos + 1, k - 1) * (k - 1));
	}
	return memo[pos][k] = ret;
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("KANGAROO.INP", "r", stdin);
	freopen("KANGAROO.OUT", "w", stdout);

	memset(memo, -1, sizeof memo);
	cin >> n >> s >> t;
	cout << calc(1, 0) << endl;

	return 0;
}