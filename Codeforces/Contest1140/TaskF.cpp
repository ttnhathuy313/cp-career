#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 3e5 + 5;
int q, ans[N], lst[N], tq;
vector <pair <int, int>> st[4 * N];

int Left(int id) {
	return (id << 1);
}

int Right(int id) {
	return (id << 1) + 1;
}

void add(int id, int L, int R, int i, int j, pair <int, int> x) {
	if (L > j || R < i) return;
	if (L >= i && R <= j) {
		st[id].push_back(x);
		return;
	}
	int mid = (L + R) >> 1;
	add(Left(id), L, mid, i, j, x);
	add(Right(id), mid + 1, R, i, j, x);
}

struct dsu {
	struct obj {
		int type, x, y;
	};

	stack<obj> rollBack;
	int ans, n;
	vector <int> lab, sz, coef;
	dsu() {}
	dsu(int _n) {
		ans = 0;
		this -> n = _n;
		lab.assign(n + 5, -1);
		sz.assign(n + 5, 1);
		coef.assign(n + 5, 0);
	}

	int root(int x) {
		return (lab[x] == -1 ? x : root(lab[x]));
	}

	void setRoot(int x) {
		int rx = root(x);
		coef[rx]++;
		ans += sz[rx];
		rollBack.push({3, rx, -1});
		return;
	}

	void merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) {
			rollBack.push({2, x, y});
			return;
		} else {
			if (sz[x] < sz[y]) {
				swap(x, y);
			}
			lab[y] = x;
			ans -= coef[x] * sz[x];
			ans -= coef[y] * sz[y];
			coef[x] += coef[y];
			sz[x] += sz[y];
			ans += coef[x] * sz[x];
			rollBack.push({1, x, y});
		}
	}

	void roll(int times) {
		while (times--) {
			obj infor = rollBack.top();
			rollBack.pop();
			if (infor.type == 2) continue;
			if (infor.type == 3) {
				coef[infor.x]--;
				ans -= sz[infor.x];
			}
			if (infor.type == 1) {
				int x = infor.x, y = infor.y;
				ans -= coef[x] * sz[x];
				sz[x] -= sz[y];
				coef[x] -= coef[y];
				ans += coef[x] * sz[x];
				ans += coef[y] * sz[y];
				lab[y] = -1;
			}
		}
	}
} solver;

void dfs(int id, int L, int R) {
	vector <pair <int, int>> rb;
	rb.clear();
	for (pair <int, int> xx : st[id]) {
		int x = xx.first, y = xx.second;

		if (lst[x] == -1) {
			solver.setRoot(y); // ++
		} else {
			solver.merge(lst[x], y);
		}

		rb.push_back({x, lst[x]});
		lst[x] = y;
	}
	reverse(rb.begin(), rb.end());
	int pre = solver.ans, vv = solver.rollBack.size();
	if (L == R) {
		ans[L] = solver.ans;
		solver.roll((int)st[id].size());
		for (pair<int, int> v : rb) {
			lst[v.first] = v.second;
		}
		return;
	}

	int mid = (L + R) >> 1;
	dfs(Left(id), L, mid);
	dfs(Right(id), mid + 1, R);
	solver.roll((int)st[id].size());
	for (pair<int, int> v : rb) {
		lst[v.first] = v.second;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	solver = dsu(N);
	// solver.setRoot(1);
	// solver.merge(1, 2);
	// solver.merge(2, 3);
	// solver.setRoot(3);
	// solver.setRoot(1);

	// cerr << solver.ans << endl;

	map <pair <int, int>, int> start;
	start.clear();
	cin >> q;
	tq = q;
	for (int i = 1; i <= tq; ++i) {
		int x, y;
		cin >> x >> y;
		if (start.find({x, y}) != start.end()) {
			add(1, 1, q, start[{x, y}], i - 1, pair <int, int> (x, y));
			start.erase({x, y});
		} else {
			start[{x, y}] = i;
		}
	}	
	for (auto d : start) {
		add(1, 1, q, d.second, q, d.first);
	}
	memset(lst, -1, sizeof lst);
	dfs(1, 1, q);
	for (int i = 1; i <= tq; ++i) {
		cout << ans[i] << ' ';
	}

	return 0;
}