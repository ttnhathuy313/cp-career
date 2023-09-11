#include <bits/stdc++.h>

using namespace std;

int ans[105];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.inp", "r", stdin);
	freopen("TaskB.out", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int a, b, c;
		cin >> a >> b >> c;
		string s;
		cin >> s;
		memset(ans, 0, sizeof ans);
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'R') {
				if (b > 0) ans[i] = 2, b--;
			}
			if (s[i] == 'P') if (c > 0)
				ans[i] = 3, c--;
			if (s[i] == 'S') if (a > 0)
				ans[i] = 1, a--;
		}
		int win = 0;
		for (int i = 0; i < n; ++i) {
			if (ans[i] == 0) {
				if (a > 0) ans[i] = 1, a--;
				else if (b > 0) ans[i] = 2, b--;
				else if (c > 0) ans[i] = 3, c--;
			} else win++;
		}
		if (win < (n + 1)/2) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for (int i = 0; i < n; ++i) {
			if (ans[i] == 1) cout << "R";
			if (ans[i] == 2) cout << "P";
			if (ans[i] == 3) cout << "S";
		}
		cout << endl;
	}

	return 0;
}