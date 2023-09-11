#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef pair <int, int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

const int N = 1e5 + 5;
int a[N], n, pref[N];
ordered_set S;

int check(int mid) {
	S.clear();
	memset(pref, 0, sizeof pref);
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > mid) pref[i] = -1;
		else pref[i] = 1;
	}
	for (int i = 1; i <= n; ++i) pref[i] += pref[i - 1];
	S.insert({0, 0});
	for (int i = 1; i <= n; ++i) {
		res += S.order_of_key({pref[i], 0});
		S.insert({pref[i], i});
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int bound = (n * (n + 1) / 2) / 2 + 1;
	int l = 0, r = (int)1e9, ans = r;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int d = check(mid);
		if (d >= bound) {
			r = mid - 1;
			ans = min(ans, mid);
		} else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}