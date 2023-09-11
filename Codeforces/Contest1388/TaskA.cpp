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
		int x;
		cin >> x;
		if (x <= 30) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			if (x == 36) {
				cout << "6 10 15 " << x - 31 << endl;
				continue;
			}
			if (x == 40) {
				cout << "6 10 15 9\n";
				continue;
			}
			if (x == 44) {
				cout << "6 10 15 13\n";
				continue;
			}
			cout << "6 10 14 " << x - 30 << endl;
		}
	}

	return 0;
}