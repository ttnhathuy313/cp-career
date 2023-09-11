#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int r1, c1, r2, c2, r3, c3;
		cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
		vector <array<int, 2>> a;
		a.clear();
		a.push_back({r1, c1});
		a.push_back({r2, c2});
		a.push_back({r3, c3});
		sort(a.begin(), a.end());
		int r , c;
		if (a[0][0] == a[1][0]) {
			r = a[0][0], c = a[2][1];
		} else r = a[2][0], c = a[0][1];
		int x, y;
		cin >> x >> y;
		if ((r == 1 || r == n) && (c == 1 || c == n)) {
			if (x != r && y != c) {
				cout << "NO" << endl;
				continue;
			}
		}
		if (abs(x - r) % 2 == 0 || abs(y - c) % 2 == 0) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;
	}

	return 0;
}