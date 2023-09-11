#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
string s;
int pre[N], fi[N * 2];

void solve() {
	int n = s.size();
	s = ' ' + s;
	memset(fi, -1, sizeof fi);
	fi[N] = 0;
	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1];
		if (s[i] == 'A') pre[i]++;
		else pre[i]--;
		if (fi[pre[i] + N] == -1) fi[pre[i] + N] = i;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (fi[pre[i] + N + 1] != -1) res = max(res, i - fi[pre[i] + N + 1]);
		if (fi[pre[i] + N] != -1) res = max(res, i - fi[pre[i] + N]);
		if (fi[pre[i] + N - 1] != -1) res = max(res, i - fi[pre[i] + N - 1]);
	}
	cout << res << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("ABSS.INP", "r", stdin);
	freopen("ABSS.OUT", "w", stdout);

	while (cin >> s) {
		solve();
	}

	return 0;
}