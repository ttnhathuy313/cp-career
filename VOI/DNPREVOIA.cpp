#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
typedef pair <int, int> ii;

const int RANGE = 31625, oo = (int)1e18 + 1;
int lt[RANGE][65];

int mu(int x, int y) {
	if (y == 2) {
		if (x > (int)1e9) return oo;
		else return x * x;
	}
	if (y == 3) {
		if (x > (int)1e6) return oo;
		else return x * x * x;
	}
	if (x >= RANGE) return oo;
	return lt[x][y];
}

void solve(int n) {
	int res = 1, pre = n;
	vector <ii> ret; ret.clear();
	ret.push_back({n, 1});
	for (int b = 2; b <= 64; ++b) {
		int l = 1, r = pre, ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (mu(mid, b) <= n) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		if (mu(ans, b) == n) {
			ret.push_back({ans, b});
		}
		pre = ans;
	}
	for (int i = ret.size() - 1; i >= 0; --i) {
		cout << ret[i].first << ' ' << ret[i].second << endl;
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("DNPREVOIA.INP", "r", stdin);
	freopen("DNPREVOIA.OUT", "w", stdout);
	clock_t tStart = clock();

	for (int i = 1; i < RANGE; ++i) {
		lt[i][0] = 1;
		for (int j = 1; j <= 64; ++j) {
			if (lt[i][j - 1] > (int)1e18 / i) lt[i][j] = oo;
			else lt[i][j] = lt[i][j - 1] * i;
		}
	}
	int tc;
	cin >> tc;
	while (tc--) {	
		int n;
		cin >> n;
		solve(n);
	}
	fprintf(stderr, "Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

	return 0;
}