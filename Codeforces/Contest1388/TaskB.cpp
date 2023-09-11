#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int n8 = (n - 1) / 4 + 1;
		for (int i = 1; i <= n - n8; ++i) cout << 9;
		while(n8--) {
			cout << 8;
		}
		cout << endl;
	}

	return 0;
}