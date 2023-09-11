#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
#define endl '\n'

const int N = 1e5 + 5;
int n, d[N], maxD[N];
vector <int> adj[N], res, step;

void prepare(int u) {
	for (int v : adj[u]) {
		d[v] = d[u] + 1;
		prepare(v);
		maxD[u] = max(maxD[u], maxD[v] + 1);
	}
}

void dfs(int u) {
	vector <ii> w;
	w.clear();
	for (int v : adj[u]) w.push_back(ii(maxD[v], v));
	sort(w.begin(), w.end());
	int pre = 0;
	res.push_back(u);
	for (ii d : w) {
		while (pre--) {
			step.push_back(d.second);
		}
		dfs(d.second);
		pre = d.first + 1;
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.inp", "r", stdin);
	freopen("TaskF.out", "w", stdout);

	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int j;
		cin >> j;
		j++;
		adj[j].push_back(i);
	}
	prepare(1);
	dfs(1);
	for (int u : res) cout << u - 1 << ' ';
	cout << endl;
	cout << step.size() << endl;
	for (int d : step) cout << d - 1 << ' ';
	cout << endl;

	return 0;
}