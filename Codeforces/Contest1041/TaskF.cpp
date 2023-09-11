#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, m, a[N], b[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	int y1;
	cin >> n >> y1;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	cin >> m >> y1;
	for (int i = 1; i <= m; ++i) cin >> b[i];
	pair <int, int> res(0, 0);
	int mx = 0;
	for (int i = 1; i <= m; ++i) {
		if (binary_search(a + 1, a + 1 + n, b[i])) {
			mx = 2;
			break;
		}
	}
	for (int len = 1; len <= (int)1e9; len <<= 1) {
		map <int, int> cnt; cnt.clear();
		for (int i = 1; i <= n; ++i) {
			cnt[a[i] % (len * 2)]++;
		}
		for (int i = 1; i <= m; ++i) {
			cnt[(b[i] + len) % (len * 2)]++;
		}
		for (auto v : cnt) if (mx < v.second) {
			res = {-v.first, -v.first + len};
			mx = v.second;
		}
	}
	cerr << res.first << ' ' << res.second;
	cout << mx << endl;

	return 0;
}