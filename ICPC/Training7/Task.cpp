#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
typedef pair <int, int> ii;

typedef tree<
ii,
null_type,
less<ii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int N = 2e5 + 5;
int n, m, res[N];
ii a[N], b[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> b[i].first >> b[i].second;
	}
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	int l = n, r = m;
	ordered_set S;
	S.clear();
	while (l--) {
		while (r > 0 && b[r].first >= a[l].first) {
			
		}
	}

	return 0;
}