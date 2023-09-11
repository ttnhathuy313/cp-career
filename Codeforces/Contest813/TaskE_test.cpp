#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
struct dsu_t { // add an edge to a new graph, the bipartiteness is stored in isBipartite
	int n, isBipartite, nVersion;
	stack <pair <int, int>> roll_back;
	vector <int> lab, Rank, parity;
	dsu_t() {}
	dsu_t(int _n) {
		this -> n = _n;
		isBipartite = true;
		nVersion = 0;
		lab.assign(n + 5, -1);
		Rank.assign(n + 5, 0);
		parity.assign(n + 5, 0);
		while (!roll_back.empty())
			roll_back.pop();
	}
	pair<int, int> root(int x) {
		if(lab[x] == -1)
			return {x, parity[x]};
		pair<int, int> p = root(lab[x]);
		p.second ^= parity[x];
		return p;
	}
	void merge(int u, int v) {
		pair <int, int> px = root(u), py = root(v);
		int rx = px.first, vx = px.second, ry = py.first, vy = py.second;
		if (rx == ry) {
			if (vx == vy) {
				roll_back.push(pair <int, int>(0, isBipartite));
				nVersion++;
				isBipartite = false;
			}
			return;
		}
		if (Rank[rx] > Rank[ry]) {
			swap(rx, ry);
			swap(vx, vy);
		}
		lab[rx] = ry;
		roll_back.push(pair <int, int>(3, rx + (parity[rx]) * n));
		roll_back.push(pair <int, int>(1, rx));
		nVersion += 2;
		parity[rx] = vx ^ vy ^ 1;
		if (Rank[rx] == Rank[ry]) roll_back.push(pair <int, int>(2, ry));
		nVersion += Rank[rx] == Rank[ry];
		Rank[ry] += (Rank[rx] == Rank[ry]);
	}
	void roll_to(int version) {
		while (nVersion != version) {
			pair <int, int> item = roll_back.top();
			roll_back.pop(); nVersion--;
			if (item.first == 0) {
				isBipartite = item.second;
			} else if (item.first == 1) {
				lab[item.second] = -1;
			} else if (item.first == 2) {
				Rank[item.second]--;
			} else if (item.first == 3) {
				if (item.second > n) {
					parity[item.second - n] = 1;
				} else parity[item.second] = 0;
			}
		}
	}
} dsu;
 
typedef pair <int, int> ii;
 
const int N = 1e5 + 5;
int n, q, res[N];
vector <ii> st[4 * N];
 
int Left(int x) {
	return (x << 1);
}
 
int Right(int x) {
	return (x << 1) + 1;
}
 
void add(int id, int L, int R, int i, int j, ii e) {
	if (i > R || j < L) return;
	if (L >= i && R <= j) {
		st[id].push_back(e);
		return;
	}
	int mid = (L + R) >> 1;
	add(Left(id), L, mid, i, j, e);
	add(Right(id), mid + 1, R, i, j, e);
}
 
void dnc(int id, int L, int R) {
	int version_kept = dsu.nVersion;
	if (dsu.isBipartite == 1) for (ii e : st[id]) {
		dsu.merge(e.first, e.second);
	}
	if (L == R) {
		res[L] = dsu.isBipartite;
		dsu.roll_to(version_kept);
		return;
	}
	int mid = (L + R) >> 1;
	dnc(Left(id), L, mid);
	dnc(Right(id), mid + 1, R);
	dsu.roll_to(version_kept);
}
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
 	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	map <ii, int> lst;
	lst.clear();
	cin >> n >> q;
	dsu = dsu_t(n);
 
	for (int i = 1; i <= q; ++i) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		map <ii, int>::iterator it = lst.find(ii(u, v));
		if (it == lst.end()) {
			lst[{u, v}] = i;
		} else {
			add(1, 1, q, (*it).second, i - 1, ii(u, v));
			lst.erase(it);
		}
	}
	for (auto d : lst) {
		add(1, 1, q, d.second, q, d.first);
	}
 
	dnc(1, 1, q);
 
	for (int i = 1; i <= q; ++i) {
		if (res[i]) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;
	}
 
	return 0;
}