#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
typedef pair <int, int> ii;
typedef pair <ii, int> iii;

typedef tree<
ii,
null_type,
less<ii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int N = 2e5 + 5;
int n, m, res[N];
iii a[N], b[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first.first >> a[i].first.second;
		a[i].second = i;
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> b[i].first.first >> b[i].first.second;
		b[i].second = i;
	}
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);

	int l = n, r = m;
	set <ii> S;
	S.clear();
	while (l) {
		// cerr << "AT " << l << endl;
		while (r > 0 && b[r].first.first >= a[l].first.first) {
			S.insert({b[r].first.second, b[r].second});
			// cerr << "	" << r << ' ' << b[r].first.second << ' ' << b[r].second << endl;
			r--;
		}
		set <ii>::iterator it = S.lower_bound({a[l].first.second, 0});
		if (it == S.end()) {
			cout << -1 << endl;
			return 0;
		}
		res[a[l].second] = (*it).second;
		S.erase(it);
		l--;
	}
	for (int i = 1; i <= n; ++i) {
		cout << res[i] << ' ';
	}

	return 0;
}