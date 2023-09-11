#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int cnt[N][30];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	string s;
	cin >> s;
	for (int i = s.size() - 1; i >= 0; --i) {
		cnt[i][s[i] - 'a']++;
		for (int c = 0; c < 26; ++c) {
			cnt[i][c] += cnt[i + 1][c];
		}
	}
	int res = 0;
	for (int i = 0; i < 26; ++i) {
		int tmp = 0, ff = 0;
		int ans[28];
		memset(ans, 0 ,sizeof ans);
		for (int j = 0; j < s.size(); ++j) if (s[j] - 'a' == i) {
			ff++;
			for (int c = 0; c < 26; ++c) ans[c] += cnt[j + 1][c];
		}
		tmp = max(tmp, ff);
		for (int j = 0; j < 26; ++j) tmp = max(tmp, ans[j]);
		res = max(res, tmp);
	}
	cout << res << endl;

	return 0;
}