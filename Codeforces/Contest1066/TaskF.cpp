#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, x[N], y[N];
set <int> bounds;
map <int, int> dp[2], minx, miny;
map <int, ii> Left, Right;

int dist(ii a, ii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n;
	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		int b = max(x[i], y[i]);
		if (bounds.find(b) == bounds.end()) {
			bounds.insert(b);
			minx[b] = b + 1;
			miny[b] = b + 1;
		}
		mx = max(mx, b);
		if (y[i] == b) minx[b] = min(minx[b], x[i]);
		if (minx[b] != b + 1) {
			Left[b] = ii(minx[b], b);
		} else {
			Left[b] = max(Left[b], ii(x[i], y[i]));
		}
		if (x[i] == b) miny[b] = min(miny[b], y[i]);
		if (miny[b] != b + 1) {
			Right[b] = ii(b, miny[b]);
		} else {
			Right[b] = max(Right[b], ii(x[i], y[i]));
		}
	}
	int pre = 0;
	for (int i : bounds) {
		dp[0][i] = min(dp[1][pre] + dist(Right[pre], Right[i]), dp[0][pre] + dist(Left[pre], Right[i]))+ dist(Left[i], Right[i]);
		dp[1][i] = min(dp[1][pre] + dist(Right[pre], Left[i]), dp[0][pre] + dist(Left[pre], Left[i])) + dist(Left[i], Right[i]); 
		pre = i;
	}
	cout << min(dp[0][mx], dp[1][mx]) << endl;

	return 0;
}