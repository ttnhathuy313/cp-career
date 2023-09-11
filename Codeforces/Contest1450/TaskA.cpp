#include <bits/stdc++.h>

using namespace std;
#define int long long

int cnt[26];
bool mark[26];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	string t = "trygub";
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		memset(mark, 0, sizeof mark);
		memset(cnt, 0, sizeof cnt);
		string s;
		cin >> s;
		for (int i = 0; i < n; ++i)
			cnt[s[i] - 'a']++;
		vector <char> res; res.clear();
		for (int i = 0; i < t.size(); ++i) {
			int cur = t[i] - 'a';
			mark[cur] = 1;
			while (cnt[cur]--) res.push_back(t[i]);
		}
		for (int i = 0; i < 26; ++i) if (!mark[i]) {
			while (cnt[i]--) res.push_back(char('a' + i));
		}
		reverse(res.begin(), res.end());
		for (char c : res) cout << c;
		cout << endl;
	}

	return 0;
}