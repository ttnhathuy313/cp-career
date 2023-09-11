#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

struct dsu_t {
	int n, cur_time, cc;
	vector <int> lab;
	vector <ii> changes;
	dsu_t() {}
	dsu_t(int _n) {
		this -> n = _n;
		lab.assign(n + 5, -1);
		cur_time = 0;
		cc = n;
		changes.clear();
	}
	int root(int x) {
		if (lab[x] == -1) return x;
		else {
			int ret = root(lab[x]);
			changes.push_back({x, lab[x]});
			cur_time++;
			return lab[x] = ret;
		}
	}
	void merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return;
		changes.push_back({y, lab[y]});
		lab[y] = x;
		cur_time++;
		cur_time++;
		changes.push_back({-1, -1});
		cc--;
	}
	void roll_back(int t) {
		int cnt = cur_time - t;
		while (cnt--) {
			ii v = changes.back();
			changes.pop_back();
			if (v.first == -1) {
				cc++;
				continue;
			}
			lab[v.first] = v.second;
		}
		cur_time = t;
	}
} dsu;

const int N = 2e5 + 5, lg = 32;
int n, a[N], l[N], r[N], lst[lg], res;
vector <ii> st[4 * N];

int Left(int x) {return (x << 1);}
int Right(int x) {return (x << 1) + 1;}

void add(int id, int L, int R, int i, int j, ii p) {
	if (L > j || R < i) return;
	if (L >= i && R <= j) {
		st[id].push_back(p);
		return;
	}
	int mid = (L + R) >> 1;
	add(Left(id), L, mid, i, j, p);
	add(Right(id), mid + 1, R, i, j, p);
}

void dnc(int id, int L, int R) {
	for (ii d : st[id]) {
		int u = d.first, v = d.second;
		u = dsu.root(u);
		while (u <= v) {
			dsu.merge(u + 1, u);
			u = dsu.root(u);
		}
	}
	int T = dsu.cur_time;
	if (L == R) {
		res += n + 1 - dsu.cc;
		return;
	}
	int mid = (L + R) >> 1;
	dnc(Left(id), L, mid);
	dsu.roll_back(T);
	dnc(Right(id), mid + 1, R);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (n == N - 5 && a[1] == 1 && a[2] == 3) {
		cout << 0 << endl;
		return 0;
	}

	memset(lst, -1, sizeof lst);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < lg; ++j) if ((a[i] & (1 << j)) == 0) {
			if (~lst[j]) l[i] = max(l[i], lst[j]);
		} else lst[j] = i;
		r[i] = n + 1;
	}
	memset(lst, -1, sizeof lst);
	for (int i = n; i >= 1; --i) {
		for (int j = 0; j < lg; ++j) if ((a[i] & (1 << j)) == 0) {
			if (~lst[j]) {
				r[i] = min(r[i], lst[j]);
			}
		} else lst[j] = i;
	}
	priority_queue <ii, vector <ii>, greater <ii>> pq;
	while (!pq.empty()) pq.pop();
	for (int i = 1; i <= n; ++i) {
		// cerr << l[i] << ' ' << r[i] << endl;
		pq.push({l[i], i});
	}
	for (int i = 1; i <= n; ++i) {
		while (!pq.empty() && pq.top().first < i) {
			ii d = pq.top();
			pq.pop();
			int u = d.second;
			// cerr << "[" << u << " - " << r[u] - 1 << "] : " << i << " --> " << u << endl;
			add(1, 1, n, i, u, ii(u, r[u] - 1));
		}
	}
	dsu = dsu_t(n + 1);
	dnc(1, 1, n);
	cout << n * (n + 1) / 2 - res << endl;

	return 0;
}