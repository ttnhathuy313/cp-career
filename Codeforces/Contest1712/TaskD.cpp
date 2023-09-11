#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int N = 1e5 + 5, oo = 1e9;
int n, a[N], k;

void solve() {
	cin >> n >> k;
	vector <pair <int, int>> b;
	b.clear();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b.push_back({a[i], i});
	}
	// D(u, v) = min(min(u -> v), 2 * global_min)
	sort(b.begin(), b.end());
	for (int i = 0; i < k - 1; ++i) {
		a[b[i].second] = oo;
		b[i].first = oo;
	}
	sort(b.begin(), b.end());
	multiset<int> S;
	S.clear();
	for (int i = 2; i <= n; ++i) {
		S.insert(min(a[i], a[i - 1]));
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (i > 1) {
			S.erase(S.find(min(a[i], a[i - 1])));
			S.insert(max(a[i], a[i - 1]));
		}
		if (i != n) {
			S.erase(S.find(min(a[i], a[i + 1])));
			S.insert(max(a[i], a[i + 1]));
		}

		int v1 = *S.rbegin();
		int v2 = 2 * b[(b[0].second == i)].first;
		res = max(res, min(v1, v2));

		if (i > 1) {
			S.erase(S.find(max(a[i], a[i - 1])));
			S.insert(min(a[i], a[i - 1]));
		}
		if (i != n) {
			S.erase(S.find(max(a[i], a[i + 1])));
			S.insert(min(a[i], a[i + 1]));
		}
	}
	cout << res << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}