#include <bits/stdc++.h>

using namespace std;
#define int long long

struct TrieNode {
	TrieNode* link;
	TrieNode* child[26];
	int val;
	TrieNode() {
		val = 0;
		link = NULL;
		for (int i = 0; i < 26; ++i)
			child[i] = NULL;
	}
};

TrieNode* root1, *root2;

void addString(string s, TrieNode* root) {
	TrieNode* p = root;
	for (int i = 0; i < s.size(); ++i) {
		int cur = s[i] - 'a';
		if (p -> child[cur] == NULL)
			p -> child[cur] = new TrieNode();
		p = p -> child[cur];
	}
	p -> val++;
}

void initSuffixLink(TrieNode* root) {
	queue <TrieNode*> q;
	while (!q.empty()) q.pop();
	q.push(root);
	while (!q.empty()) {
		TrieNode* p = q.front(); q.pop();
		for (int cur = 0; cur < 26; ++cur) if (p -> child[cur] != NULL) {
			TrieNode* t = p -> link;
			while (1) {
				if (t == root) {
					if (t -> child[cur] != NULL && p != root) t = t -> child[cur];
					break;
				}
				if (t -> child[cur] != NULL) {
					t = t -> child[cur];
					break;
				}
				t = t -> link;
			}
			p -> child[cur] -> link = t;
			p -> child[cur] -> val += t -> val;
			q.push(p -> child[cur]);
		}
	}
}

const int N = 2e5 + 5;
int pref[N], suffix[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);

	root1 = new TrieNode();
	root1 -> link = root1;
	root2 = new TrieNode();
	root2 -> link = root2;
	string t;
	cin >> t;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		addString(s, root1);
		reverse(s.begin(), s.end());
		addString(s, root2);
	}
	initSuffixLink(root1);
	initSuffixLink(root2);
	TrieNode* p = root1;
	for (int i = 0; i < t.size(); ++i) {
		TrieNode* q = p;
		int cur = t[i] - 'a';
		while (1) {
			if (q -> child[cur] != NULL) {
				q = q -> child[cur];
				break;
			}
			if (q == root1) break;
			q = q -> link;
		}
		p = q;
		pref[i] = p -> val;
	}
	reverse(t.begin(), t.end());
	p = root2;
	for (int i = 0; i < t.size(); ++i) {
		TrieNode* q = p;
		int cur = t[i] - 'a';
		while (1) {
			if (q -> child[cur] != NULL) {
				q = q -> child[cur];
				break;
			}
			if (q == root2) break;
			q = q -> link;
		}
		p = q;
		int id = (int)t.size() - i;
		suffix[id] = p -> val;

	}
	int res = 0;
	for (int i = 1; i < t.size(); ++i) {
		// cerr << "At " << i << " : " << pref[i] << ' ' << suffix[i + 1] << endl;
		res += pref[i - 1] * suffix[i + 1];
	}
	cout << res << endl;

	return 0;
}