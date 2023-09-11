#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int n = 7;
	for (int k = 1; k <= n; ++k) {
		cerr << "k : " << k << endl;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) if ((i + j - 2) % n + 1 == k) {
				cerr << i << ' ' << j << endl;
			}
		}
		cerr << "~~~~~~~~~~~" << endl;
	}

	return 0;
}