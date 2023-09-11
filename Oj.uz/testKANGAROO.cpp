#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("KANGAROO.INP", "r", stdin);
	freopen("KANGAROO.OUT", "w", stdout);

	int n = 8, s = 3, t = 5;
	vector <int> a;
	int cnt = 0;
	for (int i = 1; i <= n; ++i)a.push_back(i);
	do {
		int term = (a[0] > a[1]);
		bool ok = (a[0] == s && a[n - 1] == t);
		for (int i = 0; i < n - 1; ++i) {
			if ((a[i] > a[i + 1]) != term) ok = false;
			term ^= 1;
		}
		if (ok) {
			// for (int i = 0; i < n; ++i)
			// 	cerr << a[i] << ' ';
			// cerr << endl;
			cnt++;
		}
	} while (next_permutation(a.begin(), a.end()));
	cerr << cnt << endl;
	return 0;
}