#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, k, p[N], c[N], ans[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	if (k == 0) {
		for (int i = 1; i <= n; ++i) cout << c[i] << ' ';
		return 0;
	}
	vector <int> id; id.clear();
	for (int i = 1; i <= n; ++i) id.push_back(i);
	sort(id.begin(), id.end(), [](int i, int j) {
		return p[i] < p[j];
	});
	int cursor = 0;
	multiset <int> cur; cur.clear();
	while (cursor < n) {
		int i = id[cursor];
		int res = 0;
		for (int v : cur) res += v;
		ans[i] = res + c[i];
		if (cur.size() < k) cur.insert(c[i]);
		else {
			if (*(cur.begin()) < c[i]) {
				cur.erase(cur.begin());
				cur.insert(c[i]);
			}
		}
		while (cursor + 1 < n && p[id[cursor + 1]] == p[i]) {
			ans[id[cursor + 1]] = res + c[id[cursor + 1]];
			if (cur.size() < k) cur.insert(c[id[cursor + 1]]);
			else {
				if (*(cur.begin()) < c[id[cursor + 1]]) {
					cur.erase(cur.begin());
					cur.insert(c[id[cursor + 1]]);
				}
			}
			cursor++;
		}
		cursor++;
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';


	return 0;
}