#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
	int cnt;
	TrieNode* child[26];
	TrieNode() {
		cnt = 0;
		for (int i = 0; i < 26; ++i) child[i] = NULL;
	}
};

TrieNode* root;

void addString(string a) {
	TrieNode* p = root;
	for (int i = 0; i < a.size(); ++i) {
		int now = a[i] - 'a';
		if (p -> child[now] == NULL)
			p -> child[now] = new TrieNode();
		p = p -> child[now];
	}
	++p->cnt;
}

bool checkString(string s) {
	TrieNode* p = root;
	for (int i = 0; i < s.size(); ++i) {
		int now = s[i] - 'a';
		if (p -> child[now] == NULL)
			return false;
		p = p->child[now];
	}
	return (p->cnt > 0);
}

const int N = 3e5 + 5, MOD = 1337377;
int dp[N];

void add(int &a, int b) {
	a = (a + b) % MOD;
	return; 
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("NKSEV.INP", "r", stdin);
	freopen("NKSEV.OUT", "w", stdout);

	root = new TrieNode();
	string s;
	cin >> s;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string t;
		cin >> t;
		reverse(t.begin(), t.end());
		addString(t);
	}
	n = s.size();
	s = ' ' + s;
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		TrieNode* p = root;
		for (int j = i; j >= max(i - 99, 1); --j) {
			int now = s[j] - 'a';
			if (p -> child[now] == NULL) break;
			p = p -> child[now];
			if (p -> cnt > 0) add(dp[i], dp[j - 1]);
		}
	}
	cout << dp[n] << endl;

	return 0;
}