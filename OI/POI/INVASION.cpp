#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 605 * 2, M = 1e4 + 5;
int n, x[N], y[N], s[N][N], w[M], m, a[M], b[M];

ii toVec(int i, int j) {
	return ii(x[j] - x[i], y[j] - y[i]);
}
ii toVec2(int i, int j) {
	return ii(a[j] - x[i], b[j] - y[i]);
}

int cross(ii a, ii b) {
	return a.first * b.second - b.first * a.second;
}

bool ccw(int i, int j, int k) {
	return cross(toVec(i, j), toVec2(i, k)) > 0;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("INVASION.INP", "r", stdin);
	freopen("INVASION.OUT", "w", stdout);

	int tot = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		x[i + n] = x[i];
		y[i + n] = y[i];
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i] >> b[i] >> w[i];
		tot += w[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int l = i + 2, r = n + i - 2, id = -1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (ccw(i, mid, j)) id = mid, r = mid - 1;
				else l = mid + 1;
			}
			if (~id) s[i][id] += w[j];
		}
		for (int j = i + 2; j <= n + i - 2; ++j)
			s[i][j] += s[i][j - 1];
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			for (int k = j + 1; k <= n; ++k) {
				bool ok = (i == 2 && j == 3 && k == 5);
				int tmp = tot;
				if (ok) cerr << s[k][n + i] << endl;
				tmp -= s[i][j] + s[j][k] + s[k][n + i];
				res = max(res, tmp);
			}
		}
	}
	cout << res << endl;

	return 0;
}