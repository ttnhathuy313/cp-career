#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		map <char, int> cnt;
		cnt.clear();
		for (int i = 0; i < 4; ++i) {
			cnt[s[i]]++;
		}
		vector <int> D;
		D.clear();
		for (auto d : cnt) {
			D.push_back(d.second);
		}
		sort(D.begin(), D.end());
		if (D.size() == 1) {
			cout << -1 << endl;
		} else {
			if (D.size() == 2 && D[0] == 1 && D[1] == 3) {
				cout << 6 << endl;
			} else cout << 4 << endl;
		}
	}

	return 0;
}