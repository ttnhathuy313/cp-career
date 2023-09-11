#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 105;
int n, a[N], b[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	vector <ii> res;
	res.clear(); 
	for (int t = 1; t <= n; ++t) {
		int nextA = N, nextB = N;
		for (int i = t; i <= n; ++i) {
			nextA = min(nextA, a[i]);
			nextB = min(nextB, b[i]);
		}
		bool found = false;
		int id = -1;
		for (int i = t; i <= n; ++i) {
			if (a[i] == nextA && b[i] == nextB) {
				found = true;
				id = i;
				if (i == t) {
					continue;
				}
				res.push_back({i, t});
				swap(a[i], a[t]);
				swap(b[i], b[t]);
			}
		}
		if (!found) {
			cout << -1 << endl;
			return;
		}
	}
	cout << (res.size()) << endl;
	for (ii d : res) {
		cout << d.first << ' ' << d.second << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}