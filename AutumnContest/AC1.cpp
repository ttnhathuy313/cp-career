#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("AC1.INP", "r", stdin);
	freopen("AC1.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int c1, c2, c3;
		cin >> c1 >> c2 >> c3;
		int res = (int)1e9;
		res = min(res, c1 + c3 + c2);
		res = min(res, 2 * c1 + 2 * c2);
		res = min(res, 2 * c1 + 2 * c3);
		res = min(res, 2 * c2 + 2 * c3);
		cout << res << endl;
	}

	return 0;
}