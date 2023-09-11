#include <bits/stdc++.h>

using namespace std;
#define int long long
#define oo (int)1e9

struct TrieNode {
	int cnt, subSize;
	TrieNode* child[2];
	TrieNode() {
		cnt = subSize = 0;
		for (int i = 0; i < 2; ++i) child[i] = NULL;
	}
};

TrieNode* root;

void addString(string s) {
	TrieNode* p = root;
	for (int i = 0; i < s.size(); ++i) {
		int now = s[i] - '0';
		if (p -> child[now] == NULL)
			p -> child[now] = new TrieNode();
		p = p -> child[now];
	}
	++p->cnt;
}

void dfs(TrieNode* u) {
	for (int i = 0; i < 2; ++i) {
		TrieNode* v = u -> child[i];
		if (v == NULL) continue;
		dfs(v);
		u -> subSize += v -> subSize;
	}
	u -> subSize += u -> cnt;
}

int xorSum;

int Size(TrieNode * u, int d) {
	if (u -> child[d] == NULL) return 0;
	else return u->child[d]->subSize;
}

void find_kth(TrieNode* u, int k, int &ans, int depth, int pre) {
	if (Size(u, 0) == 0 && Size(u, 1) == 0) return;
	if (xorSum & (1 << (31 - depth))) {
		if (Size(u, 1) >= k) {
			ans |= (1 << (31 - depth));
			find_kth(u -> child[1], k, ans, depth + 1, 1);
		} else {
			find_kth(u -> child[0], k - Size(u, 1), ans, depth + 1, 0);
		}
	} else {
		if (Size(u, 0) >= k) {
			find_kth(u -> child[0], k, ans, depth + 1, 0);
		}
		else {
			ans |= (1 << (31 - depth ));
			find_kth(u -> child[1], k - Size(u, 0), ans, depth + 1, 1);
		}
	}
	return;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("VOXOR.INP", "r", stdin);
	freopen("VOXOR.OUT", "w", stdout);

	root = new TrieNode();
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		string s;
		s.clear();
		for (int i = 31; i >= 0; i--) {
			if (a & (1 << i)) s = s + '1';
			else s = s + '0';
		}
		addString(s);
	}
	dfs(root);
	while (q--) {
		string Task;
		cin >> Task;
		if (Task == "XOR") {
			int d;
			cin >> d;
			xorSum ^= d;
		} else {
			int k;
			cin >> k;
			k = n - k + 1;
			int ans = 0;
			find_kth(root, k, ans, 0, 0);
			cout << (ans ^ xorSum) << endl;
		}
	}

	return 0;
}