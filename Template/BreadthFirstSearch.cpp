#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

const int N = 1e5 + 5;
int n, m;
vector <int> adj[N];
int Trace[N];

void BreadthFirstSearch(int x) {
	memset(Trace, 0, sizeof(Trace));
	queue <int> q;
	q.push(x);
	Trace[x] = -1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) if (Trace[v] == 0) q.push(v), Trace[v] = u;
	}
	for (int i = 1; i <= n; ++i) if (i != x) {
		int tmp = i;
		cout << "Path from " << x << " to " << i << " is : " << endl;
		while (Trace[tmp] != -1) {
			cout << tmp << " <- ";
			tmp = Trace[tmp];
		}
		cout << x << endl;
	}
}

int main(int argc, char const *argv[]) {
	freopen("BreadthFirstSearch.inp", "r", stdin);
	freopen("BreadthFirstSearch.out", "w", stdout);
	cin >> n >> m; // n la so dinh, m la so canh
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	BreadthFirstSearch(1); // 1 la dinh bat dau. Muon cai nao bat dau thi thay cai do
	return 0;
}