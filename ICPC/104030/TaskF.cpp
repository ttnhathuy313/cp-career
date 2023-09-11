#include <bits/stdc++.h>

using namespace std;

const int N = 505, M = 1e6 + 5;
int n, best[N], root = 1, totNode = 1, child[M][26], pass[M];
string s[N][N];

void clearTree() {
	for (int i = 0; i < 26; ++i) {
		child[root][i] = 0;
	}
}

void addString(string t) {
	int p = root;
	for (int i = 0; i < t.size(); ++i) {
		int cur = t[i] - 'a';
		if (!child[p][cur]) {
			child[p][cur] = ++totNode;
		}
		p = child[p][cur];
		pass[p]++;
	}
}

void clearString(string t) {
	int p = root;
	for (int i = 0; i < t.size(); ++i) {
		int cur = t[i] - 'a';
		if (!child[p][cur]) {
			child[p][cur] = ++totNode;
		}
		p = child[p][cur];
		pass[p] = 0;
	}
}

void checkString(string t, int id) {
	int p = root;
	for (int i = 0; i < t.size(); ++i) {
		int cur = t[i] - 'a';
		if (pass[child[p][cur]] != n - 1) {
			return;
		}
		best[id]++;
		p = child[p][cur];
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> s[i][j];
		}
	}
	if (n == 2) {
		if (s[1][2].size() != s[2][1].size()) {
			cout << "NONE" << endl;
			return 0;
		}
		string s1 = s[1][2], s2 = s[2][1];
		
	}
	for (int i = 1; i <= n; ++i) {
		int lst = -1;
		for (int j = 1; j <= n; ++j) if (i != j) {
			addString(s[i][j]);
			lst = j;
		}
		checkString(s[i][lst], i);
		if (best[i] == 0) {
			cout << "NONE" << endl;
			return 0;
		}
		for (int j = 1; j <= n; ++j) if (i != j) {
			clearString(s[i][j]);
		}
	}

	for (int i = 1; i <= n; ++i) {
		bool ok = true;
		for (int j = 1; j <= n; ++j) if (i != j) {
			int sz = s[i][j].size();
			if (best[i] - max(2, sz - best[j] + 1) + 1 > 1 || best[i] + best[j] < sz) {
				ok = false;
				cout << "MANY" << endl;
				return 0;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) if (i != j) {
			int sz = s[i][j].size();
			if (sz == 2) {
				best[i] = best[j] = 1;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) if (i != j) {
			for (int k = best[i]; k < s[i][j].size(); ++k) {
				if (s[i][j][k] != s[j][j == 1 ? 2 : 1][k - best[i]]) {
					cout << "NONE" << endl;
					return 0;
				}
			}
		}
	}

	cout << "UNIQUE" << endl;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < best[i]; ++j) {
			cout << s[i][(i == 1 ? 2 : 1)][j];
		}
		cout << endl;
	}

	return 0;
}