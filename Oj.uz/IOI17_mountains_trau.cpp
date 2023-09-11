#include <bits/stdc++.h>

using namespace std;
#define int long long
#define sqr(a) (a * a)
typedef pair <int, int> ii;

const int N = 2005;
int dp[N][N];

int cross(ii a, ii b) {
	return a.first * b.second - a.second * b.first;
}

bool ccw(ii a, ii b, ii c) {
	return cross(ii(b.first - a.first, b.second - a.second), ii(c.first - a.first, c.second - a.second)) > 0;
}

int maximum_deevs(vector <int32_t> y) {
	int n = y.size(), ret = 0;
	for (int mask = 0; mask < (1 << n); ++mask) {
		int t = __builtin_popcount(mask);
		for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
			for (int j = i + 1; j < n; ++j) if (mask & (1 << j)) {
				bool ok = false;
				for (int k = i + 1; k < j; ++k) if (ccw(ii(j, y[j]), ii(k, y[k]), ii(i, y[i]))) {
					ok = true;
				}
				if (!ok) t = -1;
			}
		}
		ret = max(ret, t);
	}

	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("IOI17_mountains.INP", "r", stdin);
	freopen("IOI17_mountains.ANS", "w", stdout);

	int n;
	cin >> n;
	vector <int32_t> solve; solve.clear();
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		solve.push_back(x);
	}

	cout << maximum_deevs(solve) << endl;

	return 0;
}