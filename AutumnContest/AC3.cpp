#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define int long long
typedef pair <int, int> ii;

const int N = 55, MOD = 1e9 + 7, offset = 1000;
int n, g, sum, a[N], f[2][5205][N][N];

void add(int &a, int b) {
	a = (a + b) % MOD;
}

void solve() {
	cin >> n >> g >> sum;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	memset(f, 0, sizeof f);
	f[0][offset][0][0] = 1;
	for (int id = 1; id <= n; ++id) {
		int i = id & 1;
		for (int j = 0; j <= 5200; ++j) { // Tổng
			for (int tot = 1; tot <= g; ++tot) {
				for (int open = 0; open <= tot; ++open) {
					add(f[i][j][tot][open], f[i ^ 1][j][tot - 1][open]); // Thêm hiện tại thành một cái mới và đóng lại
					if (j >= a[id]) add(f[i][j][tot][open], f[i ^ 1][j - a[id]][tot][open + 1] * (open + 1)); // Thêm hiện tại vào một cái để đóng lại
					if (j + a[id] <= 5200 && open) add(f[i][j][tot][open], f[i ^ 1][j + a[id]][tot - 1][open - 1]); // Thêm hiện tại bắt đầu một cái mới
					add(f[i][j][tot][open], f[i ^ 1][j][tot][open] * open); // Thêm cái hiện tại nối với một cái bất kì
				}
			}
		}
		memset(f[i ^ 1], 0, sizeof f[i ^ 1]);
	}
	int res = 0;
	for (int k = 0; k <= sum; ++k) {
		add(res, f[n & 1][offset + k][g][0]);
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("AC3.INP", "r", stdin);
	freopen("AC3.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}