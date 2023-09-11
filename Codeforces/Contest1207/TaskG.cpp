#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair <int, int> ii;

const int N = 4e5 + 5;
int n, ch[N], link[N], child[N][26], m, lastid[N], totNode, res[N], tin[N], tout[N], dfsTime;
vector <int> associate[N], adj[N];
vector <ii> question[N];
bool mark[N];

struct FenwickTree {
	int n;
	vector <int> F;
	FenwickTree() {}
	FenwickTree(int _n) {
		this -> n = _n;
		F.assign(n + 5, 0);
	}
	void add(int i, int x) {
		if (i == 0) return;
		while (i <= n) {
			F[i] += x;
			i += (i & -i);
		}
	}
	int get(int i) {
		if (i == 0) return 0;
		int res = 0;
		while (i) {
			res += F[i];
			i -= (i & -i);
		}
		return res;
	}
} fw; // Zero index! be careful

void addString(string s, int id, int k) { // Add string t to AhoKorasick Automaton
	int p = 0;
	for (int i = 0; i < s.size(); ++i) {
		int cur = s[i] - 'a';
		if (child[p][cur] == -1) child[p][cur] = ++totNode;
		p = child[p][cur];
	}
	question[id].push_back({p, k}); // Pair of (tail of string, query index)
}

void AhoKorasick() { // Build suffix link for Aho Korasick Automaton
	queue <int> q;
	link[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < 26; ++i) if (~child[u][i]) {
			int v = child[u][i];
			q.push(v);
			if (u == 0) {
				link[v] = 0;
				continue;
			}
			int cur = link[u];
			if (~child[cur][i]) {
				link[v] = child[cur][i];
				continue;
			}
			do {
				cur = link[cur];
				if (~child[cur][i]) break;
			} while (cur);
			link[v] = max(0, child[cur][i]);
		}
	}
	// The suffix links form a tree rooted at 0
	for (int i = 1; i <= totNode; ++i) {
		adj[link[i]].push_back(i);
		// cerr << i << ' ' << link[i] << endl;
	}
}

void tour(int u) {
	tin[u] = ++dfsTime;
	for (int v : adj[u]) tour(v);
	tout[u] = ++dfsTime;
}

int nxtState(int u, int nxt) {
	if (~child[u][nxt]) return child[u][nxt];
	else {
		if (u == 0) return 0;
		return child[u][nxt] = nxtState(link[u], nxt);
	}
}

void solve(int u, int curPointer) {
	mark[u] = 1;
	// cerr << "Solving at " << u << " with pointer address : " << curPointer << endl;
	curPointer = nxtState(curPointer, ch[u]);
	fw.add(tin[curPointer], 1); // go in
	for (ii pack : question[u]) {
		int id = pack.second, k = pack.first;
		res[id] = fw.get(tout[k]) - fw.get(tin[k] - 1); // get subtree sum
	}
	for (int v : associate[u]) {
		solve(v, curPointer);
	}
	fw.add(tin[curPointer], -1); // go out
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	memset(link, -1, sizeof link);
	memset(child, -1, sizeof child);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int type;
		cin >> type;
		if (type == 1) {
			char c; cin >> c;
			ch[i] = c - 'a';
		} else {
			int j; cin >> j;
			associate[j].push_back(i);
			char c; cin >> c;
			ch[i] = c - 'a';
		}
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		int id;
		string t;
		cin >> id >> t;
		addString(t, id, i);
	}
	// cerr << "Add done!" << endl;
	AhoKorasick();
	// cerr << "Done AhoKorasick" << endl;
	tour(0);
	// cerr << "Tour Done" << endl;
	fw = FenwickTree(totNode * 2);
	for (int i = 1; i <= n; ++i) if (!mark[i]) {
		solve(i, 0);
	}
	for (int i = 1; i <= m; ++i)
		cout << res[i] << endl;

	return 0;
}