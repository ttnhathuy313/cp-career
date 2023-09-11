#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 55;
int n, x[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		set <int> S; S.clear();
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				int area = x[j] - x[i];
				S.insert(area);
			}
		}
		cout << S.size() << endl;
	}

	return 0;
}