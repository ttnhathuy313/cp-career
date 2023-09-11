#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	// freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int odd = 0, even = 0;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			if (x & 1) odd ++;
			else even ++;
		}
		if (even & 1) {
			if (odd % 4 == 1 || odd % 4 == 0) {
				cout << "Alice" << endl;
			} else cout << "Bob" << endl;
		} else {
			if (odd % 4 == 3 || odd % 4 == 0) {
				cout << "Alice" << endl;
			} else cout << "Bob" << endl;
		}
	}

	return 0;
}