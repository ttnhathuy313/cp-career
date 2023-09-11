#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 100;
int a[N];


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		vector <ii> res; res.clear();
		for (int i = 1; i <= n; ++i) {
			int mn = (int)1e9 + 7, id = -1;
			for (int j = i; j <= n; ++j) {
				if (a[j] < mn) {
					mn = a[j];
					id = j;
				}
			}
			if (i == id) continue;
			for (int j = id - 1; j >= i; --j) {
				swap(a[j], a[j + 1]);
			}
			a[i] = mn;
			res.push_back({i, id});
		}
		cout << res.size() << endl;
		for (ii d : res) {
			cout << d.first << ' ' << d.second << ' ' << d.second - d.first << endl;
		}
	}

	return 0;
}