#include <bits/stdc++.h>

using namespace std;

int cnt1[26], cnt2[26];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		string p, h;
		cin >> p >> h;
		memset(cnt1, 0, sizeof cnt1);
		bool ok = false;
		for (int i = 0; i < p.size(); ++i) cnt1[p[i] - 'a']++;
		for (int i = 0; i < h.size(); ++i) {
			for (int j = i; j < h.size(); ++j) {
				memset(cnt2, 0, sizeof cnt2);
				for (int k = i; k <= j; ++k) cnt2[h[k] - 'a']++;
				bool t = true;
				for (int k = 0; k < 26; ++k) if (cnt2[k] != cnt1[k]) t = false;
				ok |= t;
			}
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}