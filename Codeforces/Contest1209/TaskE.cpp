#include <bits/stdc++.h>

using namespace std;

const int N = 12;
int n, m, a[N * 2][2005], mx[2005], f[N][1 << N], cost[1 << N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int j = 1; j <= m; ++j) mx[j] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> a[i][j];
				a[n + i][j] = a[i][j];
				mx[j] = max(mx[j], a[i][j]);
			}
		}
		vector <int> perm; perm.clear();
		for (int j = 1; j <= m; ++j) perm.push_back(j);
		sort(perm.begin(), perm.end(), [](int i, int j) {
			return mx[i] > mx[j];
		});
		vector <int> col; col.clear();
		col.push_back(0);
		for (int i = 0; i < min((int)perm.size(), n); ++i) col.push_back(perm[i]);
		f[0][0] = 0;
		for (int i = 1; i <= col.size() - 1; ++i) {
			memset(cost, 0, sizeof cost);
			for (int mask = 0; mask < (1 << n); ++mask) {
				for (int turn = 0; turn < n; ++turn) {
					int temp = 0;
					for (int j = 0; j < n; ++j) if (mask & (1 << j)) {
						temp += a[j + 1 + turn][col[i]];
					}
					cost[mask] = max(cost[mask], temp);
				}
			}
			for (int mask = 0; mask < (1 << n); ++mask) {
				f[i][mask] = f[i - 1][mask];
				for (int submask = mask; submask; submask = (submask - 1) & mask) {
					f[i][mask] = max(f[i][mask], f[i - 1][mask ^ submask] + cost[submask]);
				}
			}
		}
		cout << f[col.size() - 1][(1 << n) - 1] << endl;
	}

	return 0;
}