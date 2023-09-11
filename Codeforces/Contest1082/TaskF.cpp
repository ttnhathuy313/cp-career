#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int X[N], C[N], n, k, A, ans = 0;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	multiset <int> cost;
	cost.clear();
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> X[i];
	cin >> A;
	for (int i = 0; i < n; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < n; i++) {
		cost.insert(C[i]);
		if (k >= X[i]) continue;
		while (k < X[i]) {
			if (cost.empty()) {
				cout << -1;
				return 0;
			}
			ans += *(cost.begin());
			cost.erase(cost.begin());
			k += A;
		}
	}
	cout << ans;

	return 0;
}