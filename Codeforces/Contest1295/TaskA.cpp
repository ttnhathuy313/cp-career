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
		if (n & 1) {
			cout << 7;
			n -= 3;
		}
		for (int i = 0; i < n / 2; ++i) cout << 1;
		cout << endl;
	}

	return 0;
}