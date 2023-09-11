#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
	TrieNode* child[26], *link, *exit;
	int val;
	TrieNode() {
		for (int i = 0; i < 26; ++i) child[i] = NULL;
		link = exit = NULL;
		val = 0;
	}
};
TrieNode* root;
void addString(string s, int id) {
	TrieNode* p = root;
	for (int i = 0; i < s.size(); ++i) {
		int cur = s[i] - 'a';
		if (p -> child[cur] == NULL)
			p -> child[cur] = new TrieNode();
		p = p -> child[cur];
	}
	p -> val = id;
}

void AhoKorasick() {
	queue <TrieNode*> q;
	root->link = root;
	root->exit = NULL;
	q.push(root);
	while (!q.empty()) {
		TrieNode* p = q.front();
		q.pop();
		for (int c = 0; c < 26; ++c) if (p->child[c] != NULL) {
			TrieNode* pc = p -> child[c];
			q.push(pc);
			if (p == root) {
				pc -> link = root;
				pc -> exit = NULL;
			} else {
				TrieNode* cur = p -> link;
				bool found = false;
				do {
					if (cur -> child[c] != NULL) {
						found = true;
						break;
					}
					cur = cur -> link;
					if (cur == root && cur -> child[c] != NULL) {
						found = true;
						break;
					}
				} while (cur != root);
				if (!found) {
					pc -> link = root;
					continue;
				}
				pc -> link = cur -> child[c];
				if (cur -> child[c] -> val) pc -> exit = cur -> child[c];
				else pc -> exit = cur -> child[c] -> exit;
			}
		}
	}
}

const int N = 1e5 + 5;
int require[N], n;
string s, t[N];
vector <int> ocr[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	root = new TrieNode();
	cin >> s >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> require[i] >> t[i];
		addString(t[i], i);
	}
	AhoKorasick();
	TrieNode* p = root;
	for (int i = 0; i < s.size(); ++i) {
		int cur = s[i] - 'a';
		if (p -> child[cur] != NULL) {
			p = p -> child[cur];
		} else {
			do {
				p = p -> link;
				if (p -> child[cur] != NULL) break;
			} while (p != root);
			p = (p -> child[cur] == NULL ? root : p -> child[cur]);
		}
		if (p -> val) ocr[p->val].push_back(i + 1);
		TrieNode* q = p -> exit;
		while (q) {
			ocr[q -> val].push_back(i + 1);
			q = q -> exit;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (ocr[i].size() < require[i]) {
			cout << -1 << endl;
			continue;
		}
		int res = s.size();
		for (int j = require[i] - 1; j < ocr[i].size(); ++j) {
			res = min(res, (int)t[i].size() + ocr[i][j] - ocr[i][j - require[i] + 1]);
		}
		cout << res << endl;
	}

	return 0;
}