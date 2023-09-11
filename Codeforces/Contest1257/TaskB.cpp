#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.inp", "r", stdin);
	freopen("TaskB.out", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int x, y;
		cin >> x >> y;
		if (x >= y) {
			cout << "YES" << endl;
		} else {
			if (x == 2 && y == 3) {
				cout << "YES" << endl;
				continue;
			}
			if (x <= 3) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}

	return 0;
}