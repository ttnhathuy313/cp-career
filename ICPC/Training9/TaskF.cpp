#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int half = n / 2;
		for (int i = 0; i < half; ++i) {
			cout << 'a';
		}
		cout << 'b';
		for (int i = 0; i < half - 1; ++i) {
			cout << 'a';
		}
		if (n > 1) if (n & 1) {
			cout << 'c';
		}
		cout << endl;
	}

	return 0;
}