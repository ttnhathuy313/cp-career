#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int N = 3e5 + 5, oo = 1e18;
int n, m, h[N], P[N];
vector <ii> adj[N];
vector <iii> A;
bool attach[N];

void get(int u, int pre, vector <int> &w) {
	w.push_back(u);
	for (ii v : adj[u]) if (!attach[v.first]) {
		if (v.first == pre) continue;
		get(v.first, u, w);
	}
}

void dfs(int u, int pre) {
	if (u == n) attach[u] = 1;
	for (ii v : adj[u]) {
		if (v.first == pre) continue;
		h[v.first] = h[u] + v.second;
		dfs(v.first, u);
		attach[u] |= attach[v.first];
	}
	if (!attach[u]) return;
	vector <int> w;
	w.clear();
	get(u, pre, w);
	for (int v : w) {
		// cerr << v << ' ' << -2 * h[u] << ' ' << h[v] << endl;
		A.push_back({-2 * h[u], {h[v], v}});
		P[v] = -2 * h[u] + h[v];
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(ii(v, w));
		adj[v].push_back(ii(u, w));
	}
	dfs(1, -1);
	sort(A.begin(), A.end());
	int mx = A[0].first + A[0].second.first, res = -oo;
	set <ii> S;
	S.clear();
	S.insert(ii(mx, A[0].second.second));
	for (int i = 1; i < A.size(); ++i) {
		vector <ii> rollback; rollback.clear();
		for (ii dv : adj[A[i].second.second]) {
			int v = dv.first;
			if (S.find(ii(P[v], v)) != S.end()) {
				S.erase(ii(P[v], v));
				rollback.push_back(ii(P[v], v));
			}
		}
		if (S.size() > 0) {
			// cerr << A[i].second.first << ' ' << (*(S.rbegin())).first << ' ' << A[i].second.first + (*(S.rbegin())).first << endl;
			res = max(res, A[i].second.first + (*(S.rbegin())).first);
		}
		S.insert(ii(A[i].first + A[i].second.first, A[i].second.second));
		for (ii T : rollback) S.insert(T);
	}
	res += h[n];
	for (int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		cout << min(h[n], res + x) << endl;
	}

	return 0;
}