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
		string s;
		cin >> s;
		int n = s.size();
		if (n >= 2 && s.substr(n - 2, 2) == "po") {
			cout << "FILIPINO" << endl;
		} else if (n >= 4 && s.substr(n - 4, 4) == "desu" || s.substr(n - 4, 4) == "masu") {
			cout << "JAPANESE" << endl;
		} else cout << "KOREAN" << endl;
 	}	

	return 0;
}