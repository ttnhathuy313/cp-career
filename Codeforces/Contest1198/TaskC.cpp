#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, m;
bool mark[N];
vector <ii> adj[N];

void solve() {
	cin >> n >> m;
	n *= 3;
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
		mark[i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	vector <int> res; res.clear();
	for (int i = 1; i <= n; ++i) if (!mark[i]) {
		ii j(0, 0);
		for (ii v : adj[i]) if (!mark[v.first]) {
			j = {v.first, v.second};
			break;
		}
		if (j.first == 0) continue;
		mark[i] = 1;
		mark[j.first] = 1;
		res.push_back(j.second); 
	}
	if (res.size() >= n / 3) {
		cout << "Matching" << endl;
		for (int i = 0; i < n / 3; ++i) cout << res[i] << ' '; cout << endl;
	} else {
		cout << "IndSet" << endl;
		int cur = 0;
		for (int i = 1; i <= n; ++i) if (!mark[i]) {
			cout << i << ' ';
			cur++;
			if (cur == n / 3) break;
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}