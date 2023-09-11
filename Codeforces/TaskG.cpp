#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int n, m, child[N][26], dp[N], subSize[N], par[N], c[N];
bool special[N];
multiset <int> S;

void dfs1(int u) {
	subSize[u] += special[u];
	for (int i = 0; i < 26; ++i) if (~child[u][i]) {
		dfs1(child[u][i]);
		par[child[u][i]] = u;
		subSize[u] += subSize[child[u][i]];
	}
}

void dfs2(int u, int cur) {
	if (special[u]) {
		int v = *(S.rbegin());
		dp[u] = v + cur + 1;
		dp[u] = max(dp[u], dp[par[u]] + 1);
	} else dp[u] = dp[par[u]] + 1;
	S.insert(dp[u] - cur);
	int pre = dp[u] - cur;
	for (int i = 0; i < 26; ++i) if (~child[u][i]) {
		int v = child[u][i];
		dfs2(v, cur);
		cur += subSize[v];
	}
	S.erase(S.find(pre));
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	memset(child, -1, sizeof child);
	cin >> n;
	for (int i = 1; i <= n;  ++i) {
		int p; char c;
		cin >> p >> c;
		child[p][c - 'a'] = i;
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		int k;
		cin >> k;
		special[k] = 1;
		c[i] = k;
	}
	for (int i = 1; i <= m; ++i)
		cout << dp[c[i]] << ' ';

	return 0;
}