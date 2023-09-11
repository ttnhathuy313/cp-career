#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5, oo = 1e18;
int dist[N], n, d[N], m, truyVan, tail[N];
struct Edge {
	int u, v, c, trace;
} E[N];
priority_queue <ii, vector <ii>, greater <ii>> pq;
queue <int> q[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m >> truyVan;
	memset(tail, -1, sizeof tail);
	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		E[i] = {u, v, c, tail[u]};
		tail[u] = i;
	}
	for (int i = 2; i <= n; ++i)
		dist[i] = oo;
	pq.push({0, 1});
	while (!pq.empty()) {
		int u = pq.top().second, d = pq.top().first;
		pq.pop();
		if (d > dist[u]) continue;
		for (int i = tail[u]; ~i; i = E[i].trace) {
			int v = E[i].v, w = E[i].c;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
	while (truyVan--) {
		int type, c;
		cin >> type >> c;
		if (type == 1) {
			cout << (dist[c] == oo? -1 : dist[c]) << endl;
		} else {
			for (int i = 1; i <= c; ++i) {
				int l;
				cin >> l;
				E[l].c++;
			}
			for (int i = 2; i <= n; ++i)
				d[i] = oo;
			q[0].push(1);
			int mx = 0;
			for (int i = 0; i <= mx; ++i) {
				while (!q[i].empty()) {
					int u = q[i].front();
					q[i].pop();
					if (d[u] < i) continue;
					for (int i = tail[u]; ~i; i = E[i].trace) {
						int v = E[i].v, w = E[i].c, newD = d[u] + dist[u] + w - dist[v];
						if (newD < d[v]) {
							d[v] = newD;
							if (newD <= min(n - 2, c)) {
								q[newD].push(v);
								mx = max(mx, newD);
							}
						}
					}
				}
			}
			for (int i = 1; i <= n; ++i)
				dist[i] = min(dist[i] + d[i], oo);
		}
	}

	return 0;
}