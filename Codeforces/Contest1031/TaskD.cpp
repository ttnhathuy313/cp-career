#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 2005;
int dp[N][N], n, k;
string a[N];
bool mark[N][N];
ii trace[N][N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = ' ' + a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) dp[i][j] = (int)1e9;
	}
	vector <ii> cur; cur.clear();
	int mx = 0; ii id = {1, 1};
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == 1 && j == 1) {
				dp[i][j] = (a[i][j] != 'a');
				goto lmao;
			}
			if (i > 1) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			if (j > 1) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			dp[i][j] += (a[i][j] != 'a');
			lmao:;
			if (dp[i][j] <= k && i + j - 1 >= mx) {
				mx = i + j - 1;
			}
		}
	}
	if (mx == 2 * n - 1) {
		for (int i = 1; i <= 2 * n - 1; ++i) cout << "a";
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) if (dp[i][j] <= k && i + j - 1 == mx) {
			cur.push_back({i, j});
		}
	}
	vector <ii> nxt; nxt.clear();
	if (cur.empty() && n == 1) {
		cout << a[1][1] << endl;
		return 0;
	}
	if (cur.empty()) {
		cout << a[1][1];
		cur.push_back({1, 1});
	}
	while (1) {
		int minVal = 1122003;
		for (ii d : cur) {
			int u = d.first, v = d.second;
			if ((u + 1 == n && v == n) || (v + 1 == n && u == n)) {
				trace[n][n] = d;
				goto label1;
			}
			if (u != n) minVal = min(minVal, a[u + 1][v] - 'a');
			if (v != n) minVal = min(minVal, a[u][v + 1] - 'a');
		}
		nxt.clear();
		for (ii d : cur) {
			int u = d.first, v = d.second;
			if (u != n && a[u + 1][v] - 'a' == minVal && !mark[u + 1][v]) {
				mark[u + 1][v] = 1;
				nxt.push_back({u + 1, v});
				trace[u + 1][v] = d;
			}
			if (v != n && a[u][v + 1] - 'a' == minVal && !mark[u][v + 1]) {
				mark[u][v + 1] = 1;
				nxt.push_back({u, v + 1});
				trace[u][v + 1] = d;
			}
		}
		cur = nxt;
	}
	cerr << "heerl?";
	label1:
	for (int i = 0; i < mx; ++i) cout << "a";
	vector <char> res;
	ii now = {n, n};
	while (1) {
		if (trace[now.first][now.second] == ii(0, 0)) break;
		res.push_back(a[now.first][now.second]);
		now = trace[now.first][now.second];
	}
	reverse(res.begin(), res.end());
	for (char d : res) cout << d;

	return 0;
}