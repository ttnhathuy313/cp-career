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
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (i == 1 && j == 1) cout << "W";
				else cout << "B";
			}
			cout << endl;
		}
	}

	return 0;
}