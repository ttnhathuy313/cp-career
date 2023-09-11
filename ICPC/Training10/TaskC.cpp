#include <bits/stdc++.h>

using namespace std;
#define int long long 

const int N = 1e7 + 5;
bool mark[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int p, n;
	cin >> p >> n;
	int mn = min(2 * p, n);
	int cur = 0, res = 1;
	mark[0] = 1;
	for (int i = 1; i <= mn; ++i) {
		cur += i;
		if (cur >= p) cur -= p;
		if (cur >= p) cur -= p;
		if (mark[cur] == 0) {
			mark[cur] = 1;
			res++;
		}
	}
	cout << res << endl;

	return 0;
}