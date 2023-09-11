#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, m;
vector <int> adj[N];
set <ii> alive;
bool mark[N];

struct obj {
	int a, b, c;
};

vector <obj> res;

void dfs(int u, int par) {
	mark[u] = 1;
	for (int v : adj[u]) if (!mark[v]) {
		dfs(v, u);
	}
	int pre = -1, cnt = 0;
	for (int v : adj[u]) if (alive.find({u, v}) != alive.end() && par != v) {
		++cnt;
		alive.erase({u, v});
		alive.erase({v, u});
		if (~pre) {
			res.push_back({pre, u, v});
			pre = -1;
		} else pre = v;
	}
	// cerr << u << " : " << cnt << endl;
	if (~pre && ~par) {
		res.push_back({pre, u, par});
		alive.erase({u, par});
		alive.erase({par, u});
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m;
	if (m & 1) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		alive.insert({u, v});
		alive.insert({v, u});
	}
	for (int i = 1; i <= n; ++i) if (!mark[i]) 
		dfs(i, -1);
	for (obj D : res) {
		cout << D.b << ' ' << D.a << endl;
		cout << D.b << ' ' << D.c << endl;
	}

	return 0;
}
