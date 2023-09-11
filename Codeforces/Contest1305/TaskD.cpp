#include <bits/stdc++.h>

using namespace std;

const int N = 1005, LOG = 29;
int n, d[N], P[N][LOG], lst;
vector <int> adj[N], chain;

void dfs(int u, int pre) {
	if (~pre) d[u] = d[pre] + 1;
	P[u][0] = pre;
	for (int i = 1; i <= LOG; ++i) if ((1 << i) <= d[u])
		P[u][i] = P[P[u][i - 1]][i - 1];
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
	}
}

int LCA(int u, int v) {
	if (d[u] < d[v]) swap(u, v);
	for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= d[u] - d[v])
		u = P[u][i];
	if (u == v) return u;
	for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= d[u] && P[u][i] != P[v][i])
		u = P[u][i], v = P[v][i];
	return P[u][0];
}

int get(int u, int pre) {
	int p1 = -1;
	for (int v : adj[u]) {
		if (v == pre) continue;
		if (p1 == -1) {
			p1 = v;
		} else {
			cout << "? " << p1 << ' ' << v << endl;
			cout.flush();
			int z; cin >> z;
			if (z != u) {
				lst = z;
				chain.clear();
				chain.push_back(z);
				return get(z, u);
			}
		}
	}
	if (p1 == -1) return -1;
	else {
		chain.push_back(p1);
		return get(p1, u);
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	get(1, -1);
	cout << "? " << chain[0] << ' ' << chain[chain.size() - 1] << endl;
	cout.flush();
	int ans;
	cin >> ans;
	cout << "! " << ans << endl;

	return 0;
}