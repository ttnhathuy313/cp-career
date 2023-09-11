#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef pair <int, int> ii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

string s;
int cnt[30];
vector <int> ind[30];
int res[(int)2e5 + 5];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> s;
	int n = s.size();
	s = ' ' + s;
	for (int i = 1; i <= n; ++i) {
		cnt[s[i] - 'a']++;
		ind[s[i] - 'a'].push_back(i);
	}
	int r = -1;
	for (int i = 0; i < 26; ++i) if (cnt[i] & 1) {
		if (~r) {
			cout << -1 << endl;
			return 0;
		}
		r = i;
	}
	vector <ii> p; p.clear();
	for (int c = 0; c < 26; ++c) {
		int sz = ind[c].size();
		vector <int> T = ind[c];
		for (int i = 1; i <= sz / 2; ++i) if (T[i - 1] != T[sz - i]) {
			p.push_back({T[i - 1], T[sz - i]});
		}
	}
	sort(p.begin(), p.end());
	int cnt = 0;
	for (ii v : p) {
		// cerr << v.first << ' ' << v.second << endl;
		cnt++;
		res[cnt] = v.first;
		res[n - cnt + 1] = v.second;
	}
	if (~r) {
		res[n / 2 + 1] = ind[r][ind[r].size() / 2];
	}
	ordered_set S; S.clear(); S.insert(res[1]);
	int ans = 0;
	for (int i = 2; i <= n; ++i) {
		ans += i - 1 - S.order_of_key(res[i]);
		S.insert(res[i]);
	}
	cout << ans << endl;

	return 0;
}