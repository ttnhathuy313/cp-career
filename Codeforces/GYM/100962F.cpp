#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair <int, int> ii;

const int N = 1e5 + 5, LOG = 22;
int n, q, r_val[N * 3], ans[N], P[N][LOG], d[N], tin[N], tout[N], E[N], dfsTime, blockSize, cnt[2 * N], s[N], L, R, exist[N];
vector <ii> adj[N];
map <int, int> compress;
vector <int> A, euler;
ii Q[N];

void calc(int u, int pre) {
	tin[u] = ++dfsTime;
	euler.push_back(u);
	if (~pre) d[u] = d[pre] + 1;
	P[u][0] = pre;
	for (int i = 1; i <= LOG; ++i) if ((1 << i) <= d[u]) 
		P[u][i] = P[P[u][i - 1]][i - 1];
	for (ii v : adj[u]) {
		if (v.first == pre) continue;
		E[v.first] = v.second;
		calc(v.first, u);
	}
	tout[u] = ++dfsTime;
	euler.push_back(u);
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

struct Query {
	int l, r, id, lwb;
};
vector <Query> QList;

bool operator < (const Query a, const Query b) {
	if (a.l / blockSize != b.l / blockSize) return a.l < b.l;
	else {
		if ((a.l / blockSize) & 1) return a.r < b.r;
		else return a.r > b.r;
	}
}

void ins(int m) {
	int bl = m / blockSize;
	cnt[m]++;
	if (cnt[m] == 1) s[bl]++;
}

void del(int m) {
	int bl = m / blockSize;
	cnt[m]--;
	if (cnt[m] == 0) s[bl]--;
}

int calc_mex(int lwb) {
	int bl = lwb / blockSize;
	for (int i = bl; i <= N; ++i) if (s[i] != blockSize) {
		for (int j = i * blockSize; j < blockSize * (i + 1); ++j) 
			if (cnt[j] == 0 && j >= lwb) return j;
	}
}

void solve() {
	L = 1, R = 2 * n;
	sort(QList.begin(), QList.end());
	for (Query P : QList) {
		int l = P.l, r = P.r;
		while (L < l) {
			exist[euler[L]]--;
			if (exist[euler[L]] == 0) del(E[euler[L]]);
			else ins(E[euler[L]]);
			L++;
		}
		while (L > l) {
			L--;
			exist[euler[L]]++;
			if (exist[euler[L]] == 1) ins(E[euler[L]]);
			else del(E[euler[L]]);
		}
		while (R > r) {
			exist[euler[R]]--;
			if (exist[euler[R]] == 0) del(E[euler[R]]);
			else ins(E[euler[R]]);
			R--;
		}
		while (R < r) {
			R++;
			exist[euler[R]]++;
			if (exist[euler[R]] == 1) ins(E[euler[R]]);
			else del(E[euler[R]]);
		}
		ans[P.id] = calc_mex(P.lwb);
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("100962F.INP", "r", stdin);
	freopen("100962F.OUT", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		A.push_back(w);
	}
	A.push_back(0);
	int pre = -1, id = 0;
	sort(A.begin(), A.end());
	for (int d : A) {
		if (pre == -1) id = 1;
		else if (d == pre + 1) id++;
		else if (d != pre) {
			id += 2;
			r_val[id - 1] = pre + 1;
		}
		r_val[id] = d;
		if (d != pre) compress[d] = id;
		pre = d;
	}
	r_val[id + 1] = pre + 1;
	r_val[0] = -1;
	for (int i = 1; i <= n; ++i) {
		for (ii &j : adj[i]) {
			j.second = compress[j.second];
		}
	}
	euler.push_back(-1);
	calc(1, -1);
	// for (int i = 1; i <= 2 * n; ++i)
	// 	cerr << euler[i] << ' ';
	// cerr << endl;
	// for (int i = 1; i <= 2 * n; ++i)
	// 	cerr << E[euler[i]] << ' ';
	// cerr << endl;
	for (int i = 0; i <= n; ++i) exist[i] = 2;
	for (int i = 1; i <= q; ++i) {
		int u, v;
		cin >> u >> v;
		if (d[u] > d[v]) swap(u, v);
		Q[i] = {u, v};
		int d = LCA(u, v);
		if (d == u) {
			// cerr << tout[v] << ' ' << tout[u] - 1 << endl;
			QList.push_back({tout[v], tout[u] - 1, i, 1});
			continue;
		}
		if (tout[u] < tin[v]) {
			// cerr << tout[u] << ' ' << tin[v] << endl;
			QList.push_back({tout[u], tin[v], i, 1});
		} else {
			// cerr << tout[v] << ' ' << tin[u] << endl;
			QList.push_back({tout[v], tin[u], i, 1});
		}
		// cerr << "Query id : " << i << ",   " << d << " to " << u << " in range " << tin[d] + 1 << " -> " << tin[u] << endl;
	}
	blockSize = sqrt(2 * n);
	solve();
	for (int i = 1; i <= q; ++i)
		cout << r_val[ans[i]] << endl;

	return 0;
}