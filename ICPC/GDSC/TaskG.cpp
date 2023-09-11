#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, nxt[N][27], m;
string s, t;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	cin >> s >> t;
	n = s.size();
	m = t.size();
	s = ' ' + s;
	t = ' ' + t;
	memset(nxt, -1, sizeof nxt);
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < 26; ++j) {
			if (s[i + 1] - 'a' == j) nxt[i][j] = i + 1;
			else nxt[i][j] = nxt[i + 1][j];
		}
	}
	int pt = 0, res = 0;
	for (int i = 1; i <= m; ++i) {
		int cur = t[i] - 'a';
		if (nxt[0][cur] == -1) {
			cout << -1 << endl;
			return 0;
		}
		if (nxt[pt][cur] == -1) {
			pt = 0;
		} 
		if (nxt[pt][cur] != -1) {
			if (pt == 0) res++;
			pt = nxt[pt][cur];
		}
	}
	cout << res << endl;

	return 0;
}