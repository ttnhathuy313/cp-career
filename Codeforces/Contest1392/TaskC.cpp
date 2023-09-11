#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, oo = 1e18;
int n, a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		vector <int> st;
		st.clear();
		st.push_back(oo);
		int res = 0;
		for (int i = n; i >= 1; --i) {
			int mi = oo;
			while (st.back() < a[i]) {
				mi = min(mi, st.back());
				st.pop_back();
			}
			if (mi != oo) res += a[i] - mi;
			st.push_back(a[i]);
		}
		cout << res << endl;
	}
  
	return 0;
}