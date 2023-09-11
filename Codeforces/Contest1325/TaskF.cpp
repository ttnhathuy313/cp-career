#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, m, desire, d[N], color[N];
vector <int> adj[N];
bool mark[N];
stack <int> st;

void dfs(int u) {
	mark[u] = 1;
	st.push(u);
	for (int v : adj[u]) {
		if (!mark[v]) {
			d[v] = d[u] + 1;
			dfs(v);
		} else {
			if (d[u] - d[v] + 1 >= desire) {
				cout << "2\n";
				cout << d[u] - d[v] + 1 << endl;
				while (st.top() != v) {
					cout << st.top() << ' ';
					st.pop();
				}
				cout << v << endl;
				exit(0);
			}
		}
	}
	if (!color[u]) {
		for (int v : adj[u])
			color[v] = 1;
	}
	st.pop();
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	desire = (int)ceil(sqrt(n));	
	dfs(1);
	cout << 1 << endl;
	for (int i = 1; desire; ++i) {
		if (!color[i]) {
			cout << i << ' ';
			desire--;
		}
	}

	return 0;
}