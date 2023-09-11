#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5005;
bitset <N> visit[N];
int n, x1[N], y1[N], x2[N], y2[N];
vector <int> horizon, vertical;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		if (x1[i] == x2[i]) {
			if (y1[i] > y2[i]) swap(y1[i], y2[i]);
			vertical.push_back(i);
		} else {
			if (x1[i] > x2[i]) swap(x1[i], x2[i]);
			horizon.push_back(i);
		}
	}
	for (int i : horizon) {
		for (int j : vertical) {
			if ((x1[i] <= x1[j] && x2[i] >= x1[j]) && (y1[j] <= y1[i] && y2[j] >= y1[i])) {
				// cerr << i << ' ' << j << endl;
				visit[i][j] = 1;
				visit[j][i] = 1;
			}
		}
	}
	int res = 0;
	if (horizon.size() > vertical.size())
		swap(horizon, vertical);
	for (int i : horizon) {
		for (int j : horizon) if (i != j && i < j) {
			int c = (visit[i] & visit[j]).count();
			res += (c * (c - 1)) >> 1;
		}
	}
	cout << res << endl;

	return 0;
}