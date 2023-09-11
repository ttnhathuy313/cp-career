#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
	TrieNode* child[26];
	int cnt;
	int val;
	TrieNode() {
		cnt = 0;
		val = 0;
		for (int i = 0; i < 26; ++i) child[i] = NULL;
	}
};

TrieNode* root;

void addString(string s) {
	TrieNode* p = root;
	for (int i = 0; i < s.size(); ++i) {
		int now = s[i] - 'a';
		if (p -> child[now] == NULL) {
			p -> child[now] = new TrieNode();
		}
		p = p -> child[now];
	}
	++p->cnt;
}

bool checkString(string s) {
	TrieNode* p = root;
	for (int i = 0; i < s.size(); ++i) {
		int now = s[i] - 'a';
		if (p -> child[now] == NULL) return false;
		p = p->child[now];
	}
	return (p->cnt > 0);
}

void dfs(TrieNode* u) {
	int mx = 0;
	for (int i = 0; i < 26; ++i) {
		if (u -> child[i] == NULL) continue;
		dfs(u -> child[i]);
		mx = max(mx, u -> child[i] -> val);
	}
	u -> val = mx + (u -> cnt > 0);
}

int m;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("CHAIN2.INP", "r", stdin);
	freopen("CHAIN2.OUT", "w", stdout);

	cin >> m;
	root = new TrieNode();
	for (int i = 1; i <= m; ++i) {
		string s;
		cin >> s;
		addString(s);
	}
	dfs(root);
	cout << (root -> val) << endl;

	return 0;
}