#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, m, ans[N];
vector <ii> qu[(int)1e6 + 5];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n >> m;
	vector <vector <int>> grid(n + 5, vector <int> (m + 5, 0));
	vector <vector <int>> go_up(n + 5, vector <int> (m + 5, 0));
	vector <vector <int>> go_left(n + 5, vector <int> (m + 5, m + 5));
	vector <vector <int>> go_out(n + 5, vector <int> (m + 5, 0));

	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			if (s[j - 1] == '.') grid[i][j] = 1;
			else grid[i][j] = 0;
			if (i == 1) go_up[i][j] = grid[i][j];
			else {
				go_up[i][j] = go_up[i - 1][j] & grid[i][j];
			}

			if (grid[i][j]) go_left[i][j] = min(go_left[i][j - 1], j);

			if (!grid[i][j]) go_out[i][j] = 0;
			else {
				if (go_up[i][j]) go_out[i][j] = 1;
				else go_out[i][j] = go_out[i][j - 1];
			}
		}
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		int u, v;
		cin >> u >> v;
		qu[v].push_back({u, i});
	}
	int cur = 0;
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= n; ++i) if (grid[i][j] && (!go_out[i][j])) {
			cur = max(cur, go_left[i][j]);
		}
		for (ii d : qu[j]) {
			if (d.first < cur) {
				ans[d.second] = 0;
			} else ans[d.second] = 1;
		}
	}
	cur = 0;
	for (int j = 1; j <= m; ++j) {
		for (int i = 2; i <= n; ++i) if (!grid[i][j] && !go_out[i - 1][j]) {
			int v = j;
			if (!grid[i][j - 1]) v = j;
			else v = go_left[i][j - 1];
			cur = max(cur, v);
		}
		for (ii d : qu[j]) {
			if (d.first < cur) ans[d.second] = 0;
		}
	}

	for (int i = 1; i <= q; ++i) {
		if (ans[i]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}