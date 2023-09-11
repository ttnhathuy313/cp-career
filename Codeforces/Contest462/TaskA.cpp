#include <bits/stdc++.h>

using namespace std;

string s[105];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	int ok = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int cnt = 0;
			if (j != 0 && s[i][j - 1] == 'o') cnt++;
			if (j != n - 1 && s[i][j + 1] == 'o') cnt++;
			if (i != 0 && s[i - 1][j] == 'o') cnt++;
			if (i != n - 1 && s[i + 1][j] == 'o') cnt++;
			if (cnt & 1) ok = false;
 		}
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}