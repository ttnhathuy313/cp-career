#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, a[N], p[N], mark[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE1.INP", "r", stdin);
	freopen("TaskE1.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			p[a[i]] = i;
			mark[i] = 0;
		}
		int pre = n + 1;
		for (int i = 1; i <= n; ++i) {
			if (p[i] < pre) {
				pre = p[i];
				mark[p[i]] = 1;
			}
		}
		for (int i = n; i >= 1; --i) if (mark[i]) {
			cout << a[i] << ' ';
		}
		for (int i = 1; i <= n; ++i) if (!mark[i]) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}

	return 0;
}