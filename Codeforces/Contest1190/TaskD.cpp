#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> os;
#define int long long
typedef pair <int, int> ii;
 
const int N = 2e5 + 5;
ii a[N];
int n;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + 1 + n, [](ii a, ii b){
		return a.second != b.second ? a.second > b.second : a.first < b.first; 
	});
	int ans = 0;
	for(int i = 1; i <= n; i++){
		os.insert(a[i].first);
		int ta = os.size();
		if(i < n && a[i].second == a[i + 1].second)
			ta = os.order_of_key(a[i + 1].first);
		ans += (os.order_of_key(a[i].first) + 1) * (ta - os.order_of_key(a[i].first));
	}
	cout << ans << '\n';

	return 0;
}