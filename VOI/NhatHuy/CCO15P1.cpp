#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, t[N], w;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("CCO15p1.INP", "r", stdin);
	freopen("CCO15p1.OUT", "w", stdout);

	cin >> n >> w;
	int s = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
		s += t[i];
	}
	sort(t + 1, t + 1 + n);
	if (w == 0) {
		cout << t[n] - t[1] << ' ' << s << endl;
	}

	return 0;
}