#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

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

const int N = 5e5 + 5;
int n, s[N], tot[N];
vector <int> a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskJ.INP", "r", stdin);
	freopen("TaskJ.OUT", "w", stdout);

	cin >> n;
	ordered_set S;
	S.clear();
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			int x;
			cin >> x;
			a[i].push_back(x);
		}
		sort(a[i].begin(), a[i].end());
		s[i] = a[i][0] + a[i][1];
		S.insert({s[i], i});
		tot[i] = a[i][0] + a[i][1] + a[i][2];
	}
	for (int i = 1; i <= n; ++i) {
		S.erase({s[i], i});
		cout << S.order_of_key(ii(tot[i] - 2, n + 1)) << ' ';
		S.insert({s[i], i});
	}


	return 0;
}