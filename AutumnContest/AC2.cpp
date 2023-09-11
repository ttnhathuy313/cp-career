#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair <int, int> ii;

const int N = 55;
int n, g, sum, a[N], ans[N], id[N], trace[N][N * 2][N];
bool f[N][N * 2][N]; // index, sum, no. of group

void solve() {
	cin >> n >> g >> sum;
	vector <ii> A; A.clear();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];	
		A.push_back({a[i], i});
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < n; ++i) {
		a[i + 1] = A[i].first;
		id[i + 1] = A[i].second;
	}
	memset(f, 0, sizeof f);
	memset(trace, -1, sizeof trace);
	f[0][0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= sum; ++j) {
			for (int k = 1; k <= g; ++k) {
				for (int t = 1; t <= i; ++t) if (a[i] - a[t] <= j && f[t - 1][j - a[i] + a[t]][k - 1]) {
					f[i][j][k] |= f[t - 1][j - a[i] + a[t]][k - 1];
					trace[i][j][k] = t;
				}
			}
		}
	}
	int rem = -1, i = n;
	for (int i = 0; i <= sum; ++i) if (f[n][i][g]) {
		rem = i;
	}
	if (~rem) {
		while (g) {
			int pre = trace[i][rem][g];
			for (int j = pre; j <= i; ++j) ans[id[j]] = g;
			rem -= a[i] - a[pre];
			i = pre - 1;
			g--;
		}
		for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
		cout << endl;
	} else cout << "IMPOSSIBLE" << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("AC2.INP", "r", stdin);
	freopen("AC2.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}