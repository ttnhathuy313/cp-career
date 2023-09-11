#include <bits/stdc++.h>
 
using namespace std;
typedef pair <int, int> ii;
#define int long long
 
const int N = 1e6 + 5, oo = 1e18;
vector <ii> adj[N];
int n, q, s, index[N], w, dist[N], offset;
 
int Left(int x) {return (x << 1);}
int Right(int x) {return (x << 1) + 1;}
 
void build(int id, int L, int R) {
	if (L == R) {
		index[L] = 2 * offset + L;
		adj[id].push_back(ii(index[L], 0));
		adj[index[L]].push_back(ii(id + offset, 0));
		return;
	}
	int mid = (L + R) >> 1;
	adj[id].push_back(ii(Left(id), 0));
	adj[id].push_back(ii(Right(id), 0));
	adj[Left(id) + offset].push_back(ii(id + offset, 0));
	adj[Right(id) + offset].push_back(ii(id + offset, 0));
	build(Left(id), L, mid); build(Right(id), mid + 1, R);
}
 
void addEdge(int id, int L, int R, int i, int j, int k, bool type) {
	if (L > j || R < i) return;
	if (L >= i && R <= j) {
		if (type == 0) {
			adj[index[k]].push_back(ii(id, w));
		} else {
			adj[id + offset].push_back(ii(index[k], w));
		}
		return;
	}
	int mid = (L + R) >> 1;
	addEdge(Left(id), L, mid, i, j, k, type); 
	addEdge(Right(id), mid + 1, R, i, j, k, type);
}
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);
 
	cin >> n >> q >> s;
	offset = 4 * n;
	build(1, 1, n);
	for (int i = 1; i <= q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int u, v;
			cin >> u >> v >> w;
			adj[index[u]].push_back(ii(index[v], w));
		} else if (t == 2) {
			int v, l, r;
			cin >> v >> l >> r >> w;
			addEdge(1, 1, n, l, r, v, 0);
		} else if (t == 3) {
			int v, l, r;
			cin >> v >> l >> r >> w;
			addEdge(1, 1, n, l, r, v, 1);
		}
	}
	priority_queue <ii, vector <ii>, greater <ii> > pq;
	while (!pq.empty()) pq.pop();
	pq.push(ii(0, index[s]));
	for (int i = 1; i <= 9 * n; ++i) dist[i] = oo;
	dist[index[s]] = 0;
	while (!pq.empty()) {
		int u = pq.top().second, d = pq.top().first;
		pq.pop();
		if (d > dist[u]) continue;
		for (ii v : adj[u]) {
			if (dist[v.first] > d + v.second) {
				dist[v.first] = d + v.second;
				pq.push(ii(d + v.second, v.first));
			}
		}	
	}
	for (int i = 1; i <= n; ++i) {
		if (dist[index[i]] == oo) cout << -1 << ' ';
		else cout << dist[index[i]] << ' ';
	}
 
	return 0;
}