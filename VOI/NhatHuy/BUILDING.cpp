#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

struct Point {
	int x, y;
	Point() {}
	Point(int _x, int _y) : x(_x), y(_y) {}
};

struct Rect{
	Point a, b, c, d;
};

struct object {
	int c, l, r, id;
	object() {}
	object(int _y, int _l, int _r, int _id) : c(_y), l(_l), r(_r), id(_id) {}
}; 

bool operator<(const object a, const object b) {
	return a.c < b.c;
}

const int N = 1e5 + 5;
Rect A[N];
int n, dfsTime, low[N], tin[N], biComp[N], biCount, dp[N], res = N, sz[N];
vector <int> adj[N], Tadj[N];
stack <int> S;
bool mark[N];

void dfs(int u, int pre) {
	S.push(u);
	low[u] = tin[u] = ++dfsTime;
	mark[u] = 1;
	for (int k = 0; k < (int)adj[u].size(); ++k) {
		int v = adj[u][k];
		if (v == pre) continue;
		if (!mark[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else low[u] = min(low[u], tin[v]);
	}
	if (low[u] == tin[u]) {
		biCount++;
		while (S.top() != u) {
			int v = S.top();
			S.pop();
			biComp[v] = biCount;
			sz[biCount]++;
		}
		S.pop();
		sz[biCount]++;
		biComp[u] = biCount;
	}
}

void calc(int u, int pre, int root) {
	dp[u] = sz[u];
	mark[u] = 1;
	for (int k = 0; k < (int)Tadj[u].size(); ++k) {
		int v = Tadj[u][k];
		if (v == pre) continue;
		calc(v, u, root);
		dp[u] += dp[v];
	}
}

void update(int u, int pre, int root) {
	if (pre != -1) {
		res = min(res, abs(dp[root] - 2 * dp[u]));
	}
	for (int k = 0; k < (int)Tadj[u].size(); ++k) {
		int v = Tadj[u][k];
		if (v == pre) continue;
		update(v, u, root);
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("BUILDING.INP", "r", stdin);
	freopen("BUILDING.OUT", "w", stdout);

	cin >> n;
	vector <object> dy; dy.clear();
	vector <object> dx; dx.clear();
	for (int i = 1; i <= n; ++i) {
		cin >> A[i].a.x >> A[i].a.y >> A[i].c.x >> A[i].c.y;
		A[i].b.x = A[i].c.x, A[i].b.y = A[i].a.y;
		A[i].d.x = A[i].a.x, A[i].d.y = A[i].c.y;
		dy.push_back(object(A[i].a.x, A[i].d.y, A[i].a.y, i));
		dy.push_back(object(A[i].c.x, A[i].d.y, A[i].a.y, i));
		dx.push_back(object(A[i].a.y, A[i].a.x, A[i].c.x, i));
		dx.push_back(object(A[i].c.y, A[i].a.x, A[i].c.x, i));
	}

	//graph processing

	sort(dy.begin(), dy.end());
	dy.push_back(object(-2, 2, 2, 2));
	vector <iii> w; w.clear();
	for (int k = 0; k < (int)dy.size(); ++k) {
		if (k != 0 && dy[k].c != dy[k - 1].c) {
			sort(w.begin(), w.end());
			set <int> avail;
			avail.clear();
			for (int p = 0; p < (int)w.size(); ++p) {
				iii cur = w[p];
				int type = cur.second.first, u = cur.second.second;
				if (type == -1) {
					for (set <int>::iterator it = avail.begin(); it != avail.end(); ++it) {
						int x = *(it);
						if (x == u) continue;
						adj[u].push_back(x);
						adj[x].push_back(u);
					}
					avail.erase(u);
				} else avail.insert(u);
			}
			w.clear();
		}
		w.push_back(iii(dy[k].l, ii(1, dy[k].id)));
		w.push_back(iii(dy[k].r, ii(-1, dy[k].id)));
	}
	sort(dx.begin(), dx.end());
	dx.push_back(object(-2, 2, 2, 2));
	w.clear();
	for (int k = 0; k < (int)dx.size(); ++k) {
		if (k != 0 && dx[k].c != dx[k - 1].c) {
			sort(w.begin(), w.end());
			set <int> avail;
			avail.clear();
			for (int p = 0; p < (int)w.size(); ++p) {
				iii cur = w[p];
				int type = cur.second.first, u = cur.second.second;
				if (type == -1) {
					for (set <int>::iterator it = avail.begin(); it != avail.end(); ++it) {
						int x = *(it);
						if (x == u) continue;
						adj[u].push_back(x);
						adj[x].push_back(u);
					}
					avail.erase(u);
				} else avail.insert(u);
			}
			w.clear();
		}
		w.push_back(iii(dx[k].l, ii(1, dx[k].id)));
		w.push_back(iii(dx[k].r, ii(-1, dx[k].id)));
	}

	//end graph processing

	for (int i = 1; i <= n; ++i) if (!mark[i]) {
		dfs(i, -1);
	}
	if (biCount == 1) {
		cout << -1 << endl;
		return 0;
	}
	set <ii> S;
	S.clear();
	for (int i = 1; i <= n; ++i) {
		for (int k = 0; k < (int)adj[i].size(); ++k) {
			int j = adj[i][k];
			if (biComp[i] == biComp[j]) continue;
			int u = biComp[i], v = biComp[j];
			if (u > v) swap(u, v);
			if (S.find(ii(u, v)) == S.end()) {
				S.insert(ii(u, v));
				Tadj[u].push_back(v);
				Tadj[v].push_back(u);
			}
		}
	}
	memset(mark, 0, sizeof mark);
	for (int i = 1; i <= biCount; ++i) if (!mark[i]) {
		calc(i, -1, i);
		update(i, -1, i);
	}
	cout << res << endl;

	return 0;
}