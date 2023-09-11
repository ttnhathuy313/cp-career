#include <bits/stdc++.h>
 
using namespace std;
typedef pair <int, int> ii;
 
const int N = 1e5 + 5;
int n, value[N], tot, dfsTime;
string s[N];
vector <ii> A;

struct TrieNode {
	TrieNode* nxt[26];
	vector <int> val;
	TrieNode() {
		val.clear();
		for (int i = 0; i < 26; ++i)
			nxt[i] = NULL;
	}
};

TrieNode* root;
 
void add(string t, int id) {
	TrieNode* cur = root;
	for (int i = 0; i < t.size(); ++i) {
		int v = t[i] - 'a';
		if (cur->nxt[v] == NULL) {
			cur -> nxt[v] = new TrieNode();
		}
		cur = cur -> nxt[v];
	}
	cur -> val.push_back(id);
}
 
void dfs1(TrieNode* cur) {
	if (cur->val.size() > 0) {
		dfsTime++;
		for (int v : cur->val) {
			value[v] = dfsTime;
		}
	}
	for (int i = 0; i < 26; ++i) {
		if (cur -> nxt[i])
			dfs1(cur -> nxt[i]);
	}
}
 
void dfs2(TrieNode* cur) {
	for (int v : cur -> val) {
		bool ok = false;
		for (char c : s[v]) if (c == 'm')
			ok = true;
		A.push_back({value[v], ok});
	}
	for (int i = 0; i < 26; ++i) {
		if (cur -> nxt[i])
			dfs2(cur -> nxt[i]);
	}
}
 
int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e5;
    vector<int> d(n+1, INF);
    d[0] = -INF;
 
    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }
 
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}
 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		value[i] = -1;
	}
	root = new TrieNode();
	for (int i = 1; i <= n; ++i) {
		reverse(s[i].begin(), s[i].end());
		add(s[i], i);
		reverse(s[i].begin(), s[i].end());
	}
	dfsTime = 0;
	dfs1(root);
	root = new TrieNode();
	tot = 1;
	for (int i = 1; i <= n; ++i) {
		add(s[i], i);
	}
	A.clear();
	dfs2(root);
	cout << lis(A) << endl;
}
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskI.INP", "r", stdin);
	freopen("TaskI.OUT", "w", stdout);
 
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
 
	return 0;
}