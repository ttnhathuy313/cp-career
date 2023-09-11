#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <char, int> ii;

int cost(string s) {
	int n = s.size() - 1, res = 0;
	for (int i = 1; i <= n; ++i) {
		int mn = 3931, id = -1;
		for (int j = i; j <= n; ++j) {
			if (s[j] < mn) {
				mn = s[j];
				id = j;
			}
		}
		string t; t.clear(); t.push_back(char(mn));
		s.insert(i, t);
		s.erase(id + 1, 1);
		res += id - i;
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int cnt[26][2];
		memset(cnt, 0, sizeof cnt);
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		s = ' ' + s; t = ' ' + t;
		int mx = 0;
		vector <ii> a, b; a.clear(); b.clear();
		for (int i = 1; i <= n; ++i) {
			cnt[s[i] - 'a'][0]++;
			cnt[t[i] - 'a'][1]++;
			a.push_back({s[i], i - 1});
			b.push_back({t[i], i - 1});
			mx = max(mx, cnt[s[i] - 'a'][0]);
			mx = max(mx, cnt[t[i] - 'a'][1]);
		}
		bool ok = true;
		for (int i = 0; i < 26; ++i) if (cnt[i][0] != cnt[i][1]) {
			ok = false;			
		}
		if (!ok) {
			cout << "NO" << endl;
			continue;
		}
		if (mx > 1) {
			cout << "YES" << endl;
			continue;
		}
		int res1 = cost(s);  int res2 = cost(t);
		if ((res1 % 2) != (res2 % 2)) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}

	return 0;
}