#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int n, deg[N], h[N];
vector <int> adj[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("DIENSO.INP", "r", stdin);
	freopen("DIENSO.OUT", "w", stdout);

	cin >> n;
	string s; cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '<') adj[i].push_back(i + 1);
		else adj[i + 1].push_back(i);
		if (s[i] == '<') deg[i + 1]++;
		else deg[i]++;
	}
	queue <int> dead;
	while (!dead.empty())
		dead.pop();
	for (int i = 1; i <= n + 1; ++i) if (deg[i] == 0)
		dead.push(i);
	while (!dead.empty()) {
		int u = dead.front();
		dead.pop();
		for (int v : adj[u]) {
			deg[v]--;
			h[v] = max(h[v], h[u] + 1);
			if (deg[v] == 0) dead.push(v);
		}
	}
	int res = 0;
	for (int i = 1; i <= n + 1; ++i) {
		res += h[i];
	}
	cout << res << endl;

	return 0;
}