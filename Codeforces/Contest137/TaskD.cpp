#include <bits/stdc++.h>

using namespace std;

const int N = 505, oo = 1e9;
int dp[N][N], cost[N][N], trace[N][N];

string make(string t) {
	int n = t.size();
	for (int i = 0; i < n; ++i) {
		if (t[i] != t[n - i - 1]) t[i] = t[n - i - 1];
	}
	return t;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	string s;
	int k, n;
	cin >> s >> k;
	n = s.size();
	s = ' ' + s;
	for (int i = 0; i <= n; ++i) for (int j = 0; j <= n; ++j) dp[i][j] = oo;
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			cost[i][j] = 0;
			for (int k = i; k <= j; ++k) if (s[k] != s[j - k + i]) cost[i][j]++;
			cost[i][j] >>= 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			for (int t = 0; t < i; ++t) {
				if (dp[t][j - 1] + cost[t + 1][i] < dp[i][j]) {
					dp[i][j] = dp[t][j - 1] + cost[t + 1][i];
					trace[i][j] = t;
				}
			}
		}
	}
	int val = oo;
	int K = k;
	for (int i = 1; i <= K; ++i) if (dp[n][i] < val) {
		k = i;
		val = dp[n][i];
	}
	cout << dp[n][k] << endl;
	vector <int> id; id.clear();
	id.push_back(n);
	while (k) {
		n = trace[n][k];
		k--;
		id.push_back(n);
	}
	reverse(id.begin(), id.end());
	for (int i = 0; i < id.size() - 1; ++i) {
		// cerr << id[i] + 1 << ' ' << id[i + 1] << ' ' << s.substr(id[i] + 1, id[i + 1] - id[i]) << endl;
		cout << make(s.substr(id[i] + 1, id[i + 1] - id[i]));
		if (i != id.size() - 2) cout << "+";
	}

	return 0;
}