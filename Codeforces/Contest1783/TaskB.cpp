#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
const int N = 55;
int ans[N][N], n;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector <array<int, 3>> pts;
		pts.clear();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) if ((i + j) % 2 == 0) {
				pts.push_back({i + j, i, j});
			}
		}
		sort(pts.begin(), pts.end());
		int cnt = 1;
		for (auto v : pts) {
			ans[v[1]][v[2]] = cnt;
			cnt++;
		}
		cnt = n * n;
		pts.clear();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) if ((i + j) % 2 == 1) {
				pts.push_back({i + j, i, j});
			}
		}
		sort(pts.begin(), pts.end());
		for (auto v : pts) {
			ans[v[1]][v[2]] = cnt;
			cnt--;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cout << ans[i][j] << ' ';
			}
			cout << endl;
		}
	}

	return 0;
}