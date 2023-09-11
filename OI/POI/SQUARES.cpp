#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("SQUARES.INP", "r", stdin);
	freopen("SQUARES.OUT", "w", stdout);

	set <int> val;
	val.clear();
	for (int i = 0; i < (1 << 10); ++i) {
		int t = 0;
		for (int j = 0; j < 10; ++j) if (i & (1 << j))
			t += i * i;
		val.insert(t);
	}
	for (int v : val) cerr << v << endl;

	return 0;
}