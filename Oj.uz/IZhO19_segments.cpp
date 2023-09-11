#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 5e5 + 5, oo = 1e18;
int n, a[N], p[N];
set <ii> s[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("IZhO19_segments.INP", "r", stdin);
	freopen("IZhO19_segments.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
	}
	for (int i = 1; i <= n; ++i) {
		s[i].insert({1, 1});
		if (i == n) {
			cout << (*(s[i].rbegin())).first << endl;
			return 0;
		}
		int lst = oo;
		while (!s[i].empty()) {
			ii mx = *s[i].rbegin();
			s[i].erase(mx);
			if (mx.first == lst) continue;
			s[i + 1].insert(mx);
			int l = i + 1, r = n, ans = -1;
			int sum = p[i] - p[mx.second - 1];
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (p[mid] - p[i] >= sum) {
					r = mid - 1;
					ans = mid;
				} else l = mid + 1;
			}
			if (~ans) s[ans].insert({mx.first + 1, i + 1});
			if (lst != oo) break;
			lst = mx.first;
		}
	}

	return 0;
}