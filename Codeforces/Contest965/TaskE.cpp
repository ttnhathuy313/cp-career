#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int totNode, n, child[N][26], mark[N], dp[N], subSize[N], h[N];
multiset <int> H;

void addString(string s) {
	int p = 0;
	for (int i = 0; i < s.size(); ++i) {
		int cur = s[i] - 'a';
		if (child[p][cur] == -1) child[p][cur] = ++totNode;
		p = child[p][cur];
	}
	mark[p] = 1;
}

void prepare(int u) {
	for (int cur = 0; cur < 26; ++cur) if (~child[u][cur]) {
		h[child[u][cur]] = h[u] + 1;
		prepare(child[u][cur]);
		subSize[u] += subSize[child[u][cur]];
	}
}

void dfs(int u, bool keep, multiset <int> &H) {
	int maxSize = 0, bigChild = -1;
	for (int cur = 0; cur < 26; ++cur) if (~child[u][cur]) {
		int v = child[u][cur];
		if (subSize[v] > maxSize) {
			maxSize = subSize[v];
			bigChild = v;
		}
	}
	if (~bigChild) dfs(bigChild, 1, H);

	for (int cur = 0; cur < 26; ++cur) if (~child[u][cur]) {
		int v = child[u][cur];
		if (v == bigChild) continue;
		multiset <int> d; d.clear();
		dfs(v, 1, d);
		for (int c : d) H.insert(c);
	}
	if (!mark[u] && u) {
		if (!H.empty()) {
			int mx = *H.rbegin();
			H.erase(H.find(mx));
		}
	}
	H.insert(h[u]);
	if (!keep) H.clear();
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	memset(child, -1, sizeof child);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		addString(s);
	}
	prepare(0);
	dfs(0, 1, H);
	int res = 0;
	for (int v : H) res += v;
	cout << res << endl;

	return 0;
}