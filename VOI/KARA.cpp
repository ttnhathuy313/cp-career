#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, m, totNode = 1, root = 1, dp[N][2];

struct Node {
	int c[2], child[26];
	Node() {
		memset(c, 0, sizeof c);
		memset(child, 0, sizeof child);
	}
} trie[N];

void addString(string s, int pl) {
	int p = root;
	trie[p].c[pl] = 1;
	for (int i = 0; i < s.size(); ++i) {
		int cur = s[i] - 'a';
		if (trie[p].child[cur] == 0)
			trie[p].child[cur] = ++totNode;
		p = trie[p].child[cur];
		trie[p].c[pl] = 1;
	}
	trie[p].c[pl] = 1;
}

void dfs(int u) {
	for (int i = 0; i < 26; ++i) if (trie[u].child[i]) {
		int v = trie[u].child[i];
		dfs(v);
		for (int j = 0; j < 2; ++j) {
			if (!dp[v][j ^ 1] && trie[v].c[j]) dp[u][j] = 1;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("KARA.INP", "r", stdin);
	// freopen("KARA.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		addString(s, 0);
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		string t;
		cin >> t;
		addString(t, 1);
	}
	dfs(1);
	if (dp[1][0]) cout << "Alice" << endl;
	else cout << "Bob" << endl;

	return 0;
}