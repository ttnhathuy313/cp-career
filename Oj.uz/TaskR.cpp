#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2005, MOD = 1e9 + 7;
string s;
int start, lst, memo[N][N], n;

void add(int &a, int b) {
	a = (a + b) % MOD;
	return;
}

int calc(int pos, int k) {
	if (pos == n + 1)
		return (k == 1);
	if (~memo[pos][k]) return memo[pos][k];
	int ret = 0;
	if (pos == start) {
		if (s[pos] != 'R' && k) add(ret, calc(pos + 1, k));
		if (s[pos] != 'L') add(ret, calc(pos + 1, k + 1));
	} else if (pos == lst) {
		if (k) add(ret, calc(pos + 1, k));
		add(ret, calc(pos + 1, k + 1));
	} else {
		if (s[pos] != 'L')
			add(ret, calc(pos + 1, k + 1) * (k + 1 - (pos > start) - (pos > lst)) % MOD);
		if (s[pos] != 'R' && k >= 2)
			add(ret, calc(pos + 1, k - 1) * (k - 1) % MOD);
		if (s[pos] != 'R' && k)
			add(ret, calc(pos + 1, k) * (k - (pos > start)) % MOD);
		if (s[pos] != 'L' && k)
			add(ret, calc(pos + 1, k) * (k - (pos > lst)) % MOD);
	}
	return memo[pos][k] = ret;
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskR.inp", "r", stdin);
	freopen("TaskR.out", "w", stdout);

	cin >> s >> start >> lst;
	n = s.size();
	s = '!' + s;
	memset(memo, -1, sizeof memo);
	cout << calc(1, 0) << endl;

	return 0;
}