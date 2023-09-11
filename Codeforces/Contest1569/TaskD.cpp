#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int x[N], y[N], n, m, k;

void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		int v;
		cin >> v;
		x[i] = v;
	}
	for (int i = 1; i <= m; ++i) {
		int v;
		cin >> v;
		y[i] = v;
	}
	vector <ii> row, col;
	row.clear(); col.clear();
	for (int i = 1; i <= k; ++i) {
		int u, v;
		cin >> u >> v;
		bool b1 = (*lower_bound(x + 1, x + 1 + n, u)) == u, b2 = (*lower_bound(y + 1, y + 1 + m, v) == v);
		if ((b1 ^ b2) == 0) continue;
		if (b1) col.push_back({v, u});
		if (b2) row.push_back({u, v});
	}
	sort(row.begin(), row.end());
	int tren = 0, duoi = 0, bad = 0;
	map <int, int> cnt; cnt.clear();
	for (int i = 0; i < row.size(); ++i) {
		int cur = row[i].first;
		while (tren < n && x[tren + 1] <= cur) {
			tren++;
		}
		while (duoi < i && row[duoi].first < x[tren]) {
			cnt[row[duoi].second]++;
			duoi++;
		}
		// cerr << "At " << cur << " : " << (i - max(0LL, duoi)) + cnt[row[i].second] << "  " << duoi << endl;
		bad += i - max(duoi, 0LL) + cnt[row[i].second];
	}
	while (duoi < row.size()) {
		cnt[row[duoi].second]++;
		duoi++;
	}
	for (auto d : cnt) {
		bad -= (d.second - 1) * d.second / 2;
	}
	sort(col.begin(), col.end());
	tren = 0, duoi = 0;
	cnt.clear();
	for (int i = 0; i < col.size(); ++i) {
		int cur = col[i].first;
		while (tren < m && y[tren + 1] <= cur) {
			tren++;
		}
		while (duoi < i && col[duoi].first < y[tren]) {
			cnt[col[duoi].second]++;
			duoi++;
		}
		bad += (i - max(0LL, duoi)) + cnt[col[i].second];
	}
	while (duoi < col.size()) {
		cnt[col[duoi].second]++;
		duoi++;
	}
	for (auto d : cnt) {
		bad -= (d.second - 1) * d.second / 2;
	}
	cout << bad << endl;
}

signed main() {
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