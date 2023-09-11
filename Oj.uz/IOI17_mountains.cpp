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
	int n = y.size();
	for (int r = 0; r < n; ++r) {
		dp[r][r] = 1;
		if (r == 0) continue;
		dp[r - 1][r] = 1;
		int xx = 1, yy = y[r] - y[r - 1], sum = 0, lastSeen = r - 1, id = r - 1;
		for (int l = r - 2; l >= 0; --l) {
			if (ccw(ii(r, y[r]), ii(lastSeen, y[lastSeen]), ii(l, y[l]))) {
				sum += dp[l + 1][lastSeen - 1];
				lastSeen = l;
			}
			dp[l][r] = max(dp[l][r - 1], sum + dp[l + 1][lastSeen - 1] + 1);
		}
	}


	return dp[0][n - 1];
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("IOI17_mountains.INP", "r", stdin);
	freopen("IOI17_mountains.OUT", "w", stdout);

	int n;
	cin >> n;
	vector <int32_t> solve; solve.clear();
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		solve.push_back(x);
		// cerr << "(" << i << ", " << x << ")" << endl;
	}

	cout << maximum_deevs(solve) << endl;

	return 0;
}