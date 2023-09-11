#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 5e5 + 5;
int n, a[N], l[N], r[N], ans[N], q;
vector <int> query[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("EMPIRES.INP", "r", stdin);
	freopen("EMPIRES.OUT", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= q; ++i) {
		cin >> l[i] >> r[i];
		query[l[i]].push_back(i);
	}
	vector <int> st;
	st.clear();
	for (int i = n; i >= 1; --i) {
		while (st.size() && a[i] >= a[st.back()])
			st.pop_back();
		st.push_back(i);
		for (int j : query[i]) {
			int target = r[j];
			int l = 0, r = st.size() - 1, res = -1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (st[mid] <= target) r = mid - 1, res = mid;
				else l = mid + 1;
			}
			ans[j] = st.size() - res;
		}
	}
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << endl;
	}

	return 0;
}