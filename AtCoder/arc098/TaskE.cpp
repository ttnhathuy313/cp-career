#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef pair <int, int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int N = 2005;
int n, k, q, a[N], res = (int)2e9, ans[N];
ordered_set S;

void solve(int lw) {
	S.clear();
	memset(ans, 0, sizeof ans);
	int pre = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i] < lw) {
			pre = i + 1;
			S.clear();
		} else {
			S.insert({a[i], i});
			ans[i] += i - pre + 1 - S.order_of_key({a[i], i});
		}
	}
	pre = n;
	S.clear();
	for (int i = n; i >= 1; --i) {
		if (a[i] < lw) {
			pre = i - 1;
			S.clear();
		} else {
			S.insert({a[i], i});
			ans[i] += pre - i - S.order_of_key({a[i], 0});
		}
	}
	vector <int> val; val.clear();
	for (int i = 1; i <= n; ++i) if (a[i] >= lw && ans[i] >= k) {
		val.push_back(a[i]);
	}
	if (val.size() < q) return;
	sort(val.begin(), val.end());
	res = min(res, val[q - 1] - lw);
	// cerr << "Ans for " << lw << " is " << val[q - 1] - lw << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> k >> q;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		solve(a[i]);
	}
	cout << res << endl;

	return 0;
}