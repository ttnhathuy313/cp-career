#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	map <char, int> cnt;
	while (tc--) {
		cnt.clear();
		string s;
		cin >> s;
		for (char c : s) {
			cnt[c]++;
		}
		if (cnt['B'] == cnt['A'] + cnt['C']) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;
	}

	return 0;
}