#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int L;
	cin >> L;
	int hbit = (int)log2(L);
	cout << hbit + 1 << ' ' << hbit * 2 + (__builtin_popcount(L) - 1) << endl;
	for (int i = 1; i <= hbit; ++i) {
		cout << i << ' ' << i + 1 << ' ' << (1 << (i - 1)) << endl;
		cout << i << ' ' << i + 1 << " 0" << endl;
	}
	int curw = (1 << hbit);
	for (int i = 0; i < hbit; ++i) if ((L & (1 << i))) {
		cout << i + 1 << ' ' << hbit + 1 << ' ' << curw << endl;
		curw += (1 << i);
	}

	return 0;
}