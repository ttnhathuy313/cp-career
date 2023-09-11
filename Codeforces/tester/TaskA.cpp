#include <bits/stdc++.h>

using namespace std;

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
		int lst = -1;
		for (int i = 0; i < n; ++i) if ((s[i] - '0') & 1) lst = i;
		if (lst == -1) {
			cout << -1 << endl;
			continue;
		}
		int f = -1;
		for (int i = 0; i < lst; ++i) if ((s[i] - '0') & 1) f = (s[i] - '0');
		if (f == -1) {
			cout << -1 << endl;
		} else {
			cout << f << s[lst] << endl;
		}
	}	

	return 0;
}