#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5, oo = 1e9;
int dp[N][105][2], n, p, m, id[N], k, subSize[N];
bool fplus;
vector <int> adj[N];
stack <int> st, op;

void dfs(int u) {
	int l = adj[u][0], r = adj[u][1];
	if (l < 0 && r < 0) {
		subSize[u] = 1;
		dp[u][1][1] = dp[u][1][0] = -l-r;
		dp[u][0][0] = dp[u][0][1] = -l+r;
	} else if (l > 0 && r > 0) {
		dfs(l); dfs(r);
		subSize[u] += subSize[l] + subSize[r] + 1;
		for (int i = 0; i <= min(k, subSize[u]); ++i) {
			for (int j = 0; j <= min(i, subSize[l]); ++j) {
				dp[u][i][1] = max(dp[u][i][1], dp[l][j][1] - dp[r][i - j][0]);
				if (i != j) dp[u][i][1] = max(dp[u][i][1], dp[l][j][1] + dp[r][i - 1 - j][1]);
				dp[u][i][0] = min(dp[u][i][0], dp[l][j][0] - dp[r][i - j][1]);
				if (i != j) dp[u][i][0] = min(dp[u][i][0], dp[l][j][0] + dp[r][i - j - 1][0]);
			}
		}
	} else if (r > 0) {
		dfs(r);
		subSize[u] += subSize[r] + 1;
		for (int i = 0; i <= min(subSize[u], k); ++i) {
			dp[u][i][1] = -l - dp[r][i][0];
			if (i > 0) dp[u][i][1] = max(dp[u][i][1], -l + dp[r][i - 1][1]);
			dp[u][i][0] = -l - dp[r][i][1];
			if (i > 0) dp[u][i][0] = min(dp[u][i][0], -l + dp[r][i - 1][0]);
		}
	} else if (l > 0) {
		dfs(l);
		subSize[u] += subSize[l] + 1;
		for (int i = 0; i <= min(subSize[u], k); ++i) {
			dp[u][i][0] = dp[l][i][0] + r;
			dp[u][i][1] = dp[l][i][1] + r;
			if (i > 0) dp[u][i][1] = max(dp[u][i][1], dp[l][i - 1][1] - r);
			if (i > 0) dp[u][i][0] = min(dp[u][i][0], dp[l][i - 1][0] - r);
		}

	}
}

void dfs2(int u) {
	int l = adj[u][0], r = adj[u][1];
	if (l < 0 && r < 0) {
		subSize[u] = 1;
		dp[u][1][1] = dp[u][1][0] = -l + r;
		dp[u][0][0] = dp[u][0][1] = -l - r;
	} else if (l > 0 && r > 0) {
		dfs2(l); dfs2(r);
		subSize[u] += subSize[l] + subSize[r] + 1;
		for (int i = 0; i <= min(k, subSize[u]); ++i) {
			for (int j = 0; j <= min(i, subSize[l]); ++j) {
				dp[u][i][1] = max(dp[u][i][1], dp[l][j][1] + dp[r][i - j][1]);
				if (i != j) dp[u][i][1] = max(dp[u][i][1], dp[l][j][1] - dp[r][i - 1 - j][0]);
				dp[u][i][0] = min(dp[u][i][0], dp[l][j][0] + dp[r][i - j][0]);
				if (i != j) dp[u][i][0] = min(dp[u][i][0], dp[l][j][0] - dp[r][i - j - 1][1]);
			}
		}
	} else if (r > 0) {
		dfs2(r);
		subSize[u] += subSize[r] + 1;
		for (int i = 0; i <= min(subSize[u], k); ++i) {
			dp[u][i][1] = -l + dp[r][i][1];
			if (i > 0) dp[u][i][1] = max(dp[u][i][1], -l - dp[r][i - 1][0]);
			dp[u][i][0] = -l + dp[r][i][0];
			if (i > 0) dp[u][i][0] = min(dp[u][i][0], -l - dp[r][i - 1][1]);
		}
	} else if (l > 0) {
		dfs2(l);
		subSize[u] += subSize[l] + 1;
		for (int i = 0; i <= min(subSize[u], k); ++i) {
			dp[u][i][0] = dp[l][i][0] - r;
			dp[u][i][1] = dp[l][i][1] - r;
			if (i > 0) dp[u][i][1] = max(dp[u][i][1], dp[l][i - 1][1] + r);
			if (i > 0) dp[u][i][0] = min(dp[u][i][0], dp[l][i - 1][0] + r);
		}

	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	string s;
	cin >> s >> p >> m;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '?') {
			st.push(++n);
		} else if (s[i] == '(') {
			op.push(i);
		} else if (s[i] == ')') {
			id[i] = st.top();
			st.pop();
			id[op.top()] = id[i];
			op.pop();
		}
	}
	n = 0;
	for (int i = 1; i < s.size(); ++i) if (s[i] == '?') {
		++n;
		if (s[i - 1] >= '0' && s[i - 1] <= '9') adj[n].push_back(-(s[i - 1] - '0'));
		else adj[n].push_back(id[i - 1]);
		if (s[i + 1] >= '0' && s[i + 1] <= '9') adj[n].push_back(-(s[i + 1] - '0'));
		else adj[n].push_back(id[i + 1]);
	}
	if (n == 0) {
		cout << s << endl;
		return 0;
	}
	k = min(p, m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[i][j][0] = oo;
			dp[i][j][1] = -oo;
		}
	}
	if (p < m) fplus = true;
	if (fplus) {
		dfs(id[0]);
		cout << dp[id[0]][p][1] << endl;
	} else {
		dfs2(id[0]);
		cout << dp[id[0]][m][1] << endl;
	}

	return 0;
}