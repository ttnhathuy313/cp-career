#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, cnt[99];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		n = s.size();
		s = ' ' + s;
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= n; ++i) cnt[s[i] - '0']++;
	
		int mx = 0;
		for (int i = 0; i <= 9; ++i) mx = max(mx, cnt[i]);

		int res = n - mx;
		for (int n1 = 0; n1 <= 9; ++n1) {
			for (int n2 = 0; n2 <= 9; ++n2) if (n2 != n1) {
				int turn = n1;
				int tmp = 0;
				for (int i = 1; i <= n; ++i) {
					if (s[i] - '0' != turn) tmp++;
					else {
						if (turn == n1) turn = n2;
						else turn = n1;
					}
				}
				if (turn == n1) res = min(res, tmp);
			}
		}
		cout << res << endl;
	}

	return 0;
}