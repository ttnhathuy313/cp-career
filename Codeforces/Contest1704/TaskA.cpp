#include <bits/stdc++.h>

using namespace std;

const int N = 50;
int okay[N][N], zero[2][N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		string s, t;
		cin >> s >> t;
		memset(zero, 0, sizeof zero);
		memset(okay, 0, sizeof okay);
		zero[0][0] = (s[0] - '0');
		zero[1][0] = (s[0] - '0');
		for (int i = 1; i < s.size(); ++i) {
			zero[0][i] = min(zero[0][i - 1], (s[i] - '0'));
		}

		for (int i = 1; i < s.size(); ++i) {
			zero[1][i] = max(zero[1][i - 1], (s[i] - '0'));
		}
		okay[s.size()][t.size()] = 1;
		okay[s.size() - 1][t.size() - 1] = (s[s.size() - 1] == t[t.size() - 1]);
		for (int i = s.size() - 1; i >= 0; --i) {
			for (int j = t.size() - 1; j >= 0; --j) {
				if ((s.size() - i) != (t.size() - j)) {
					continue;
				}
				okay[i][j] = okay[i + 1][j + 1] & (s[i] == t[j]);
			}
		}
		bool ok = false;

		for (int i = 0; i < s.size(); ++i) {
			if (zero[0][i] == t[0] - '0' && s.substr(i + 1, s.size() - i - 1) == t.substr(1, t.size() - 1)) {
				ok = true;
			}
			if (zero[1][i] == t[0] - '0' && s.substr(i + 1, s.size() - i - 1) == t.substr(1, t.size() - 1)) {
				ok = true;
			}
		}

		if (ok) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;
	}

	return 0;
}