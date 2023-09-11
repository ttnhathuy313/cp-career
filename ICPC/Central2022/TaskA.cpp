#include <bits/stdc++.h>

using namespace std;

const int N = 305;
int memo[N][N][N], n, k, pref[N], suf[N];
string s;

int calc(int i, int j, int taken) {
	int total = pref[i - 1] + suf[j + 1];
	if (total - taken == k) {
		return true;
	}
	if (taken == k) {
		return false;
	}
	if (i > j) {
		return false;
	}
	if (~memo[i][j][taken]) {
		return memo[i][j][taken];
	}
	int res = (1 ^ calc(i + 1, j, total - taken)) | (1 ^ calc(i, j - 1, total - taken));

	return memo[i][j][taken] = res;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	cin >> n >> k;
	cin >> s;

	memset(memo, -1, sizeof memo);
	s = ' ' + s;
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + (s[i] == 'B');
	}

	for (int i = n; i >= 1; --i) {
		suf[i] = suf[i + 1] + (s[i] == 'B');
	}
	if (calc(1, n, 0)) {
		cout << "YES" << endl;
	} else cout << "NO" << endl;

	return 0;
}