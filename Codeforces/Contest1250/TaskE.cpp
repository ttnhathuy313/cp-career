#include <bits/stdc++.h>

using namespace std;

const int N = 155;
int n, m, k, g[N][N], color[N];
bool mark[N];
string s[N];

void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; ++i) {
		s[i + n] = s[i];
		reverse(s[i + n].begin(), s[i + n].end());
		s[i + n] = ' ' + s[i + n];
		s[i] = ' ' + s[i];
	}
	memset(g, 0, sizeof g);
	for (int i = 1; i <= n * 2; ++i) {
		for (int j = i + 1; j <= n * 2; ++j) {
			int tot = 0;
			for (int t = 1; t <= m; ++t) tot += (s[i][t] == s[j][t]);
			if (tot < k) g[i][j] = g[j][i] = 1;
			// if (g[i][j]) cerr << i << ' ' << j << endl;
		}
	}
	for (int i = 1; i <= n; ++i) g[i][i + n] = g[i + n][i] = 1;
	memset(mark, 0, sizeof mark);
	vector <int> res; res.clear();
	for (int uu = 1; uu <= n * 2; ++uu) if (!mark[uu]) {
		queue <int> q; while (!q.empty()) q.pop();
		mark[uu] = 1;
		q.push(uu);
		color[uu] = 1;
		vector <int> V; V.clear();
		int a1, a2; a1 = a2 = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			// cerr << u << " has color " << color[u] << endl;
			if (color[u]) a2 += (u > n);
			else a1 += (u > n);
			V.push_back(u);
			for (int v = 1; v <= n * 2; ++v) if (g[u][v]) {
				if (!mark[v]) {
					color[v] = color[u] ^ 1;
					mark[v] = 1;
					q.push(v);
				} else {
					if (color[v] != color[u] ^ 1) {
						cout << -1 << endl;
						return;
					}
				}
			}
		}
		// cerr << a1 << ' ' << a2 << endl;
		if (a1 < a2) {
			for (int u : V) if (u > n && color[u] == 0)
				res.push_back(u);
		} else {
			for (int u : V) if (u > n && color[u] == 1)
				res.push_back(u);
		}
	}
	cout << res.size() << endl;
	for (int u : res) cout << u - n << ' ';
	cout << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}