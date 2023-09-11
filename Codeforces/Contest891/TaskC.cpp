#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

const int N = 5e5 + 5;
int n, m, ans[N], cur[N];
vector <Edge> EdgeList;
vector <int> E[N], queryW[N], weightE[N], id;

struct dsu_t {
	int n, record;
	vector <int> lab;
	vector <ii> changes;
	dsu_t() {}
	dsu_t(int _n) {
		changes.clear();
		this -> n = _n;
		lab.assign(n + 5, -1);
	}
	int root(int x) {
		if (lab[x] == -1) return x;
		int y = root(lab[x]);
		if (record) changes.push_back(ii(x, lab[x]));
		lab[x] = y;
		return y;
	}
	bool merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return false;
		if (record) changes.push_back(ii(y, lab[y]));
		lab[y] = x;
		return true;
	}
	void rollback() {
		while (!changes.empty()) {
			ii d = changes.back(); changes.pop_back();
			lab[d.first] = d.second;
		}
		record = false;
	}
};

int main(int argc, char const *argv[])
{
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E[w].push_back(EdgeList.size()); 
		EdgeList.push_back(Edge(u, v, w));
	}
	int q; cin >> q;
	for (int i = 1; i <= q; ++i) {
		ans[i] = 1;
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			int e;
			cin >> e; --e;
			weightE[i].push_back(e);
			if (queryW[EdgeList[e].w].empty() || queryW[EdgeList[e].w].back() != i) queryW[EdgeList[e].w].push_back(i);
		}
		sort(weightE[i].begin(), weightE[i].end(), [](int i, int j) {
			return EdgeList[i].w < EdgeList[j].w;
		});
	}
	dsu_t dsu = dsu_t(n);
	for (int i = 1; i <= N - 5; ++i) {
		for (int j : queryW[i]) {
			id.clear();
			while (cur[j] < weightE[j].size() && EdgeList[weightE[j][cur[j]]].w == i) {
				id.push_back(weightE[j][cur[j]]);
				cur[j]++;
			}
			dsu.record = true;
			for (int k : id) {
				if (!dsu.merge(EdgeList[k].u, EdgeList[k].v)) {
					ans[j] = false;
				}
			}
			dsu.rollback();
		}
		for (int j : E[i])
			dsu.merge(EdgeList[j].u, EdgeList[j].v);
	}
	for (int i = 1; i <= q; ++i) {
		if (ans[i]) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}