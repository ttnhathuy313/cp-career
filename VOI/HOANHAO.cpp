#include <bits/stdc++.h>

using namespace std;
#define int long long

	int c[33333]; 


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("HOANHAO.INP", "r", stdin);
	freopen("HOANHAO.OUT", "w", stdout);

	int b = 161616;
	int res = 0;
	set <int> D; D.clear();
	for (int i = 1; i <= b; ++i) {
		int j = i;
		int p = 1;
		while (j) {
			p *= (j % 10);
			j /= 10;
		}
		if (p * i <= b && p * i) {
			// cout << i << ' ' << p << endl;
			if (p == 4) cerr << i << endl;
			c[p]++;
			D.insert(p);
			res++;
		}
	}
	cerr << res << endl;
	for (int v : D) {
		cout << v << ' ' << c[v] << endl;
	}
	return 0;
}