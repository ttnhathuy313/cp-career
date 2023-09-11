#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int n;
	cin >> n;
	int m = 1 + n / 2;
	cout << m << endl;
	cout << "1 1" << endl;
	for (int i = 2; i <= n; ++i) {
		int row = 1 + i / 2;
		if (i & 1) cout << row << ' ' << row << endl;
		else cout << row << ' ' << row - 1 << endl;
	}

	return 0;
}