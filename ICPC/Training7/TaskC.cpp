#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 5;
int res[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int p;
	cin >> p;
	memset(res, -1, sizeof res);
	for (int i = 0; i < p; ++i) {
		res[(i * i) % p] = i;
	}
	for (int i = 0; i < p; ++i)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}