#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("vowel.INP", "r", stdin);
	freopen("vowel.OUT", "w", stdout);

	int tc;
	cin >> tc;
	map <char, int> mp;
	mp.clear();
	mp['u'] = mp['e'] = mp['o'] = mp['a'] = mp['i'] = 1;
	while (tc--) {
		string s;
		cin >> s;
		int a = 0, n = s.size();
		for (int i = 0; i < n; ++i) {
			if (mp[s[i]]) a++;
		}
		cout << s << endl;
		if (a > n - a) cout << 1 << endl;
		else cout << 0 << endl;
	}

	return 0;
}