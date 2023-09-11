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
int n, a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE2.INP", "r", stdin);
	freopen("TaskE2.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		ordered_set S; S.clear();
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			int choice1 = S.order_of_key({a[i], 0});
			int choice2 = i - 1 - S.order_of_key({a[i], n + 1});
			res += min(choice1, choice2);
			S.insert({a[i], i});
		}
		cout << res << endl;
	}

	return 0;
}