#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 205, oo = 3e18;
string s[N];
int n, a[N], l, id;

struct Matrix {
	int n, m;
	vector <vector <int>> mat;
	Matrix() {}
	Matrix(int _n, int _m) {
		this -> n = _n; this -> m = _m;
		mat.assign(n + 5, vector <int> (m + 5, 0));
	}
} trans;

Matrix operator + (const Matrix &a, const Matrix &b) {
	int n = a.n, m = a.m, p = b.m;
	Matrix ret(n, p);
	ret.mat.assign(n + 5, vector <int> (p + 5, -oo));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= p; ++j) {
			for (int k = 1; k <= m; ++k) {
				ret.mat[i][j] = max(ret.mat[i][j], a.mat[i][k] + b.mat[k][j]);
			}
		}
	}
	return ret;
}

Matrix matExp(Matrix a, int m) {
	m--;
	Matrix ret = a;
	while (m) {
		if (m & 1) ret = ret + a;
		a = a + a;
		m >>= 1;
	}
	return ret;
}

struct TrieNode {
	int val;
	TrieNode* child[26];
	TrieNode* link;
	TrieNode() {
		val = 0;
		for (int i = 0; i < 26; ++i) {
			child[i] = NULL;
		}
	}
};
TrieNode* root;
map <TrieNode*, int> idx;
TrieNode* reflex[N];

void addString(string s, int val) {
	// cerr << "Adding String : " << s << " with value : " << val << endl;
	TrieNode* p = root;
	for (int i = 0; i < s.size(); ++i) {
		int cur = s[i] - 'a';
		if (p -> child[cur] == NULL) {
			p -> child[cur] = new TrieNode();
			idx[p -> child[cur]] = ++id;
			reflex[id] = p -> child[cur];
		}
		p = p -> child[cur];
		// cerr << "	" << idx[p] << endl;
	}
	p -> val += val;
}

void AhoKorasickAutomaton() {
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

void make_Transitive() {
	trans = Matrix(id, id);
	trans.mat.assign(id + 5, vector <int> (id + 5, -oo));

	for (int i = 1; i <= id; ++i) {
		bool isLeaf = true;
		TrieNode* p = reflex[i];
		for (int c = 0; c < 26; ++c) if (p -> child[c] != NULL)
			isLeaf = false;
		if (isLeaf) p = p -> link;
		while (p != NULL) {
			for (int c = 0; c < 26; ++c) if (p -> child[c] != NULL) {
				// cerr << idx[p -> child[c]] << ' ' << i << ' ' << p -> child[c] -> val << endl;
				trans.mat[idx[p -> child[c]]][i] = p -> child[c] -> val;
			}
			if (p -> link == root && p == root) p = NULL;
			else p = p -> link;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	root = new TrieNode();
	id++; idx[root] = id;
	reflex[1] = root; root -> link = root;
	cin >> n >> l;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		addString(s[i], a[i]);
	}
	AhoKorasickAutomaton();
	// for (int i = 1; i <= id; ++i) {
	// 	cerr << "Node " << i << " has value " << reflex[i] -> val << endl;
	// }
	make_Transitive();
	Matrix F(id, 1);
	for (int i = 2; i <= id; ++i) F.mat[i][1] = -oo;
	F.mat[1][1] = 0;
	int res = 0;
	Matrix final = matExp(trans, l) + F;
	for (int i = 1; i <= id; ++i) {
		if (res < final.mat[i][1]) {
			res = max(res, final.mat[i][1]);
		}
		// cerr << "F[" << i << "] : " << final.mat[i][1] << endl;
	}
	cout << res << endl;

	return 0;
}