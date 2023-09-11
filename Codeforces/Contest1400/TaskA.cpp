#include <bits/stdc++.h>

using namespace std;

bool mark[444];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = 0, cur = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '0') {
				cur++;
				ans = max(ans, cur);
			} else {
				cur = 0;
			}
		}
		if (ans < n) {
			for (int i = 1; i <= n; ++i) cout << 1; cout << endl;
			continue;
		}
		memset(mark, 0, sizeof mark);
		int curr = 0, lst = -1;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '0') {
				if (lst == -1) lst = i;
				curr++;
				if (curr == ans) {
					break;
				}
			} else {
				curr = 0;
				lst = -1;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (i == lst + 1) {
				cout << "0";
			} else cout << "1";
		}
		cout << endl;
	}

	return 0;
}