#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef pair <int, int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

const int N = 2e5 + 5;
int n, k, a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	ordered_set S; S.clear();
	S.insert({0, 0});
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res += S.order_of_key({a[i] - k * i, i});
		S.insert({a[i] - k * i, i});
	}
	cout << res << endl;

	return 0;
}