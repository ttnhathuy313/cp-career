#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int x;
		cin >> x;
		string s;
		cin >> s;
		vector <char> S;
		S.clear();
		S.push_back('0');
		for (int i = 0; i < s.size(); ++i) S.push_back(s[i]);
		int now = (int)s.size() - 1, tot = s.size();
		for (int l = 1; l <= x; ++l) {
			if ((int)S.size() <= x + 10) {
				int d = (int)S.size();
				int cnt = (S[l] - '1');
				while (cnt--) {
					for (int j = l + 1; j < d; ++j) S.push_back(S[j]);
				}
			}
			tot += (S[l] - '1') * now % MOD;
			tot %= MOD;
			now *= (S[l] - '0');
			now %= MOD;
			now = (now - 1 + MOD) % MOD;
		}
		cout << tot << endl;
	}

	return 0;
}