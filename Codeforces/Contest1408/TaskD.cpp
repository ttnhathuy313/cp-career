#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2005, M = 1e6 + 1;
int n, m, a[N], b[N], c[N], d[N], mx[N * N + 10000];
vector <ii> val;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
	}
	for (int j = 1; j <= m; ++j) {
		cin >> c[j] >> d[j];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) if (a[i] <= c[j] && b[i] <= d[j]) {
			val.push_back({c[j] - a[i] + 1, d[j] - b[i] + 1});
		}
	}
	if (val.empty()) {
		cout << 0 << endl;
		return 0;
	}
	sort(val.begin(), val.end());
	mx[val.size()] = 0;
	int res = (int)1e18;
	for (int i = (int)val.size() - 1; i >= 0; --i) {
		mx[i] = max(mx[i + 1], val[i].second);
		if (i > 0) res = min(res, mx[i] + val[i - 1].first);
		else res = min(res, mx[i]);
	}
	res = min(res, val.back().first);

	cout << res << endl;

	return 0;
}