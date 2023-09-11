#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, S = 350;
int n, m, q, a[N], isHeavy[N], bucket, mark[N], res[N], lazy[N], id[N], reflex[N];
int32_t giao[N][S];
vector <int> s[N], heavy, light;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int overall = 0;
	for (int k = 1; k <= m; ++k) {
		int sz;
		cin >> sz;
		overall += sz;
		for (int i = 1; i <= sz; ++i) {
			int d;
			cin >> d;
			res[k] += a[d];
			s[k].push_back(d);
		}
	}
	bucket = (int)sqrt(overall) + 1;
	for (int i = 1; i <= m; ++i) {
		if (s[i].size() < bucket) light.push_back(i);
		else {
			heavy.push_back(i);
			isHeavy[i] = 1;
		}
	}
	int cnt = 0;
	for (int i : heavy) {
		id[i] = ++cnt;
		reflex[cnt] = i;
		memset(mark, 0, sizeof mark);
		for (int j : s[i]) mark[j] = 1;
		for (int j = 1; j <= m; ++j) if (j != i) {
			for (int v : s[j]) if (mark[v]) giao[j][cnt]++;
		}
	}
	while (q--) {
		char type;
		cin >> type;
		if (type == '?') {
			int temp = 0, u;
			cin >> u;
			if (!isHeavy[u]) {
				for (int i : heavy) {
					temp += 1LL * lazy[i] * giao[u][id[i]];
				}
				for (int i : s[u]) temp += a[i];
				cout << temp << endl;
			} else {
				for (int i : heavy) if (i != u)
					temp += 1LL * lazy[i] * giao[u][id[i]];
				temp += res[u] + 1LL * lazy[u] * s[u].size();
				cout << temp << endl;
			}
		} else {
			int u, k;
			cin >> u >> k;
			if (!isHeavy[u]) {
				for (int i : s[u]) a[i] += k;
				for (int i : heavy) res[i] += 1LL * giao[u][id[i]] * k;
			} else {
				lazy[u] += k;
			}
		}
	}

	return 0;
}