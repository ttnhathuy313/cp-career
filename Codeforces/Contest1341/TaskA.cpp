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
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		int up = n * (a + b);
		if (up < c - d) {
			cout << "No\n";
			continue;
		}
		int lw = n * (a - b);
		if (lw > c + d) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
	}

	return 0;
}