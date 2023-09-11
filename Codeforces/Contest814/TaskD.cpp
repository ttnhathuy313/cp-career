#include <bits/stdc++.h>

using namespace std;
#define int long long
#define sqr(a) (a) * (a)

const int N = 1005;
const double pi = acos(-1);
int x[N], r[N], y[N], n, dp[N][10]; // 0 : max Sum, 1 : max 1 - 2, 2 : max 2 - 1, 3 : min 1 + 2
bool root[N];
vector <int> adj[N];

bool cmp(int a, int b) {
	return r[a] < r[b];
}

void dfs(int u) {
	int s1 = 0, s2 = 0, s = 0, s3 = 0, s5 = 0, s6 = 0;
	for (int v : adj[u]) {
		dfs(v);
		s1 += dp[v][1], s2 += dp[v][2], s += dp[v][0], s3 += dp[v][3];
		s5 += dp[v][5], s6 += dp[v][6];
	}
	dp[u][0] = sqr(r[u]) + max(s1, s2);
	dp[u][3] = sqr(r[u]) + min(s5, s6);
	dp[u][1] = max(s - sqr(r[u]), sqr(r[u]) - s3);
	dp[u][2] = max(s - sqr(r[u]), sqr(r[u]) - s3);
	dp[u][5] = min(s3 - sqr(r[u]), sqr(r[u]) - s);
	dp[u][6] = min(s3 - sqr(r[u]), sqr(r[u]) - s);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n; vector <int> ind; ind.clear();
	for (int i = 1; i <= n; ++i) {
		ind.push_back(i);
		cin >> x[i] >> y[i] >> r[i];
		root[i] = 1;
	}
	sort(ind.begin(), ind.end(), cmp);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int u = ind[i], v = ind[j];
			if (r[u] == r[v]) continue;
			if (sqr(x[v] - x[u]) + sqr(y[v] - y[u]) - sqr(r[v]) < 0) {
				root[u] = false;
				adj[v].push_back(u);
				cerr << v << ' ' << u << endl;
				break;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) if (root[i]) {
		dfs(i);
		res += dp[i][0];
	}
	cerr << dp[4][3] << endl;
	cout << fixed << setprecision(9) << pi * res << endl;

	return 0;
}