#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int m = 95, d = 96, w = 25;
	for (int i = 1; i <= min(m, d); ++i) {
		for (int j = 1; j <= min(m, d); ++j) if ((i + (j - 1) * d) % w == (j + (i - 1) * d) % w) if (i < j) {
			cerr << i << ' ' << j << endl;
		}
	}

	return 0;
}